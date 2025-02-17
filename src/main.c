#include <stdio.h>
#include <utils/texture/texture.h>
#include <utils/shader/shader.h>
#include <utils/window/window.h>
#include <utils/camera/camera.h>
#include <utils/terriblerenderer/renderer.h>
#include <utils/board/board.h>
#include "GLFW/glfw3.h"
#include "utils/VAO.h"

// constants
#define HEIGHT 480
#define WIDTH 640

// variables
bool running = true;

mat4 projection;
mat4 view;

struct Camera camera;

const char* board[8] = { "SOCTUCOS",
                         "MMMMMMMM",
                         "0M000000",
                         "00000000",
                         "00M000P0",
                         "0000000P",
                         "PPPPPPPP",
                         "RNBQKBNR"};

void key_callback(GLFWwindow* window, int key, int scancode, int action , int mods );
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
  glfwGetCursorPos(window, &xpos,&ypos);
  printf("%f\t%f\n",xpos,ypos);
}

int main(){
    GLFWwindow* window;
    init_window(&window, HEIGHT, WIDTH, "CChess");

    glfwSetKeyCallback(window, key_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
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


void key_callback(GLFWwindow* window, int key, int scancode, int action , int mods ){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        running = false;
    };
}

