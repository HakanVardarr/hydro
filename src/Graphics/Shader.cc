#include "Graphics/Shader.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "spdlog/spdlog.h"

#define VERTEX 0
#define FRAGMENT 1

#define SHADER 0
#define PROGRAM 1

#define RETURNSHADER(type, source)                   \
    GLuint shader_##type = glCreateShader(type);     \
    glShaderSource(shader_##type, 1, &source, NULL); \
    glCompileShader(shader_##type);                  \
    return shader_##type;

#define COMPILESHADER(type, shader_type)                    \
    GLuint type = compileShader(source##type, shader_type); \
    checkCompileErrors(type, SHADER);

namespace Hydro {

Shader::Shader(const std::string filePath, const std::string name) {
    auto startTimer = std::chrono::high_resolution_clock::now();
    std::tuple<std::string, std::string>* shaders = readShader(filePath);
    if (shaders == nullptr) {
        throw std::runtime_error("Cannot read the file: " + filePath);
    }

    std::string sourcevertex = std::get<0>(*shaders);
    std::string sourcefragment = std::get<1>(*shaders);

    COMPILESHADER(vertex, VERTEX);
    COMPILESHADER(fragment, FRAGMENT);

    linkProgram(vertex, fragment);
    checkCompileErrors(m_program, PROGRAM);

    auto endTimer = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        endTimer - startTimer);

    spdlog::debug("{} shader compiled in {}μs.", name, duration.count());

    delete shaders;
}

Shader::~Shader() { glDeleteProgram(m_program); }

GLuint Shader::compileShader(std::string shaderSource, int shaderType) {
    const GLchar* source = shaderSource.c_str();
    if (shaderType == VERTEX) {
        RETURNSHADER(GL_VERTEX_SHADER, source);
    }
    RETURNSHADER(GL_FRAGMENT_SHADER, source);
}

void Shader::linkProgram(GLuint vertex, GLuint fragment) {
    m_program = glCreateProgram();

    glAttachShader(m_program, vertex);
    glAttachShader(m_program, fragment);
    glLinkProgram(m_program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::checkCompileErrors(GLuint id, int type) {
    int success;
    char infoLog[1024];
    if (type != PROGRAM) {
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(id, 1024, NULL, infoLog);
            throw std::runtime_error("SHADER_LINKING_ERROR: " +
                                     std::string(infoLog));
        }
    } else {
        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(id, 1024, NULL, infoLog);
            throw std::runtime_error("PROGRAM_LINKING_ERROR: " +
                                     std::string(infoLog));
        }
    }
}

std::tuple<std::string, std::string>* Shader::readShader(
    const std::string filePath) {
    std::stringstream vertexSource, fragmentSource;
    std::ifstream shaderFile(".." + filePath);

    if (shaderFile.is_open()) {
        std::string line;
        while (getline(shaderFile, line) && line != "//Fragment") {
            if (line != "//Vertex") {
                vertexSource << line << "\n";
            }
        }
        while (getline(shaderFile, line)) {
            fragmentSource << line << "\n";
        }

        shaderFile.close();

        return new std::tuple<std::string, std::string>(vertexSource.str(),
                                                        fragmentSource.str());
    } else {
        return nullptr;
    }
}
}  // namespace Hydro