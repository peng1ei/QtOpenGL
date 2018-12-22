//
// Created by penglei on 18-12-21.
//

#ifndef QTOPENGL_GLWINDOW_H
#define QTOPENGL_GLWINDOW_H

#include <QtOpenGL/QGLWidget>

class GLWindow : public QGLWidget {
public:

protected:
    void initializeGL();
    void paintGL();

};


#endif //QTOPENGL_GLWINDOW_H
