#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QMouseEvent>
#include <QPainter>
#include <iostream>
using namespace std;

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
    //Para lapiz
    if(lapiz){
        QPainter painter(this);
        QPen Pen1(Qt::black);
        Pen1.setWidth(5);
        painter.setPen(Pen1);
        painter.setRenderHint(QPainter::Antialiasing,true);
        //painter.set
        for(int x=0; x<this->puntos_lapiz.size(); x++) {
            painter.drawPoint(puntos_lapiz[x]);
        }
        cout << PosX << " " << PosY << endl;
    }
    //Para lapicero (líneas rectas)
    if(lapicero){
        cout << "Lapicero activado" << endl;
    }
    if(borrador){
        QPainter painter(this);
        QPen Pen1(Qt::white);
        Pen1.setWidth(5);
        painter.setPen(Pen1);
        painter.setRenderHint(QPainter::Antialiasing,true);
        //painter.set
        for(int x=0; x<this->puntos_borrador.size(); x++) {
            painter.drawPoint(puntos_borrador[x]);
        }
        cout << PosX << " " << PosY << endl;
    }
}


//Obtiene la posición del mouse cuando se presiona y acciona el Paint Event---------------------
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        color = color == Qt::black ? Qt::white : Qt::black;
    else{
        pressed = 1;
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
    if(lapiz){
        if(pressed){
            PosX = event->pos().x();
            PosY = event->pos().y();
            QPoint point(PosX, PosY);
            this->puntos_lapiz.push_back(point);
            update();
        }
    }
    if(borrador){
        if(pressed){
            PosX = event->pos().x();
            PosY = event->pos().y();
            QPoint point(PosX, PosY);
            this->puntos_borrador.push_back(point);
            update();
        }
    }
}

//Lapiz
void MainWindow::on_Lapiz_clicked()
{
    lapiz = true;
    lapicero = false;
    figura = false;
    borrador = false;
}

void MainWindow::on_Borrador_clicked()
{
    lapiz = false;
    lapicero = false;
    figura = false;
    borrador = true;
}

void MainWindow::on_Lapicero_clicked()
{
    lapiz = false;
    lapicero = true;
    figura = false;
    borrador = false;
}
