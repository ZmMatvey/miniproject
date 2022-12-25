#version 330 core
out vec4 FragColor;

uniform mat4 Colors;

void main() 
{
	FragColor = vec4(Colors[0]);
}
