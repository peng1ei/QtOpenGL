//
// Created by penglei on 18-12-22.
//

const char *vertex_shader_code = {
        "#version 430\r\n"
        ""
        "layout (location = 0) in vec2 position;"
        "layout (location = 1) in vec3 color;"
        ""
        "out vec3 the_color;"
        ""
        "void main()"
        "{"
        "   gl_Position = vec4(position, 0.0, 1.0);"
        "   the_color = color;"
        "}"
};

const char *fragment_shader_code = {
        "#version 430\r\n"
        ""
        "in vec3 the_color;"
        "out vec4 data_color;"
        ""
        "void main()"
        "{"
        "   data_color = vec4(the_color, 1.0);"
        ""
        "}"
};








