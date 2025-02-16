cmake_minimum_required(VERSION 3.27)
project(ChessbutBad)

set(CMAKE_C_STANDARD)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(ChessbutBad
   src/main.c
   src/glad.c
   lib/stb_image/stb_image.c
   src/gfx/utils/window/window.c
   src/gfx/utils/texture/texture.c
   src/gfx/utils/shader/shader.c
   src/gfx/utils/camera/camera.c
   src/gfx/utils/board/board.c
   src/gfx/utils/terriblerenderer/renderer.c
   src/gfx/utils/VAO.c
   src/gfx/utils/VBO.c
   src/gfx/utils/EBO.c
)


target_include_directories(ChessbutBad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx
)


target_link_directories(ChessbutBad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/libglfw3.a)

target_link_libraries(ChessbutBad PRIVATE
    glfw
    m
    dl
    pthread
)

# RAE WUZ HERZ!1
# pls gib goth gf i be
