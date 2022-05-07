#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QColor>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
public:
    OpenGLWidget(QWidget *parent = nullptr);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
private:
    void qColorToRGB(const QColor &C, float &r, float &g, float &b) const;
    int normalize(float value, float min, float max) const;
};

#endif // OPENGLWIDGET_H
