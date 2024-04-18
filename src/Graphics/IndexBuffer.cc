#include "Graphics/IndexBuffer.h"

namespace Hydro {

IndexBuffer::IndexBuffer(const int *indices, GLuint size) : m_size(size) {
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &m_id); }

void IndexBuffer::Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id); }

void IndexBuffer::Unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

}  // namespace Hydro