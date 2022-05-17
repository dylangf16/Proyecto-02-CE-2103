#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "BMP/Image.h"
#include "BMP/Image.cpp"
#include "Stack.h"
#include <QMouseEvent>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

std::string HEXColor = "#000000";
int rConversion, gConversion, bConversion;
vector<vector<std::string>> HEXvec;
Stack undoStack;
Stack redoStack;
bool lastCanvasWasSaved;

//#-------------------- Ventana Inicio -------------------------
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->iniciarPaint = false;
    ui->framePrincipal->hide();
    color = Qt::black;
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
    }
}

void MainWindow::borrar(QMouseEvent *event){
    PosX = event->pos().x();
    PosY = event->pos().y();
    for (int i = 0; i < grosor; i++) {
        for (int j = 0; j < grosor; j++) {
            HEXvec[PosX + j][PosY + i] = "#ffffff";
        }
    }

}

void MainWindow::pintarConLapiz(QMouseEvent *event){
    PosX = event->pos().x();
    PosY = event->pos().y();
    for (int i = 0; i < grosor; i++) {
        for (int j = 0; j < grosor; j++) {
            HEXvec[PosX + j][PosY + i] = HEXColor;
            update();
        }
    }
}

void MainWindow::PaintFill(QMouseEvent *event) {
    PosX = event->pos().x();
    PosY = event->pos().y();
    BFS(HEXvec, PosX, PosY, HEXColor);
    update();
}


void MainWindow::pintarConLapicero(QMouseEvent *event, int x1, int y1, int x2, int y2, int dx, int dy, int decide){
    int pk = 2 * dy - dx;
    for (int i = 0; i <= dx; i++)
    {
        x1 < x2 ? x1++ : x1--;
        if (pk < 0)
        {
            if (decide == 0)
            {
                for (int i = 0; i < grosor; i++) {
                    for (int j = 0; j < grosor; j++) {
                        HEXvec[x1+j][y1+i] = HEXColor;
                    }
                }
                pk = pk + 2 * dy;
            }
            else
            {
                for (int i = 0; i < grosor; i++) {
                    for (int j = 0; j < grosor; j++) {
                        HEXvec[y1+i][x1+j] = HEXColor;
                    }
                }
                pk = pk + 2 * dy;
            }
        }
        else
        {
            y1 < y2 ? y1++ : y1--;
            if (decide == 0)
            {
                for (int i = 0; i < grosor; i++) {
                    for (int j = 0; j < grosor; j++) {
                        HEXvec[x1+j][y1+i] = HEXColor;
                    }
                }
            }
            else
            {
                for (int i = 0; i < grosor; i++) {
                    for (int j = 0; j < grosor; j++) {
                        HEXvec[y1+i][x1+j] = HEXColor;
                    }
                }
            }
            pk = pk + 2 * dy - 2 * dx;
        }
    }
}

void MainWindow::pickColor(QMouseEvent *event){
    PosX = event->pos().x();
    PosY = event->pos().y();
    if(Color1Pressed){
        Color1 = HEXvec[PosX][PosY];
        HEXColor = Color1;
    }
    else if(Color2Pressed){
        Color2 = HEXvec[PosX][PosY];
        HEXColor = Color2;
    }
    else if(Color3Pressed){
        Color3 = HEXvec[PosX][PosY];
        HEXColor = Color3;
    }
    else if(Color4Pressed){
        Color4 = HEXvec[PosX][PosY];
        HEXColor = Color4;
    }
    else if(Color5Pressed){
        Color5 = HEXvec[PosX][PosY];
        HEXColor = Color5;
    }
    else if(Color6Pressed){
        Color6 = HEXvec[PosX][PosY];
        HEXColor = Color6;
    }
    else if(Color7Pressed){
        Color7 = HEXvec[PosX][PosY];
        HEXColor = Color7;
    }
    else if(Color8Pressed){
        Color8 = HEXvec[PosX][PosY];
        HEXColor = Color8;
    }
    else if(Color9Pressed){
        Color9 = HEXvec[PosX][PosY];
        HEXColor = Color9;
    }
    else if(Color10Pressed){
        Color10 = HEXvec[PosX][PosY];
        HEXColor = Color10;
    }
    else if(Color11Pressed){
        Color11 = HEXvec[PosX][PosY];
        HEXColor = Color11;
    }
    else if(Color12Pressed){
        Color12 = HEXvec[PosX][PosY];
        HEXColor = Color12;
    }
    ColorPicker = false;
}

void MainWindow::dibujarCuadrado(QMouseEvent *event){
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
}

void MainWindow::dibujarTriangulo(QMouseEvent *event){
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
}

