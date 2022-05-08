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
    QPen Pen1(Qt::black);
    Pen1.setWidth(10);
    painter.setPen(Pen1);
    painter.setRenderHint(QPainter::Antialiasing,true);
    //painter.set
    for(int x=0; x<this->puntos.size(); x++) {
        painter.drawPoint(puntos[x]);
    }
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
        QPoint point(PosX, PosY);
        this->puntos.push_back(point);
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


