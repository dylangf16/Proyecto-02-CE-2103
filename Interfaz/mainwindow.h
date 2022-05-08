#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent( QPaintEvent *) override;
    void mousePressEvent( QMouseEvent *) override;
    void mouseReleaseEvent( QMouseEvent *) override;
    void mouseMoveEvent( QMouseEvent *) override;

private:
    Ui::MainWindow *ui;
    QPoint *points; // point array
    QColor *colors; // color array
    int count; // count = number of points
    bool down; // TRUE if mouse down
};
#endif // MAINWINDOW_H
