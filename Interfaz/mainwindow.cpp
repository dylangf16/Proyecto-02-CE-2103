#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QMouseEvent>
#include <QPainter>
#include <iostream>
#include <math.h>
using namespace std;

int nFilas = 500;
int nColumnas = 600;
std::string HEXColor;
std::string HEXarray[500][600];
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    color = Qt::black;
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 600; ++j) {
            HEXarray[i][j] = "#1188f0";
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Paint Event para colocar puntos de pixeles -------------------------------------------------
void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter PainterMatrix(this);
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 600; ++j) {
            QString color = QString::fromStdString(HEXarray[i][j]);
            QColor qcolor;
            qcolor.setNamedColor(color);
            QPen PenMatrix(qcolor);
            PainterMatrix.setPen(PenMatrix);
            PainterMatrix.drawPoint(i,j);
        }
    }

    /*
    //Para lapiz
    if(lapiz){
        QPainter painter(this);
        QPen Pen1(Qt::black);
        Pen1.setWidth(5);
        painter.setPen(Pen1);
        painter.setRenderHint(QPainter::Antialiasing,true);
        //painter.set
        for(int x=0; x<this->puntos.size(); x++) {
            painter.drawPoint(puntos[x]);
        }
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
        for(int x=0; x<this->puntos.size(); x++) {
            painter.drawPoint(puntos[x]);
        }
    }
    */
}


//Obtiene la posición del mouse cuando se presiona y acciona el Paint Event---------------------
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        color = color == Qt::black ? Qt::white : Qt::black;
    else{
        pressed = 1;
    }
    if(lapicero){
        if(LapiceroX0 == 0 && LapiceroY0 == 0){
            LapiceroX0 = event->pos().x();
            LapiceroY0 = event->pos().y();
        }
        else if(LapiceroX1 == 0 && LapiceroY1 == 0){
            LapiceroX1 = event->pos().x();
            LapiceroY1 = event->pos().y();
        }
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

            HEXColor = "#f05711";
            HEXarray[PosX][PosY] = HEXColor;
            //QPoint point(PosX, PosY);
            //this->puntos.push_back(point);
            update();
        }
    }
    if(borrador){
        if(pressed){
            PosX = event->pos().x();
            PosY = event->pos().y();
            HEXColor = "#ffffff";
            HEXarray[PosX][PosY] = HEXColor;

            //QPoint point(PosX, PosY);
            //this->puntos.push_back(point);
            update();
        }
    }
    if(lapicero){
        int vx = LapiceroX1 - LapiceroX0;
        int vy = LapiceroY1 - LapiceroY0;
        int step = abs(vx);

        if(step < abs(vy)) step = abs(vy);
        double xinc = (double)vx/step,
               yinc = (double)vy/step;

        while(step >= 0){
            HEXColor = "##58e014";
            HEXarray[LapiceroX0][LapiceroY0] = HEXColor;
            LapiceroX0 += xinc;
            LapiceroY0 += yinc;
            step--;
        }
        update();
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


    /*
    QColor rgb = q.pixelColor(PosX/12, PosY/12);
    cout << "Color RGB: " << rgb.name().toStdString() << endl;
    */
}





