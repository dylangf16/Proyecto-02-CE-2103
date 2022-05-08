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
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_Lapiz_clicked();

    void on_Borrador_clicked();

    void on_Lapicero_clicked();

private:
    Ui::MainWindow *ui;
    QColor color;
    QPixmap *pixmap;
    bool pressed, lapiz, lapicero, figura, borrador;
    std::vector<QPoint> puntos_lapiz;
    std::vector<QPoint> puntos_borrador;
    std::vector<QPoint> puntos_lapicero;
    int PosX,PosY;

};
#endif // MAINWINDOW_H
