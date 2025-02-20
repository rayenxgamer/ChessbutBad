#include "board.h"
#include "utils/terriblerenderer/renderer.h"
#include "utils/texture/texture.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void Board_Draw(struct Shader shader, char board[8][8],unsigned int VAO,unsigned int VBO,unsigned int EBO){
  // should be able to just draw them using a list? but now i have
  // to think of how to make up the list
  struct piece* piece = malloc(sizeof(struct piece));

  object* head = NULL;
  object* temp;

  // bind the background texture
  struct Texture bg = T_LoadTextureFromFile(bg, "../assets/chess.png", false); T_Bind(bg);
  Renderer_FillBackground(480, 640, shader, bg, VAO, VBO,  EBO);
  // create the texture atlas
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

  #define GLOBAL_PIECE_SIZE 50

  // not proud of this many defines, should be in a const var but it sounded cool to have it as a macro

   T_Bind(atlas);

  BindShader(shader);

  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
        piece->x = 40 + (j * 80); // 40 px offset from window then 80px every move
        piece->y = 460 - ((i*60)); // 20 px offset from window then 60px every move

      // check every single board space for a letter then draw a rectangle with a texture there to represent the piece
      switch (board[i][j]) {
        case 'R':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_ROOK;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'N':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_KNIGHT;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'B':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_BISHOP;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'K':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_KING;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'Q':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_QUEEN;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'P':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_WHITE_PAWN;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'S':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_ROOK;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'O':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_KNIGHT;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'C':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_BISHOP;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'U':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_KING;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'T':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_QUEEN;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
        case 'M':
          piece->type = 'R';
          piece->selected = false;
          piece->texture = TEXTURE_BLACK_PAWN;
          Renderer_FillRect(GLOBAL_PIECE_SIZE, GLOBAL_PIECE_SIZE, shader, piece, VAO, VBO, EBO);
          temp = insert(piece);
          temp ->next = head;
          head = temp;
          break;
      }
    }
  }
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

bool Board_CheckForPieceClicked(double m_xpos,double m_ypos, char board[8][8], uint* clickcounter, vec2 firstclickcoords){
    double xpos =floor((m_xpos / 80));
    double ypos =floor((m_ypos / 60));

  if (*clickcounter == 1) {
      switch (board[(int)ypos][(int)xpos]) {
        case '0':
        printf("nothing here\n");
        // does nothing if your first board click was on 0 aka empty space
        return false;
        break;
        default:
        // get the coordinates of this click so it can be used to store stuff like
        // well, the position and piece charachter
        firstclickcoords[0] = xpos;
        firstclickcoords[1] = ypos;
        return true;
      }
    *clickcounter = *clickcounter+1;
  }else{
    if (firstclickcoords[1] == ypos && firstclickcoords[0] == xpos) {
      return true;
    }else{
      char pieceToBeMoved = board[(int)firstclickcoords[1]][(int)firstclickcoords[0]];
      board[(int)firstclickcoords[1]][(int)firstclickcoords[0]] = '0';
      board[(int)ypos][(int)xpos] = pieceToBeMoved;
    }
  }
  return true;
};
