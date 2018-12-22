#include <QApplication>
#include <QtWidgets>
#include "GLWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GLWindow *gl_window = new GLWindow;
    gl_window->show();

    return app.exec();
}