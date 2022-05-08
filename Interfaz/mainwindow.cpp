#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QMouseEvent>
#include <QPainter>

int PosX,PosY;
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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPoint(PosX,PosY);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        color = color == Qt::black ? Qt::black : Qt::black;
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
        PosX = event->pos().x() / 12;
        PosY = event->pos().y() / 12;
        painter.drawPoint(PosX,PosY);
        update();
    }
}