void MainWindow::dibujarCirculo(QMouseEvent *event){
    PosX = event->pos().x();
    PosY = event->pos().y();
    for(int j = 0; j < 10; j++){
        HEXvec[PosX+j][PosY] = HEXColor;
        HEXvec[PosX-j][PosY] = HEXColor;
    }
    for(int j = 0; j < 7; j++){
        HEXvec[PosX+10+j][PosY+j] = HEXColor;
        HEXvec[PosX-10-j][PosY+j] = HEXColor;
    }
    for(int j = 0; j < 15; j++){
        HEXvec[PosX+17][PosY+7+j] = HEXColor;
        HEXvec[PosX-17][PosY+7+j] = HEXColor;
    }
    for(int j = 0; j < 7; j++){ //Lados
        HEXvec[PosX+17-j][PosY+22+j] = HEXColor;
        HEXvec[PosX-17+j][PosY+22+j] = HEXColor;
    }
    for(int j = 0; j < 10; j++){
        HEXvec[PosX-10+j][PosY+29] = HEXColor;
        HEXvec[PosX+10-j][PosY+29] = HEXColor;
    }
    for(int j = 0; j < 3; j++){
        HEXvec[PosX+j][PosY+29] = HEXColor;
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
        borrar(event);
    }
    else if (lapiz){
        pintarConLapiz(event);
    }
    else if(lapicero){
        if(!LapiceroClicked1){
            LapiceroX1 = event->pos().x();
            LapiceroY1 = event->pos().y();
            LapiceroClicked1 = true;
        }
        else if(!LapiceroClicked2) {
            int x2 = event->pos().x();
            int y2 = event->pos().y();
            LapiceroClicked2 = true;
            int dx = abs(x2 - LapiceroX1);
            int dy = abs(y2 - LapiceroY1);

            if(dx > dy){
                pintarConLapicero(event, LapiceroX1, LapiceroY1, x2, y2, dx, dy,0);
            }else{
                pintarConLapicero(event, LapiceroY1, LapiceroX1, y2, x2, dy, dx,1);
            }
            LapiceroClicked1 = false;
            LapiceroClicked2 = false;
        }
    }
    else if(ColorPicker){
        pickColor(event);
    }
    else if(cuadrado) {
        dibujarCuadrado(event);
    }
    else if(triangulo){
        dibujarTriangulo(event);
    }
    else if(circulo){
        dibujarCirculo(event);
    }
    else if(Fill){
        PaintFill(event);
    }
    else if(SelecCuadrado){
        CuadradoSeleccion(event);
    }
    else if(SelecMagic){
        MagicSeleccion(event);
    }
    else if(SelecLapiz){
        LapizSeleccion(event);
    }
    undoStack.push(HEXvec);
    update();
    lastCanvasWasSaved = true;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(this->iniciarPaint){
        pressed = 0;
    }
    if(SelecLapiz){
        PosX = event->pos().x();
        PosY = event->pos().y();
        PosY = PosY + grosor + 50;
        cout << HEXvec[PosX][PosY] << endl;
        BFSSeleccionLapiz(HEXvec,PosX, PosY, "#bfbfbf");
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
            borrar(event);
            update();
        }
    }
    if(SelecLapiz){
        PosX = event->pos().x();
        PosY = event->pos().y();
        PosY += 1;

        SelecPuntos.resize(1000);
        for(int i = 0; i < HEXvec.size(); i++){
            SelecPuntos[i].resize(1000);
        }

        for (int i = 0; i < grosor; i++) {
            for (int j = 0; j < grosor; j++) {
                HEXvec[PosX + j][PosY + i] = "#bfbfbf";
            }
        }
        update();
    }
}

void MainWindow::CuadradoSeleccion(QMouseEvent *event) {
    if(!SelecCuadrado1){
        SelecPosX1 = event->pos().x();
        SelecPosY1 = event->pos().y();
        SelecCuadrado1 = true;
    }
    else if(!SelecCuadrado2) {
        SelecPosX2 = event->pos().x();
        SelecPosY2 = event->pos().y();
        SelecCuadrado2 = true;

        SelecPuntos.resize(SelecPosX2);
        for(int i = SelecPosX1; i < SelecPosX2; i++){
            SelecPuntos[i].resize(SelecPosY2);
            for (int j = SelecPosY1; j < SelecPosY2; j++) {
                HEXvec[i][j] = "#bfbfbf";
                SelecPuntos[i][j] = to_string(i) + "," + to_string(j) + " -";
                cout << SelecPuntos[i][j];
                cout << " ";
            }
            cout << "\n";
        }
        SelecCuadrado1 = false;
        SelecCuadrado2 = false;
    } update();
}

