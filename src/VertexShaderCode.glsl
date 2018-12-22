#version 430

layout (location = 0) in vec2 position;
layout (location = 1) in vec3 color;

out vec3 the_color;

void main()
{
   gl_Position = vec4(position, 0.0, 1.0);
   the_color = color;
}