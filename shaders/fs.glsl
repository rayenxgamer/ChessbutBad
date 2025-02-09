#version 330 core
out vec4 fragcolor;

in vec2 Tex;

uniform sampler2D Texture;

void main(){
    fragcolor = vec4(1.0,1.0 ,1.0 ,1.0);
}
