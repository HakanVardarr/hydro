#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include "glad/glad.h"
// ------------------
#include "GLFW/glfw3.h"

namespace Hydro {

class VertexBuffer {
   public:
    VertexBuffer(const float* verticies, GLuint size);
    ~VertexBuffer();

    void Bind();
    void Unbind();

   private:
    GLuint m_id;
};

}  // namespace Hydro

#endif