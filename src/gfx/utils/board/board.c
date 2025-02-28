#include "board.h"
#include "utils/terriblerenderer/renderer.h"
#include "utils/texture/texture.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void Board_Draw(struct Shader shader,const char board[8][8],
                unsigned int VAO,unsigned int VBO,unsigned int EBO){
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
  // make the clicked coords align witht the board size by deviding it by the offset
  // and flooring the value
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
    // check if the user clicks the exact same square again
    if (firstclickcoords[1] == ypos && firstclickcoords[0] == xpos) {
      return true;
    }
    // otherwise actually move the charachter
    else{
      if (Board_ValidMove(xpos, ypos,firstclickcoords[0],firstclickcoords[1], board)) {
        // get the charachter of the piece thats gonna be moved
        char pieceToBeMoved = board[(int)firstclickcoords[1]][(int)firstclickcoords[0]];
        // switch the spot where the piece is moving from to an empty space
        board[(int)firstclickcoords[1]][(int)firstclickcoords[0]] = '0';
        // set the mouse position to the piece to be moved's charachter
        board[(int)ypos][(int)xpos] = pieceToBeMoved;
      }
      else {
        printf("invalid move");
      return true;
      }
    }
  }
  // and actually exit the function
  return true;
};

static void Board_DetermineMaxMoves(const char board[8][8],double fx, double fy, int* upMaxLength, int* downMaxLength,
                                    int* rightMaxLength, int* leftMaxLength){
  // determine the max moves this piece can go up before hitting a piece
  // all lengths have to start at 1 to account for taking the piece and for
  // it to start properly counting
  while (board[(int)fy - *upMaxLength][(int)fx] == '0') {
    *upMaxLength += 1;
  }
  // down this time
  while (board[(int)fy + *downMaxLength][(int)fx] == '0') {
    *downMaxLength += 1;
  }
  // left
  while (board[(int)fy][(int)fx - *leftMaxLength] == '0') {
    *leftMaxLength += 1;
  }
  // and then right
  while (board[(int)fy][(int)fx + *rightMaxLength] == '0') {
    *rightMaxLength += 1;
  }
  printf("all determined");
}

static bool Board_CheckRookMove(double x, double y, double fx, double fy, const char board[8][8], bool isWhite){
  int upMaxLength = 1; int downMaxLength = 1; int rightMaxLength = 1; int leftMaxLength = 1;
  Board_DetermineMaxMoves(board,  fx,  fy,
                          &upMaxLength,  &downMaxLength,
                          &rightMaxLength,  &leftMaxLength);
  if (y > fy - upMaxLength - 1 && x == fx && y < fy) {
    return true;
  }
  if (y < fy + downMaxLength + 1 && x == fx && y > fy) {
    return true;
  }
  if (x > fx - rightMaxLength - 1 && y == fy && x < fx) {
    return true;
  }
  if (x < fx + rightMaxLength + 1 && y == fy && x > fx) {
    return true;
  }

  // logging, ignore
  printf("\nmax up len:| %d\n", upMaxLength);
  printf("\nmax down len:| %d\n", downMaxLength);
  printf("\nmax right len:| %d\n", rightMaxLength);
  printf("\nmax len:| %d\n", leftMaxLength);
  printf("\nfirstYclicke: %d\n",(int)fy);
  // * temporary * //
  return false;
}



static bool Board_CheckKnightMove(double x, double y, double fx, double fy, const char board[8][8], bool isWhite){
  if (y == fy-2.0f && (x == fx-1 || x == fx+1) || y == fy+2.0f && (x == fx +1 || x == fx-1)) {
    return true;
  }
  if (x == fx-2.0f && (y == fy+1 || y == fy-1) || x == fx + 2.0f && (y == fy + 1 || y == fy-1)) {
    return true;
  }

  //* temporary *//
  return false;
}

 static bool Board_CheckPawnMove(double x, double y, double fx, double fy,const char board[8][8], bool isWhite){
  // general movement checks : up, down, starting position moves, not being able to move up into
  // a piece that exists there
  if (x == fx && board[(int)y][(int)x] == '0') {
      if (isWhite ? (fy == 6 && y >= (fy - 2.0f) && y < fy && board[(int)fy-1][(int)fx] == '0') ||
          (y >= (fy - 1.0f) && y < fy) : (fy == 1 && y <= (fy + 2.0f) && y > fy && board[(int)fy+1][(int)fx] == '0') ||
          (y >= (fy + 1.0f) && y > fy) ) {
          return true;
        }
  }
  // diagonal capturing checks
    if (isWhite ? (y == fy-1 && (x == fx-1 || x == fx+1) && board[(int)y][(int)x] != '0')
  : (y == fy+1 && (x == fx+1 || x == fx-1) && board[(int)y][(int)x] != '0')) {
        return true;
    }
  return false;
}

bool Board_ValidMove(double x, double y,double fx, double fy, char board[8][8]){
  // the firstclickcoords is board array coordinates
  char selectedPieceChar = board[(int)fy][(int)fx];
  printf("\n%d\t%d\n",(int)x, (int)y);
  printf("\n%d\t%d\n",(int)fx, (int)fy);
  printf("%c\n",selectedPieceChar);
  bool canMove = false;
  switch (selectedPieceChar)
  {
    // pawns
    case 'P':
      canMove = Board_CheckPawnMove(x,  y,  fx,  fy,  board, true);
    break;
    case 'M':
      canMove = Board_CheckPawnMove(x,  y,  fx,  fy,  board, false);
    break;
    // knight
    case 'N':
     canMove = Board_CheckKnightMove(x, y, fx, fy, board, true);
    break;
    case 'O':
     canMove = Board_CheckKnightMove(x, y, fx, fy, board, true);
    break;
    case 'R':
     canMove = Board_CheckRookMove(x,  y,  fx,  fy,  board,  true);
  }
  return canMove;
}

