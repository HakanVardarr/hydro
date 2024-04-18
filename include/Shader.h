#ifndef _SHADER_H
#define _SHADER_H

#include <fstream>
#include <string>
#include <tuple>

#include "glad/glad.h"
// ------------------
#include "GLFW/glfw3.h"

#define VERTEX 0
#define FRAGMENT 1

#define SHADER 0
#define PROGRAM 1

class Shader {
   public:
    Shader(const std::string filePath, const std::string name);
    ~Shader(){};

    void Use() const { glUseProgram(m_program); }

    void SetBool(const std::string &name, bool value) const {
        glUniform1i(glGetUniformLocation(m_program, name.c_str()), (int)value);
    }
    void SetInt(const std::string &name, int value) const {
        glUniform1i(glGetUniformLocation(m_program, name.c_str()), value);
    }
    void SetFloat(const std::string &name, float value) const {
        glUniform1f(glGetUniformLocation(m_program, name.c_str()), (int)value);
    }

   private:
    GLuint m_program;
    std::string m_name;

    GLuint compileShader(std::string shaderSource, int shaderType);
    void linkProgram(GLuint vertex, GLuint fragment);
    void checkCompileErrors(GLuint id, int type);
    std::tuple<std::string, std::string> *readShader(std::string filePath);
};

#endif