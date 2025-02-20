#include <stdio.h>
#include <utils/texture/texture.h>
#include <utils/shader/shader.h>
#include <utils/window/window.h>
#include <utils/camera/camera.h>
#include <utils/terriblerenderer/renderer.h>
#include <utils/board/board.h>
#include "GLFW/glfw3.h"
#include "utils/VAO.h"

// TODO'S (in comments)
// detect turns
// windows build support
// app icon
// commenting the code in main.c
// detect piece paths
// detect a check
// detect a mate
// castle
// a battle pass and world domination

// constants
#define HEIGHT 480
#define WIDTH 640

// variables
double m_xpos;
double m_ypos;

uint clickcounter = 0;
vec2 firstclickcounter;

bool running = true;

mat4 projection;
mat4 view;

struct Camera camera;

char board[8][8] = { "SOCTUCOS",
                         "MMMMMMMM",
                         "00000000",
                         "00000000",
                         "00000000",
                         "00000000",
                         "PPPPPPPP",
                         "RNBQKBNR"};

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

int main(){
    GLFWwindow* window;
    init_window(&window, HEIGHT, WIDTH, "CChess");

    glfwSetKeyCallback(window, key_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetMouseButtonCallback(window,mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    struct VertexAttr attributes[] = {
        {0, "position"},
        {1, "texture"},
   };

    unsigned int VAO = CreateVAO(VAO);
    unsigned int VBO = CreateVBO(VBO);
    unsigned int EBO = CreateEBO(EBO);

    BindVAO(VAO);
    BindVBO(VBO);
    BindEBO(EBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    struct Shader shader = CreateShader(

        "../shaders/common/vs.glsl",
        "../shaders/common/fs.glsl",
        2,
        attributes
    );


    camera = C_CreateCamera(camera, (vec2){0.0,0.0});
    C_GetProjMatrix(camera, HEIGHT, WIDTH, projection);
    C_GetViewMatrix(camera, view);

    while (running) {
      Clear_window(1.0, 0.9, 0.1, 1.0);
      ShouldCloseCheck(&window, &running);
      BindShader(shader);

      Shader_SetMat4(shader, "projection", projection);
      Shader_SetMat4(shader, "view", view);
      // chess board
      // grid is 40 offset from left X of the window and 80 per pawn rect
      // 60 per Y looks good
      Board_Draw(shader,board,VAO,VBO,EBO);
      glfwPollEvents();
      glfwSwapBuffers(window);
    }

    Shutdown_window(&window);
    return 0;
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
      running = false;
  };
};
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
    clickcounter++;
    switch (clickcounter) {
      case 1:
      if (!Board_CheckForPieceClicked(m_xpos,m_ypos,board,&clickcounter,firstclickcounter))
      {
        clickcounter = 0;
      }
      break;
      case 2:
        Board_CheckForPieceClicked(m_xpos, m_ypos, board, &clickcounter, firstclickcounter);
      clickcounter = 0;
      break;
    }
  };
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    board[0][1] = 'C';
  }
}
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    glfwGetCursorPos(window, &xpos,&ypos);
    m_xpos = xpos;
    m_ypos = ypos;
};