void MainWindow::MagicSeleccion(QMouseEvent *event) {
    PosX = event->pos().x();
    PosY = event->pos().y();
    BFS(HEXvec, PosX, PosY, "#bfbfbf");
}

void MainWindow::LapizSeleccion(QMouseEvent *event)
{

}

//# ----------------------------------------- Apartado de Botones ---------------------------
void MainWindow::deactivateAllButtons(){
    lapiz = false;
    lapicero = false;
    borrador = false;
    ColorPicker = false;

    cuadrado = false;
    triangulo = false;
    circulo = false;

    Fill = false;

    SelecCuadrado = false;
    SelecLapiz = false;
    SelecMagic = false;
}

void MainWindow::on_Lapiz_clicked()
{
    deactivateAllButtons();
    lapiz = true;
}

void MainWindow::on_Borrador_clicked()
{
    deactivateAllButtons();
    borrador = true;
}

void MainWindow::on_Lapicero_clicked()
{
    deactivateAllButtons();
    lapicero = true;
}

void MainWindow::on_ColorPicker_clicked()
{
    deactivateAllButtons();
    ColorPicker = true;
}

void MainWindow::on_Cuadrado_clicked()
{
    deactivateAllButtons();
    cuadrado = true;
}

void MainWindow::on_Triangulo_clicked()
{
    deactivateAllButtons();
    triangulo = true;
}

void MainWindow::on_Circulo_clicked()
{
    deactivateAllButtons();
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

void MainWindow::on_PaintFill_clicked()
{
    deactivateAllButtons();
    Fill = true;
}

void MainWindow::on_SeleccionarLapiz_clicked()
{
    deactivateAllButtons();
    SelecLapiz = true;
}

void MainWindow::on_SeleccionarCuadrado_clicked()
{
    deactivateAllButtons();
    SelecCuadrado = true;
}

void MainWindow::on_SeleccionarMagico_clicked()
{
    deactivateAllButtons();
    SelecMagic = true;
}


void MainWindow::deactivateAllColors(){
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
    Color12Pressed = false;
    lastCanvasWasSaved = false;
}

void MainWindow::on_Color1_clicked()
{
    deactivateAllColors();
    Color1Pressed = true;
    HEXColor = Color1;
}

void MainWindow::on_Color2_clicked()
{
    deactivateAllColors();
    Color2Pressed = true;
    HEXColor = Color2;
}

void MainWindow::on_Color3_clicked()
{
    deactivateAllColors();
    Color3Pressed = true;
    HEXColor = Color3;
}

void MainWindow::on_Color4_clicked()
{
    deactivateAllColors();
    Color4Pressed = true;
    HEXColor = Color4;
}

void MainWindow::on_Color5_clicked()
{
    deactivateAllColors();
    Color5Pressed = true;
    HEXColor = Color5;
}

void MainWindow::on_Color6_clicked()
{
    deactivateAllColors();
    Color6Pressed = true;
    HEXColor = Color6;
}

void MainWindow::on_Color7_clicked()
{
    deactivateAllColors();
    Color7Pressed = true;
    HEXColor = Color7;
}

void MainWindow::on_Color8_clicked()
{
    deactivateAllColors();
    Color8Pressed = true;
    HEXColor = Color8;
}

void MainWindow::on_Color9_clicked()
{
    deactivateAllColors();
    Color9Pressed = true;
    HEXColor = Color9;
}

void MainWindow::on_Color10_clicked()
{
    deactivateAllColors();
    Color10Pressed = true;
    HEXColor = Color10;
}

void MainWindow::on_Color11_clicked()
{
    deactivateAllColors();
    Color11Pressed = true;
    HEXColor = Color11;
}

void MainWindow::on_Color12_clicked()
{
    deactivateAllColors();
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

void MainWindow::on_FiltroAzules_clicked()
{
    for (int i = 0; i < HEXvec.size(); ++i) {
        for (int j = 0; j < HEXvec[0].size(); ++j) {
            std::string HexVALUE = HEXvec[i][j];
            conversionHEXtoRGB(HexVALUE);
            int r2 = 127 - rConversion;
            int g2 = 127 - gConversion;
            int b2 = 127 - bConversion;
            char hexNEGATIVO[8];
            std::snprintf(hexNEGATIVO, sizeof hexNEGATIVO, "#%02x%02x%02x", r2,g2,b2);
            std::string conversion;
            conversion += hexNEGATIVO;
            HEXvec[i][j] = conversion;
        }
    }
    update();
}


void MainWindow::on_FiltroRaro_clicked()
{
    for (int i = 0; i < HEXvec.size(); ++i) {
        for (int j = 0; j < HEXvec[0].size(); ++j) {
            std::string HexVALUE = HEXvec[i][j];
            conversionHEXtoRGB(HexVALUE);
            int r2 = 200 - rConversion;
            int g2 = 150 - gConversion;
            int b2 = 100 - bConversion;
            char hexNEGATIVO[8];
            std::snprintf(hexNEGATIVO, sizeof hexNEGATIVO, "#%02x%02x%02x", r2,g2,b2);
            std::string conversion;
            conversion += hexNEGATIVO;
            HEXvec[i][j] = conversion;
        }
    }
    update();
}


//#------------------------------------------- Metodos --------------------------------------------------------

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
            HEXvec[i][j] = "#87ceeb";
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
}

//Leer a ver como funciona JAJAJAJJAJA
void MainWindow::BFS(vector<vector<std::string>> &mat, int r, int c, std::string target) {
    int rows = mat.size();
    if (0 == rows){
        return;
    }
    int cols = mat[0].size();
    if (0 == cols) {
        return ;
    }
    unordered_set<string> vis;
    queue<vector<int>> Q;
    Q.push({r, c});
    vector<int> d{1, 0, -1, 0, 1};
    auto cur = mat[r][c];
    int num1 = 0;
    int num2 = 0;

    SelecPuntos.resize(1000);
    for(int i = 0; i < mat[0].size(); i++){
        SelecPuntos[i].resize(1000);
    }
    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        auto key = std::to_string(p[0]) + "," + std::to_string(p[1]);
        if (vis.count(key)) continue;
        vis.insert(key);
        mat[p[0]][p[1]] = target;
        for (int i = 0; i < 4; ++ i) {
            int nx = p[0] + d[i];
            int ny = p[1] + d[i + 1];
            if ((nx >= 0) && (ny >= 0) && (nx < rows) && (ny < cols) && (mat[nx][ny] == cur)) {
                Q.push({nx, ny});

                if(SelecMagic){
                    HEXvec[nx][ny] = "#bfbfbf";
                    if(num1 < mat.size()){
                        if(num2 < 10){
                            SelecPuntos[num1][num2] = to_string(nx) + "," + to_string(ny) + " - ";
                            cout << SelecPuntos[num1][num2];
                            cout << " ";
                            num2++;
                        }else{
                            num1++;
                            num2 = 0;
                            cout << "\n";
                        }
                    }else{
                        num1 = 0;
                    }
                }
            }
        }
    }
    update();
}

