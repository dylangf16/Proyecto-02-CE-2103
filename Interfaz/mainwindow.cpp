#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "BMP/Image.h"
#include "BMP/Image.cpp"
#include <QMouseEvent>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

std::string HEXColor = "#000000";
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
void MainWindow::conversionHEXtoRGB(std::string HEXvalue){
    char const *hexColor = HEXvalue.c_str();
    std::sscanf(hexColor, "#%02x%02x%02x", &rConversion, &gConversion, &bConversion);
    RED = rConversion;
    GREEN = gConversion;
    BLUE = bConversion;
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
        conversionHEXtoRGB(Color1);
        ui->Color1->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color2);
        ui->Color2->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color3);
        ui->Color3->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color4);
        ui->Color4->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color5);
        ui->Color5->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color6);
        ui->Color6->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color7);
        ui->Color7->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color8);
        ui->Color8->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color9);
        ui->Color9->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color10);
        ui->Color10->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color11);
        ui->Color11->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
        conversionHEXtoRGB(Color12);
        ui->Color12->setStyleSheet("background-color: rgb("+ QString::number(RED)+","+ QString::number(GREEN)+","+ QString::number(BLUE)+")");
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        color = color == Qt::black ? Qt::white : Qt::black;
    else{
        pressed = 1;
    }
    if(borrador){
        PosX = event->pos().x();
        PosY = event->pos().y();
        for (int i = 0; i < grosor; i++) {
            for (int j = 0; j < grosor; j++) {
                HEXvec[PosX + j][PosY + i] = "#ffffff";
            }
        }
        update();
    }
    if (lapiz){
        PosX = event->pos().x();
        PosY = event->pos().y();
        for (int i = 0; i < grosor; i++) {
            for (int j = 0; j < grosor; j++) {
                HEXvec[PosX + j][PosY + i] = HEXColor;
            }
        }

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
        if(Color1Pressed){
            Color1 = HEXvec[PosX][PosY];
            HEXColor = Color1;
        }
        if(Color1Pressed){
            Color1 = HEXvec[PosX][PosY];
            HEXColor = Color1;
        }
        if(Color2Pressed){
            Color2 = HEXvec[PosX][PosY];
            HEXColor = Color2;
        }
        if(Color3Pressed){
            Color3 = HEXvec[PosX][PosY];
            HEXColor = Color3;
        }
        if(Color4Pressed){
            Color4 = HEXvec[PosX][PosY];
            HEXColor = Color4;
        }
        if(Color5Pressed){
            Color5 = HEXvec[PosX][PosY];
            HEXColor = Color5;
        }
        if(Color6Pressed){
            Color6 = HEXvec[PosX][PosY];
            HEXColor = Color6;
        }
        if(Color7Pressed){
            Color7 = HEXvec[PosX][PosY];
            HEXColor = Color7;
        }
        if(Color8Pressed){
            Color8 = HEXvec[PosX][PosY];
            HEXColor = Color8;
        }
        if(Color9Pressed){
            Color9 = HEXvec[PosX][PosY];
            HEXColor = Color9;
        }
        if(Color10Pressed){
            Color10 = HEXvec[PosX][PosY];
            HEXColor = Color10;
        }
        if(Color11Pressed){
            Color11 = HEXvec[PosX][PosY];
            HEXColor = Color11;
        }
        if(Color12Pressed){
            Color12 = HEXvec[PosX][PosY];
            HEXColor = Color12;
        }
        update();
        ColorPicker = false;
    }

    if(cuadrado) {
        PosX = event->pos().x();
        PosY = event->pos().y();

        for (int j = 0; j < 50; j++) {
            HEXvec[PosX][PosY + j] = HEXColor;
        }

        for(int j = 0; j < 50; j++){
            HEXvec[PosX+j][PosY+50] = HEXColor;
        }

        for(int j = 0; j < 50; j++){
            HEXvec[PosX+50][PosY+j] = HEXColor;
        }
        for(int j = 0; j < 50; j++){
            HEXvec[PosX+j][PosY] = HEXColor;
        }
        update();
    }

    if(triangulo){
        PosX = event->pos().x();
        PosY = event->pos().y();
        for(int j = 0; j < 50; j++){
            HEXvec[PosX-j][PosY+j] = HEXColor;
            HEXvec[PosX+j][PosY+j] = HEXColor;
        }
        for(int j=0;j<50;j++){
            HEXvec[PosX+j][PosY+50] = HEXColor;
        }
        for(int j=0;j<50;j++){
            HEXvec[PosX-j][PosY+50] = HEXColor;
        }
        update();
    }
    if(circulo){
        PosX = event->pos().x();
        PosY = event->pos().y();
        for(int j = 0; j < 10; j++){
            HEXvec[PosX+j][PosY] = HEXColor;//Izquierda Arriba // Naranja
            HEXvec[PosX-j][PosY] = HEXColor;//Derecha Arriba // Rojo
        }
        for(int j = 0; j < 7; j++){ //Lados diagonales
            HEXvec[PosX+10+j][PosY+j] = HEXColor;
            HEXvec[PosX-10-j][PosY+j] = HEXColor;
        }
        for(int j = 0; j < 15; j++){ //Lados rectos
            HEXvec[PosX+17][PosY+7+j] = HEXColor;
            HEXvec[PosX-17][PosY+7+j] = HEXColor;
        }
        for(int j = 0; j < 7; j++){ //Lados
            HEXvec[PosX+17-j][PosY+22+j] = HEXColor;
            HEXvec[PosX-17+j][PosY+22+j] = HEXColor;
        }
        for(int j = 0; j < 10; j++){
            HEXvec[PosX-10+j][PosY+29] = HEXColor;//Izquierda Arriba // Naranja
            HEXvec[PosX+10-j][PosY+29] = HEXColor;//Derecha Arriba // Rojo
        }

        update();
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
            PosY += 1;
            for (int i = 0; i < grosor; i++) {
                for (int j = 0; j < grosor; j++) {
                    HEXvec[PosX + j][PosY + i] = HEXColor;
                }
            }
            update();
        }
    }
    if(borrador){
        if(pressed) {
            PosX = event->pos().x();
            PosY = event->pos().y();
            for (int i = 0; i < grosor; i++) {
                for (int j = 0; j < grosor; j++) {
                    HEXvec[PosX + j][PosY + i] = "#ffffff";
                }
            }
            update();
        }
    }
}

