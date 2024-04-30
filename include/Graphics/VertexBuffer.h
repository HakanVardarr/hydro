#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include "glad/glad.h"
// ------------------
#include "GLFW/glfw3.h"

class VertexBuffer {
   public:
    VertexBuffer(const float* verticies, GLuint size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

   private:
    GLuint m_id;
};

#endif