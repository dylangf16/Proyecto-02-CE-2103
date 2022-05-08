#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    color = Qt::black;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        color = color == Qt::black ? Qt::white : Qt::black;
    else{
        pressed = 1;
        draw(event);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    pressed = 0;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    draw(event);
}

void MainWindow::draw(QMouseEvent *event)
{
    if(pressed){
        QPainter painter(this);
        painter.setPen(color);
        int x = event->pos().x() / 12;
        int y = event->pos().y() / 12;
        painter.drawPoint(x,y);
        repaint();
    }
}