//# ----------------------------------------- Apartado de Botones ---------------------------
void MainWindow::on_Lapiz_clicked()
{
    lapiz = true;
    lapicero = false;
    borrador = false;
    ColorPicker = false;

    cuadrado = false;
    triangulo = false;
    circulo = false;
}

void MainWindow::on_Borrador_clicked()
{
    lapiz = false;
    lapicero = false;
    borrador = true;
    ColorPicker = false;

    cuadrado = false;
    triangulo = false;
    circulo = false;
}

void MainWindow::on_Lapicero_clicked()
{
    lapiz = false;
    lapicero = true;
    borrador = false;
    ColorPicker = false;
    LapiceroX0 = 0;
    LapiceroX1 = 0;
    LapiceroY0 = 0;
    LapiceroY1 = 0;

    cuadrado = false;
    triangulo = false;
    circulo = false;
}

void MainWindow::on_ColorPicker_clicked()
{
    lapiz = false;
    lapicero = false;
    borrador = false;
    ColorPicker = true;

    cuadrado = false;
    triangulo = false;
    circulo = false;
}

void MainWindow::on_Cuadrado_clicked()
{
    lapiz = false;
    lapicero = false;
    borrador = false;
    ColorPicker = false;

    cuadrado = true;
    triangulo = false;
    circulo = false;
}

void MainWindow::on_Triangulo_clicked()
{
    lapiz = false;
    lapicero = false;
    borrador = false;
    ColorPicker = false;

    cuadrado = false;
    triangulo = true;
    circulo = false;
}

void MainWindow::on_Circulo_clicked()
{
    lapiz = false;
    lapicero = false;
    borrador = false;
    ColorPicker = false;

    cuadrado = false;
    triangulo = false;
    circulo = true;

}


void MainWindow::on_RotarDer_clicked()
{
    rotateToTheRight();
    update();
}


void MainWindow::on_RotarIzq_clicked()
{
    rotateToTheLeft();
    update();
}


void MainWindow::on_RotarVer_clicked()
{
    verticalRotation();
    update();
}


void MainWindow::on_RotarHor_clicked()
{
    horizontalRotation();
    update();
}

void MainWindow::on_SeleccionarGrosor_clicked()
{
    QString grosorDado = ui->Grosor->toPlainText();
    grosor = grosorDado.toInt();
}


void MainWindow::on_Color1_clicked()
{
    Color1Pressed = true;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color1;
}

void MainWindow::on_Color2_clicked()
{
    Color1Pressed = false;
    Color2Pressed = true;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color2;
}

void MainWindow::on_Color3_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = true;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color3;
}

void MainWindow::on_Color4_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = true;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color4;
}

void MainWindow::on_Color5_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = true;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color5;
}

void MainWindow::on_Color6_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = true;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color6;
}

void MainWindow::on_Color7_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = true;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color7;
}

void MainWindow::on_Color8_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = true;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color8;
}

void MainWindow::on_Color9_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = true;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color9;
}

