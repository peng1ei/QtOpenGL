//
// Created by penglei on 18-12-21.
//
#include <GL/glew.h>
#include "GLWindow.h"

void GLWindow::initializeGL() {
    glewInit();

    GLfloat verts[] {
        +0.0f, +1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
        +1.0f, -1.0f, 0.0f,
    };

    // 创建一个 buffer object
    GLuint my_buffer_id;
    glGenBuffers(1, &my_buffer_id);

    // 将 buffer object 暂时绑定到 OpenGL Context
    // 因为只有这样才能修改和使用 object
    glBindBuffer(GL_ARRAY_BUFFER, my_buffer_id);

    // 将 CPU 中的数据传给 GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
            verts, GL_STATIC_DRAW);

    // 当完成 buffer object 的赋值后，解绑，等需要的时候再绑定
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void GLWindow::paintGL() {
    glViewport(0, 0, width(), height());

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

}
