#include "Graphics/VertexBuffer.h"

namespace Hydro {

VertexBuffer::VertexBuffer(const float* verticies, GLuint size) {
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);

    glBufferData(GL_ARRAY_BUFFER, size, verticies, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &m_id); }

void VertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_id); }
void VertexBuffer::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

}  // namespace Hydro