void MainWindow::BFSSeleccionLapiz(vector<vector<std::string>> &mat, int r, int c, std::string target) {
    int rows = mat.size();
    if (0 == rows){
        return;
    }
    int cols = mat[0].size();
    if (0 == cols) {
        return ;
    }
    unordered_set<string> vis;
    queue<vector<int>> Q;
    Q.push({r, c});
    vector<int> d{1, 0, -1, 0, 1};
    auto cur = "#bfbfbf";

    SelecPuntos.resize(1000);
    for(int i = 0; i < mat[0].size(); i++){
        SelecPuntos[i].resize(1000);
    }
    int num1 = 0;
    int num2 = 0;

    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        auto key = std::to_string(p[0]) + "," + std::to_string(p[1]);
        if (vis.count(key)) continue;
        vis.insert(key);
        mat[p[0]][p[1]] = target;
        for (int i = 0; i < 4; ++ i) {
            int nx = p[0] + d[i];
            int ny = p[1] + d[i + 1];
            if ((nx >= 0) && (ny >= 0) && (nx < rows) && (ny < cols) && (mat[nx][ny] != cur)) {
                Q.push({nx, ny});
                if(num1 < mat.size()){
                    if(num2 < 10){
                        SelecPuntos[num1][num2] = to_string(nx) + "," + to_string(ny) + " - ";
                        cout << SelecPuntos[num1][num2];
                        cout << " ";
                        num2++;
                    }else{
                        num1++;
                        num2 = 0;
                        cout << "\n";
                    }
                }else{
                    num1 = 0;
                }
            }
        }
    }
    update();
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
    rotateToTheRight();
    undoStack.push(HEXvec);
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
    rotateToTheRight();
}

void MainWindow::on_Undo_clicked()
{
    if(lastCanvasWasSaved) {
        undoStack.pop();
    }
    redoStack.push(HEXvec);
    HEXvec = undoStack.pop();
    update();
    lastCanvasWasSaved = false;
}


void MainWindow::on_Redo_clicked()
{
    undoStack.push(HEXvec);
    HEXvec = redoStack.pop();
    update();
}






