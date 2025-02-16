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
  Renderer_FillBackground(640, 640, shader, bg, VAO, VBO,  EBO);
  struct Texture atlas = T_LoadTextureFromFile(atlas, "../assets/rooks/white_rook.png", false);
  T_Bind(atlas);

  BindShader(shader);

  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      piece->x = 40 + (j * 80);
      piece->y = 480 - (25 + (i * 60));
      switch (board[i][j]) {
        case 'R':
          printf("rook spawned!\n");
          printf("the X is: %f\t the Y is %f\n",piece->y,piece->x);
          printf("the j is: %d\t the i is %d\n",j,i);
          piece->type = 'R';
          piece->selected = false;
          piece->texture = atlas;
          Renderer_FillRect(60, 60, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'N':
          printf("knight spawned\n");
          break;
        case 'B':
          printf("bishop spawned\n");
          break;
        case 'K':
          printf("King spawned!\n");
          break;
        case 'Q':
          printf("Queen spawned!\n");
          break;
        case 'P':
          printf("spawned pawn\n");
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
