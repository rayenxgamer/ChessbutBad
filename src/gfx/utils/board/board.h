#pragma once

#include <stdbool.h>
#include "utils/shader/shader.h"
#include "utils/texture/texture.h"


struct piece{
  bool selected;
  float x;
  float y;
  char type;
  struct Texture texture;
};

struct Node{
  struct piece* piece;
  struct Node* next;
};

typedef struct Node object;

void Board_Draw(struct Shader shader, const char* board[8],unsigned int VAO,unsigned int VBO,unsigned int EBO);

void printboard(const char* board[8]);

void DefaultPiece(struct piece* self);

static object* insert(struct piece* value);

void Board_CheckForPieceClicked(double m_xpos,double m_ypos);
