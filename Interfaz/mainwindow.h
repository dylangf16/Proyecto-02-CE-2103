#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QPainter"
#include "QMouseEvent"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QColor color;
    bool pressed;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void MousePressEvent(QMouseEvent *e);
    void MouseRealeaseEvent(QMouseEvent *e);
    void Draw(QMouseEvent *e);
    void MouseMoveEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
