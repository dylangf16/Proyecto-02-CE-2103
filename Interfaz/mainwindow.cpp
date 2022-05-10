#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QMouseEvent>
#include <QPainter>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

std::string HEXColor;
int rConversion, gConversion, bConversion;
vector<vector<std::string>> HEXvec;

//#-------------------- Ventana Inicio -------------------------
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->iniciarPaint = false;
    ui->framePrincipal->hide();
    color = Qt::black;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//#---------------------------- Conversiones de filtros ----------------------------
void conversionHEXtoRGB(std::string HEXvalue){
    char const *hexColor = HEXvalue.c_str();
    std::sscanf(hexColor, "#%02x%02x%02x", &rConversion, &gConversion, &bConversion);
}

std::string conversionRGBtoHEX(int r, int g, int b){
    char hexColor[8];
    std::snprintf(hexColor, sizeof hexColor, "#%02x%02x%02x", r, g, b);
    std::string HEXvalue;
    HEXvalue += hexColor;
    return HEXvalue;
}

//#-------------------------- Apartado de Events --------------------------------------------------------
void MainWindow::paintEvent(QPaintEvent *event)
{
    if(this->iniciarPaint){
    QPainter PainterMatrix(this);
    for (int i = 0; i < HEXvec.size(); ++i) {
        for (int j = 0; j < HEXvec[0].size(); ++j) {
            QString color = QString::fromStdString(HEXvec[i][j]);
            QColor qcolor;
            qcolor.setNamedColor(color);
            QPen PenMatrix(qcolor);
            PainterMatrix.setPen(PenMatrix);
            PainterMatrix.drawPoint(i,j);
            //Arreglar reseteo de puntos
            }
        }
    }
}

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
            int vx = LapiceroX1 - LapiceroX0;
            int vy = LapiceroY1 - LapiceroY0;
            int step = abs(vx);

            if(step < abs(vy)) step = abs(vy);
            double xinc = (double)vx/step,
                   yinc = (double)vy/step;

            while(step >= 0){
                HEXColor = "#ff0000";
                HEXvec[round(LapiceroX0)][round(LapiceroY0)] = HEXColor;
                LapiceroX0 += xinc;
                LapiceroY0 += yinc;
                step--;

            update();
            }
            LapiceroX0 = 0;
            LapiceroX1 = 0;
            LapiceroY0 = 0;
            LapiceroY1 = 0;
        }
    }
    if(ColorPicker){
        PosX = event->pos().x();
        PosY = event->pos().y();
        HEXColor = HEXvec[PosX][PosY];
        ColorPicker = false;
    }
    if(cuadrado){
        PosX = event->pos().x();
        PosY = event->pos().y();
        //Linea hacia abajo
        for(int j = 0; j < 50; j++){
           HEXvec[PosX][PosY+j] = "#fcba03"; //Amarillo
        }
        //Hacia la derecha desde abajo
        for(int j = 0; j < 50; j++){
           HEXvec[PosX+j][PosY+50] = "#fcba03"; //Rojo
        }
        //Hacia arriba desde abajo derecha
        for(int j = 0; j < 50; j++){
           HEXvec[PosX+50][PosY+j] = "#fcba03"; //Azul
        }
        for(int j = 0; j < 50; j++){
           HEXvec[PosX+j][PosY] = "#fcba03"; //Verde
        }
        update();
        cuadrado = false;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->iniciarPaint){
    pressed = 0;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(lapiz){
        if(pressed){
            PosX = event->pos().x();
            PosY = event->pos().y();

            //HEXColor = "#f05711";
            HEXvec[PosX][PosY] = HEXColor;
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
            HEXvec[PosX][PosY] = HEXColor;

            //QPoint point(PosX, PosY);
            //this->puntos.push_back(point);
            update();
        }
    }
}

//# ----------------------------------------- Apartado de Botones ---------------------------
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
    LapiceroX0 = 0;
    LapiceroX1 = 0;
    LapiceroY0 = 0;
    LapiceroY1 = 0;
}

void MainWindow::on_ColorPicker_clicked()
{
    lapiz = false;
    lapicero = false;
    figura = false;
    borrador = false;
    ColorPicker = true;
}


void MainWindow::on_PaintFill_2_clicked()
{
    lapiz = false;
    lapicero = false;
    figura = false;
    borrador = false;
    ColorPicker = false;
}


void MainWindow::on_PaintFill_4_clicked()
{
    cuadrado = true;
}

//#---------------------- Apartado de filtros -----------------------------------------------

//Aplicar filtro negativo al canvas
//Si se presiona otra vez el botón, se devuelve a la normalidad
void MainWindow::on_Negativo_clicked()
{
    for (int i = 0; i < HEXvec.size(); ++i) {
        for (int j = 0; j < HEXvec[0].size(); ++j) {
            std::string HexVALUE = HEXvec[i][j];
            conversionHEXtoRGB(HexVALUE);
            int r2 = 255 - rConversion;
            int g2 = 255 - gConversion;
            int b2 = 255 - bConversion;
            char hexNEGATIVO[8];
            std::snprintf(hexNEGATIVO, sizeof hexNEGATIVO, "#%02x%02x%02x", r2,g2,b2);
            std::string conversion;
            conversion += hexNEGATIVO;
            HEXvec[i][j] = conversion;
        }
    }
    update();
}

//Aplicar filtro de escala de grises al canvas
//No se devuelve a la normalidad si se presiona otra vez
void MainWindow::on_Grises_clicked()
{
    for (int i = 0; i < HEXvec.size(); ++i) {
        for (int j = 0; j < HEXvec[0].size(); ++j) {
            std::string HexVALUE = HEXvec[i][j];
            conversionHEXtoRGB(HexVALUE);
            int greyscale = 0.299*rConversion + 0.587*gConversion + 0.114*bConversion;
            int r1 =greyscale;
            int g1 =greyscale;
            int b1 =greyscale;
            char hexGRIS[8];
            std::snprintf(hexGRIS, sizeof hexGRIS, "#%02x%02x%02x", r1,g1,b1);
            std::string conversion;
            conversion += hexGRIS;
            HEXvec[i][j] = conversion;
        }
    }
    update();
}

//#--------------------- Cambio de frames -----------------------------------------------
void MainWindow::on_btnStart_clicked()
{
    QString size;
    size = ui->plainTextHeight->toPlainText();
    this->canvasHeight = size.toInt();
    size = ui->plainTextEditWidth->toPlainText();
    this->canvasWidth = size.toInt();
    HEXvec.resize(this->canvasHeight);
    for (int i = 0; i < this->canvasHeight; ++i) {
          HEXvec[i].resize(this->canvasWidth);
        for (int j = 0; j < this->canvasWidth; ++j) {
            HEXvec[i][j] = "#1188f0";
        }
    }
    this->iniciarPaint = true;
    update();
    ui->frameInicio->hide();
    ui->framePrincipal->show();
}















