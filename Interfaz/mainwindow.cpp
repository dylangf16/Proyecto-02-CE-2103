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

//Paint Event para colocar puntos de pixeles -------------------------------------------------
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

//Obtiene la posición del mouse cuando se presiona y acciona el Paint Event---------------------
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

//Detecta cuando se deja de presionar el botón del mouse ---------------------------------------
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    pressed = 0;
}

//Detecta el movimiento del mouse --------------------------------------------------------------
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(pressed){
        PosX = event->pos().x();
        PosY = event->pos().y();
        QPoint point(PosX, PosY);
        this->puntos.push_back(point);
        update();
    }

}






















