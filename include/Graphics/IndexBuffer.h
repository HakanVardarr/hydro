#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H

#include "glad/glad.h"
// ------------------
#include "GLFW/glfw3.h"

namespace Hydro {

class IndexBuffer {
   public:
    IndexBuffer(const int *indices, GLuint size);
    ~IndexBuffer();

    GLsizei Size() { return m_size; }

    void Bind();
    void Unbind();

   private:
    GLuint m_id;
    GLsizei m_size;
};

}  // namespace Hydro

#endif