#ifndef _SHADER_H
#define _SHADER_H

#include <fstream>
#include <string>
#include <tuple>

#include "glad/glad.h"
// ------------------
#include "GLFW/glfw3.h"

class Shader {
   public:
    Shader(const std::string filePath);
    ~Shader();

    void Use() const { glUseProgram(m_program); }
    void SetBool(const std::string &name, bool value) const;
    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;

   private:
    GLuint m_program;
    std::string m_name;

    GLuint compileShader(std::string shaderSource, int shaderType);
    void linkProgram(GLuint vertex, GLuint fragment);
    void checkCompileErrors(GLuint id, int type);
    std::tuple<std::string, std::string> *readShader(std::string filePath);
};

#endif