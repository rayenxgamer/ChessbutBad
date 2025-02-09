#pragma once

#include <cglm/cglm.h>
#include <utils/shader/shader.h>
#include <utils/texture/texture.h>

#include "../VAO.h"
#include "../VBO.h"
#include "../EBO.h"


void Renderer_FillRect(float x,float y,float height, float width, struct Texture self,struct Shader shader,
                       unsigned int VAO, unsigned int VBO, unsigned int EBO);
