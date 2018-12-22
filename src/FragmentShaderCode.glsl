#version 430

in vec3 the_color;
out vec4 data_color;

void main()
{
   data_color = vec4(the_color, 1.0);
}