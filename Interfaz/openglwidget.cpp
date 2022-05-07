#include "openglwidget.h"
OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget { parent }
{

}

void OpenGLWidget::initializeGL()
{
    float r, g, b, a = 1.0f;
    initializeOpenGLFunctions();
    qColorToRGB(Qt::black, r,g,b);
    glClearColor(r,g,b,a);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Aquí se pinta lo que quiera
}

void OpenGLWidget::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLWidget::qColorToRGB(const QColor &C, float &r, float &g, float &b) const
{
    r = normalize(C.red(), 1.0f, 255.0f);
    g = normalize(C.green(), 1.0f, 255.0f);
    b = normalize(C.blue(), 1.0f, 255.0f);
}

int OpenGLWidget::normalize(float value, float min, float max) const
{
    return (value - min) / (max - min);
}
