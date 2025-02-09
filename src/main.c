#include <utils/texture/texture.h>
#include <utils/shader/shader.h>
#include <utils/window/window.h>
#include <utils/camera/camera.h>
#include <utils/terriblerenderer/renderer.h>
#include "GLFW/glfw3.h"
#include "utils/LOG.h"
#include "utils/VAO.h"

bool running = true;

mat4 projection;
mat4 view;

struct Camera camera;

void key_callback(GLFWwindow* window, int key, int scancode, int action , int mods );

int main(){
    GLFWwindow* window;
    init_window(&window, 480, 640, "CChess");

    glfwSetKeyCallback(window, key_callback);

    struct VertexAttr attributes[] = {
        {0, "position"},
        {1, "texture"},
    };

    struct Shader shader = CreateShader(
        "../shaders/common/vs.glsl",
        "../shaders/common/fs.glsl",
        2,
        attributes
    );


    camera = C_CreateCamera(camera, (vec2){0.0,0.0});
    C_GetProjMatrix(camera, 480, 640, projection);
    C_GetViewMatrix(camera, view);

    u32 VAO = CreateVAO(VAO);
    u32 VBO = CreateVAO(VBO);
    u32 EBO = CreateVAO(EBO);

    // load a chess background
    struct Texture chess_bg = T_LoadTextureFromFile(chess_bg, "../assets/bg.jpg", false);

    T_Bind(chess_bg);

    BindVAO(VAO);
    BindVBO(VBO);
    BindEBO(EBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    while (running) {
        Clear_window(1.0, 0.9, 0.1, 1.0);
        ShouldCloseCheck(&window, &running);
        BindShader(shader);

        Shader_SetMat4(shader, "projection", projection);
        Shader_SetMat4(shader, "view", view);

        BindVAO(VAO);

        Renderer_FillRect(320,240, 480, 640, chess_bg, shader, VAO, VBO,EBO);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    Shutdown_window(&window);
    return 0;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action , int mods ){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        running = false;
    }
}
