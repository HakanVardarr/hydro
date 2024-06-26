#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H

#include "glad/glad.h"
// ------------------
#include "GLFW/glfw3.h"

class IndexBuffer {
   public:
    IndexBuffer(const int *indices, GLuint size);
    ~IndexBuffer();

    GLsizei Size() { return m_size; }

    void Bind() const;
    void Unbind() const;

   private:
    GLuint m_id;
    GLsizei m_size;
};

#endif