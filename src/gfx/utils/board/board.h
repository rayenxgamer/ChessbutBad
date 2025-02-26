#pragma once

#include <stdbool.h>
#include "utils/shader/shader.h"
#include "utils/texture/texture.h"

// piece list
struct Node{
  struct piece* piece;
  struct Node* next;
};

typedef struct Node object;
// move list
struct Node1{

};

struct piece{
  bool selected;
  float x;
  float y;
  char type;
  struct Texture texture;
};



// a function..to draw the board? im getting good at the whole "the code explains itself" thing
void Board_Draw(struct Shader shader,const char board[8][8],unsigned int VAO,unsigned int VBO,unsigned int EBO);

// deprecated, in other words, i deleted it from the c file and its still here for no reason
void printboard(const char* board[8]);

// sets default piece struct values
void DefaultPiece(struct piece* self);

// list insert function
static object* insert(struct piece* value);

// the whole piece moving thing, obviously not needed and useless id rather
bool Board_CheckForPieceClicked(double m_xpos,double m_ypos, char board[8][8], uint* clickcounter, vec2 firstclickcoords);


static bool Board_CheckRookMove(double x, double y, double fx, double fy, const char board[8][8], bool isWhite);
static bool Board_CheckKnightMove(double x, double y, double fx, double fy, const char board[8][8], bool isWhite);
static bool Board_CheckPawnMove(double x, double y, double fx, double fy,const char board[8][8], bool isWhite);

bool Board_ValidMove(double x, double y,double fx, double fy, char board[8][8]);
