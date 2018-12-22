//
// Created by penglei on 18-12-21.
//
#include <GL/glew.h>
#include "GLWindow.h"

extern const char *vertex_shader_code;
extern const char *fragment_shader_code;

void installShaders() {
    GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

    const char *adapter[1];
    adapter[0] = vertex_shader_code;
    glShaderSource(vertex_shader_id, 1, adapter, 0);
    adapter[0] = fragment_shader_code;
    glShaderSource(fragment_shader_id, 1, adapter, 0);

    glCompileShader(vertex_shader_id);
    glCompileShader(fragment_shader_id);

    GLuint program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);
    glLinkProgram(program_id);

    glUseProgram(program_id);
}

void GLWindow::initializeGL() {
    glewInit();

    GLfloat verts[] {
        +0.0f, +0.0f,
        +1.0f, +0.0f, +0.0f,
        +1.0f, +1.0f,
        +1.0f, +0.0f, +0.0f,
        -1.0f, +1.0f,
        +1.0f, +0.0f, +0.0f,
        -1.0f, -1.0f,
        +1.0f, +0.0f, +0.0f,
        +1.0f, -1.0f,
        +1.0f, +0.0f, +0.0f,
    };

    // 创建一个 buffer object
    GLuint vertex_buffer_id;
    glGenBuffers(1, &vertex_buffer_id);

    // 将 buffer object 暂时绑定到 OpenGL Context
    // 因为只有这样才能修改和使用 object
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);

    // 将 CPU 中的数据传给 GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
            verts, GL_STATIC_DRAW);

    // 当完成 buffer object 的赋值后，解绑，等需要的时候再绑定
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*5, 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float)*5,
            (char*)(sizeof(float)*2));

    // 用顶点索引缓冲对象
    GLushort indices[] = {
            0, 1, 2,
            0, 3, 4,
    };

    GLuint index_buffer_id;
    glGenBuffers(1, &index_buffer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
            indices, GL_STATIC_DRAW);

    installShaders();
}

void GLWindow::paintGL() {
    glViewport(0, 0, width(), height());

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);

}
