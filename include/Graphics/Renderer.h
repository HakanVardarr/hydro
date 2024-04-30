#ifndef _RENDERER_H
#define _RENDERER_H

#include "Graphics/IndexBuffer.h"
#include "Graphics/Shader.h"
#include "Graphics/VertexArray.h"

class Renderer {
   public:
    static void Draw(Shader shader, VertexArray vao, IndexBuffer ibo);

   private:
};

#endif