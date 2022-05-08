#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QMouseEvent>
#include <QPainter>
#include <iostream>
using namespace std;

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
    painter.setPen(color);
    //painter.set
    painter.drawPoint(PosX, PosY);
    cout << PosX << " " << PosY << endl;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        color = color == Qt::black ? Qt::white : Qt::black;
    else{
        pressed = 1;
        PosX = event->pos().x();
        PosY = event->pos().y();
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    pressed = 0;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    update();
}