void MainWindow::on_Color10_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = true;
    Color11Pressed = false;
    Color12Pressed = false;

    HEXColor = Color10;
}

void MainWindow::on_Color11_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = true;
    Color12Pressed = false;

    HEXColor = Color11;
}

void MainWindow::on_Color12_clicked()
{
    Color1Pressed = false;
    Color2Pressed = false;
    Color3Pressed = false;
    Color4Pressed = false;
    Color5Pressed = false;
    Color6Pressed = false;
    Color7Pressed = false;
    Color8Pressed = false;
    Color9Pressed = false;
    Color10Pressed = false;
    Color11Pressed = false;
    Color12Pressed = true;

    HEXColor = Color12;
}


//#---------------------- Apartado de filtros -----------------------------------------------

//Aplicar filtro negativo al canvas
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
//#--------------------- Metodos --------------------------------------------------------
void MainWindow::rotateToTheRight(){
    int newWidth =HEXvec.size();
    int newHeight = HEXvec[0].size();
    vector<vector<std::string>> output;
    output.resize(newHeight);
    for(int i=0; i<newHeight; i++) {
        output[i].resize(newWidth);
    }
    for (int i=0; i<newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            output[j][newWidth - 1 - i] = HEXvec[i][j];
        }
    }
    HEXvec = output;
}

void MainWindow::rotateToTheLeft(){
    int newWidth =HEXvec.size();
    int newHeight = HEXvec[0].size();
    vector<vector<std::string>> output;
    output.resize(newHeight);
    for(int i=0; i<newHeight; i++) {
        output[i].resize(newWidth);
    }
    for (int i=0; i<newWidth; i++) {
        int k = newHeight-1;
        for (int j = 0; j < newHeight; j++) {
            output[k][i] = HEXvec[i][j];
            k--;
        }
    }
    HEXvec = output;
}

void MainWindow::verticalRotation(){
    vector<vector<std::string>> output;
    output = HEXvec;
    for (int i=0; i<HEXvec.size(); i++) {
        int k = HEXvec[0].size() - 1;
        for (int j = 0; j < HEXvec[0].size(); j++) {
            output[i][j] = HEXvec[i][k];
            k--;
        }
    }
    HEXvec = output;
}

void MainWindow::horizontalRotation(){
    vector<vector<std::string>> output;
    output = HEXvec;
    int k = HEXvec.size();
    for (int i=0; i<HEXvec.size(); i++) {
        k--;
        for (int j = 0; j < HEXvec[0].size(); j++) {
            output[i][j] = HEXvec[k][j];
        }
    }
    HEXvec = output;
}


void MainWindow::createCanvas(){
    QString size;
    size = ui->plainTextGetHeight->toPlainText();
    this->canvasHeight = size.toInt();
    size = ui->plainTextEditGetWidth->toPlainText();
    this->canvasWidth = size.toInt();
    HEXvec.resize(this->canvasHeight);
    for (int i = 0; i < this->canvasHeight; ++i) {
        HEXvec[i].resize(this->canvasWidth);
        for (int j = 0; j < this->canvasWidth; ++j) {
            HEXvec[i][j] = "#1188f0";
        }
    }
}

void MainWindow::loadImage(){
    QString ImageDir;
    ImageDir = ui->plainTextGetDir->toPlainText();
    QByteArray ba = ImageDir.toLocal8Bit();
    const char *ImageDirectory = ba.data();
    Image image(0,0);
    image.Read(ImageDirectory);
    HEXvec = image.BMPtoMatrix();
    rotateToTheRight();
}


//#--------------------- Cambio de frames -----------------------------------------------

bool IsTextEditEmpty(const QTextEdit * myTextEdit)
{
    return myTextEdit->document()->isEmpty();
}

void MainWindow::on_btnStart_clicked()
{
    if(!IsTextEditEmpty(reinterpret_cast<const QTextEdit *>(ui->plainTextGetHeight)) and !IsTextEditEmpty(reinterpret_cast<const QTextEdit *>(ui->plainTextEditGetWidth))) {
        createCanvas();
    } else if(!IsTextEditEmpty(reinterpret_cast<const QTextEdit *>(ui->plainTextGetDir))){
        loadImage();
    }
    this->iniciarPaint = true;
    update();
    ui->frameInicio->hide();
    ui->framePrincipal->show();
}

void MainWindow::on_Save_clicked()
{
    QString givenImageName;
    givenImageName = ui->plainTextGetName->toPlainText();
    QByteArray bb = givenImageName.toLocal8Bit();
    const char *ImageName = bb.data();
    Image image(0,0);
    rotateToTheLeft();
    image.matrixToBMP(HEXvec);
    image.Export(ImageName);
}
