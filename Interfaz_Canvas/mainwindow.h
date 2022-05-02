#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void on_Lapicero_clicked();

private:
    Ui::MainWindow *ui;
    void drawLines(QPainter *p);
    QPoint startPos;
    QPoint endPos;
    bool inDrawing;
    QVector<QLine> lines;
};

#endif // MAINWINDOW_H
