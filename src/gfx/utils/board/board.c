#include "board.h"
#include "utils/terriblerenderer/renderer.h"
#include "utils/texture/texture.h"
#include <stdio.h>
#include <stdlib.h>

void Board_Draw(struct Shader shader, const char* board[8],unsigned int VAO,unsigned int VBO,unsigned int EBO){
  // should be able to just draw them using a list? but now i have
  // to think of how to make up the list
  struct piece* piece = malloc(sizeof(struct piece));

  object* head = NULL;
  object* temp;

  // bind the background texture
  struct Texture bg = T_LoadTextureFromFile(bg, "../assets/chess.png", false);
  T_Bind(bg);
  Renderer_FillBackground(480, 640, shader, bg, VAO, VBO,  EBO);
  struct Texture atlas = T_LoadTextureFromFile(atlas, "../assets/atlas.png", false);
  // chess constant atlases

  #define TEXTURE_BLACK_ROOK T_LoadAtlas(&atlas, 16, 5, 0);
  #define TEXTURE_BLACK_PAWN T_LoadAtlas(&atlas, 16, 8, 0);
  #define TEXTURE_BLACK_KNIGHT T_LoadAtlas(&atlas, 16, 6, 0);
  #define TEXTURE_BLACK_BISHOP T_LoadAtlas(&atlas, 16, 7, 0);
  #define TEXTURE_BLACK_QUEEN T_LoadAtlas(&atlas, 16, 9, 0);
  #define TEXTURE_BLACK_KING T_LoadAtlas(&atlas, 16, 1, 1);

  #define TEXTURE_WHITE_ROOK T_LoadAtlas(&atlas, 16, 0, 0);
  #define TEXTURE_WHITE_PAWN T_LoadAtlas(&atlas, 16, 3, 0);
  #define TEXTURE_WHITE_KNIGHT T_LoadAtlas(&atlas, 16, 1, 0);
  #define TEXTURE_WHITE_BISHOP T_LoadAtlas(&atlas, 16, 2, 0);
  #define TEXTURE_WHITE_QUEEN T_LoadAtlas(&atlas, 16, 4, 0);
  #define TEXTURE_WHITE_KING T_LoadAtlas(&atlas, 16, 0, 1);

 T_Bind(atlas);

  BindShader(shader);

  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
        piece->x = 40 + (j * 80);  // Offset by half the piece width (60/2)
        piece->y = 480 - (50+(i*70));
      switch (board[i][j]) {
        case 'R':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_ROOK;
          piece->y += 100;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'N':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_KNIGHT;
          piece->y += 100;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'B':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_BISHOP;
          piece->y += 100;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'K':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_KING;
          piece->y += 100;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'Q':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_QUEEN;
          piece->y += 100;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'P':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_PAWN;
          piece->y += 110;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'S':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_ROOK;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'O':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_KNIGHT;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'C':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_BISHOP;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'U':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_KING;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'T':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_QUEEN;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'M':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_PAWN;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
      }
    }
  }
  object* current = head;
}
void printboard(const char* board[8]){
  printf("%c\n",board[0][1]);
}

void DefaultPiece(struct piece* self){
  self->selected = false;
  self->x = 0;
  self->y = 0;
  self->type = 'p';
}

object* insert(struct piece* value){
    object* newnode = malloc(sizeof(struct Node));
    newnode->piece = value;
    newnode->next = NULL;

    return newnode;
};
