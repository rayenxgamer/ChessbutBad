#include "board.h"
#include "utils/terriblerenderer/renderer.h"
#include "utils/texture/texture.h"
#include <stdio.h>
#include <stdlib.h>

void Board_Draw(struct Shader shader, const char* board[8],unsigned int VAO,unsigned int VBO,unsigned int EBO){
  // should be able to just draw them using a list? but now i have
  // to think of how to make up the list
  static struct piece piece;

  object* head = NULL;
  object* temp;

  struct Texture Rook = T_LoadTextureFromFile(Rook, "../assets/pawns/black_pawn.png", false);
  T_Bind(Rook);

  BindShader(shader);

  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      switch (board[i][j]) {
        case 'R':
          printf("rook spawned!\n");
          piece.x = (j * 80) + 40;
          piece.y = (i*100) + 50;
          piece.y = 800 - piece.y;
          printf("the X is: %f\t the Y is %f\n",piece.y,piece.x);
          printf("the j is: %d\t the i is %d\n",j,i);
          piece.type = 'R';
          piece.selected = false;
          piece.texture = Rook;
          temp = insert(&piece);
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
  int count = 1;
  while (current != NULL) {
    printf("itterated over %d pieces\n",count);
    Renderer_FillRect(60, 60, shader, current->piece, VAO, VBO, EBO);
    current = current ->next;
    count ++;
  }
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
