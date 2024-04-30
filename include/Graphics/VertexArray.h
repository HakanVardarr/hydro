#ifndef _VERTEX_ARRAY_H
#define _VERTEX_ARRAY_H
#include <vector>

#include "VertexBuffer.h"
#include "glad/glad.h"
// ------------------
#include "GLFW/glfw3.h"

class VertexArray {
   public:
    VertexArray(VertexBuffer &vertexBuffer,
                std::vector<unsigned int> attributes);
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

   private:
    GLuint m_id;
};
#endif