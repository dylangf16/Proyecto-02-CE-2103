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
bool lapiceroWasJustUsed = false;

//#-------------------- Ventana Inicio -------------------------
/**
 * Inicializacion de la ventana de inicio
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->iniciarPaint = false;
    ui->framePrincipal->hide();
    ui->frameSecundario->hide();
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
/**
 * Convierte valores HEX a RGB
 * @param HEXvalue valor HEX que se desea convertir a RGB
 */
void MainWindow::conversionHEXtoRGB(std::string HEXvalue){
    char const *hexColor = HEXvalue.c_str();
    std::sscanf(hexColor, "#%02x%02x%02x", &rConversion, &gConversion, &bConversion);
    RED = rConversion;
    GREEN = gConversion;
    BLUE = bConversion;
}

//#-------------------------- Apartado de Events --------------------------------------------------------
/**
 * Pinta la matriz en la ventana de inicio
 */
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

/**
 * Pinta de blanco los pixeles seleccionados por el usuario
 * @param event
 */
void MainWindow::borrar(QMouseEvent *event){
    PosX = event->pos().x();
    PosY = event->pos().y();
    for (int i = 0; i < grosor; i++) {
        for (int j = 0; j < grosor; j++) {
            HEXvec[PosX + j][PosY + i] = "#ffffff";
        }
    }
}

/**
 * Pinta del color actualmente en uso los pixeles seleccionados por el usuario
 * @param event
 */
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

/**
 * Llama la funcion, con los paramentros adecuados, que realizar el pintado de relleno
 * @param event
 */
void MainWindow::PaintFill(QMouseEvent *event) {
    PosX = event->pos().x();
    PosY = event->pos().y();
    BFS(HEXvec, PosX, PosY, HEXColor);
    update();
}

/**
 * Pinta una linea recta en el canvas
 * @param event
 * @param x1 ubicacion en el eje x del primer punto de la linea
 * @param y1 ubicacion en el eje y del primer punto de la linea
 * @param x2 ubicacion en el eje x del segundo punto de la linea
 * @param y2 ubicacion en el eje y del segundo punto de la linea
 * @param dx valor absoluto de (x2-x1)
 * @param dy valor absoluto de (y2-y1)
 * @param decide
 */
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

/**
 * Guarda el color seleccionado en los botones de color
 * @param event
 */
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

/**
 * Dibuja un cuadrado en la matriz
 * @param event
 */
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

/**
 * Dibuja un triangulo en la matriz
 * @param event
 */
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

/**
 * Dibuja un circulo en la matriz
 * @param event
 */
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

/**
 * Evento para detectar el click de mouse y realizar las acciones necesarias
 * @param event
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->pos().y() <= HEXvec.size() and event->pos().x() <= HEXvec[0].size()) {
        if (event->button() == Qt::RightButton)
            color = color == Qt::black ? Qt::white : Qt::black;
        else {
            pressed = 1;
        }
        if (borrador) {
            borrar(event);
        } else if (lapiz) {
            pintarConLapiz(event);
        } else if (lapicero) {
            if (!LapiceroClicked1) {
                LapiceroX1 = event->pos().x();
                LapiceroY1 = event->pos().y();
                LapiceroClicked1 = true;
            } else if (!LapiceroClicked2) {
                int x2 = event->pos().x();
                int y2 = event->pos().y();
                LapiceroClicked2 = true;
                int dx = abs(x2 - LapiceroX1);
                int dy = abs(y2 - LapiceroY1);

                if (dx > dy) {
                    pintarConLapicero(event, LapiceroX1, LapiceroY1, x2, y2, dx, dy, 0);
                } else {
                    pintarConLapicero(event, LapiceroY1, LapiceroX1, y2, x2, dy, dx, 1);
                }
                lapiceroWasJustUsed = true;
                LapiceroClicked1 = false;
                LapiceroClicked2 = false;
            }
        } else if (ColorPicker) {
            pickColor(event);
        } else if (cuadrado) {
            dibujarCuadrado(event);
        } else if (triangulo) {
            dibujarTriangulo(event);
        } else if (circulo) {
            dibujarCirculo(event);
        } else if (Fill) {
            PaintFill(event);
        } else if (SelecCuadrado) {
            CuadradoSeleccion(event);
        } else if (SelecMagic) {
            MagicSeleccion(event);
        } else if (SelecLapiz) {
            LapizSeleccion(event);
        } else if (zoomPressed) {
            zoom(event);
        }
        undoStack.push(HEXvec);
        update();
        lastCanvasWasSaved = true;
    }
}

/**
 * Evento para detectar cuando se libera el click del mouse
 * @param event
 */
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

/**
 * Evento para seguir el movimiento del mouse
 * @param event
 */
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(pressed) {
        if (lapiz) {
            PosX = event->pos().x();
            PosY = event->pos().y();
            PosY += 1;
            for (int i = 0; i < grosor; i++) {
                for (int j = 0; j < grosor; j++) {
                    HEXvec[PosX + j][PosY + i] = HEXColor;
                }
            }

        }
        if (borrador) {
            borrar(event);

        }
    }
    if(SelecLapiz){
        LapizSeleccion(event);
    }
    update();
}

/**
 * Imprime los puntos a la hora seleccionar una zona cuadrada
 * @param event
 */
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
    }
    update();
}

/**
 * pinta los puntos cuando se realiza la seleccion magica
 */
void MainWindow::MagicSeleccion(QMouseEvent *event) {
    PosX = event->pos().x();
    PosY = event->pos().y();
    BFS(HEXvec, PosX, PosY, "#bfbfbf");
}

/**
 * Pinta las zonas seleccionadas con lapiz
 * @param event
 */
void MainWindow::LapizSeleccion(QMouseEvent *event)
{
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
}

//#------------------------------------------- Metodos --------------------------------------------------------

/**
 * Rota la matriz a la derecha
 */
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

/**
 * Rota la matriz a la izquierda
 */
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

/**
 * Rota la matriz de forma vertical
 */
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

/**
 * Rota la matriz de forma horizontal
 */
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

/**
 * Crea una matriz del tamano dado por el usuario
 */
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

/**
 * Carga en la matriz una imagen dada por el usuario
 */
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

/**
 * Realiza zoomPressed en la esquina superior izquierda
 */
void MainWindow::zoom(QMouseEvent *event){
    PosX = event->pos().x();
    PosY = event->pos().y();
    vector<vector<std::string>> output;
    int numRows,numCols, zoom;
    numRows = HEXvec.size();
    numCols = HEXvec[0].size();
    int cantidadZoom = 4;

    output.resize(numRows);
    for(int i =0; i< numRows; i++){
        output[i].resize(numCols);
    }
    for(int srcRow =0 ; srcRow < numRows; srcRow += cantidadZoom) {
        for (int srcCol = 0; srcCol < numCols; srcCol += cantidadZoom) {
            string srcPixel = HEXvec[(srcRow/cantidadZoom) + PosX][(srcCol/cantidadZoom) + PosY];
            for(int k = 1; k < cantidadZoom; k++){
                for(int m = 0; m < cantidadZoom; m++) {
                    if (srcRow + k < numRows and srcCol + k < numCols) {
                        output[srcRow][srcCol] = srcPixel;
                        output[srcRow][srcCol + k] = srcPixel;
                        output[srcRow + k][srcCol] = srcPixel;
                        output[srcRow + k][srcCol + m] = srcPixel;
                    }
                }
            }
        }
    }
    HEXvec = output;
}

/**
 * Para verificar si un TextEdit se encuentra vacio
 * @param myTextEdit el TextEEdit que se desea verificar
 * @return
 */
bool IsTextEditEmpty(const QTextEdit * myTextEdit)
{
    return myTextEdit->document()->isEmpty();
}

//# ----------------------------------------- Apartado de Botones ---------------------------
/**
 * Desactiva todos los botones
 */
void MainWindow::deactivateAllButtons(){
    lapiz = false;
    lapicero = false;
    borrador = false;
    ColorPicker = false;
    zoomPressed  =false;

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
    undoStack.push(HEXvec);
    update();
}


void MainWindow::on_RotarIzq_clicked()
{
    rotateToTheLeft();
    undoStack.push(HEXvec);
    update();
}


void MainWindow::on_RotarVer_clicked()
{
    verticalRotation();
    undoStack.push(HEXvec);
    update();
}

void MainWindow::on_RotarHor_clicked()
{
    horizontalRotation();
    undoStack.push(HEXvec);
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

void MainWindow::on_zoom_clicked()
{
    deactivateAllButtons();
    zoomPressed = true;
}

/**
 * Vuelve falso que los botones de colores ayan sido seleccionados
 */
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

/**
 * Llama la funcion para crear el canvas
 */
void MainWindow::on_btnStart_clicked()
{
    if(!IsTextEditEmpty(reinterpret_cast<const QTextEdit *>(ui->plainTextGetHeight)) and !IsTextEditEmpty(reinterpret_cast<const QTextEdit *>(ui->plainTextEditGetWidth))) {
        createCanvas();
    }
    this->iniciarPaint = true;
    rotateToTheRight();
    undoStack.push(HEXvec);
    update();
    ui->frameInicio->hide();
    ui->framePrincipal->show();
    ui->frameSecundario->show();
}

/**
 * Llama la funcion para guardar el cavas en una imagen bmp
 */
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

/**
 * Actualiza el canvas a su version anterior
 */
void MainWindow::on_Undo_clicked()
{
    if(lastCanvasWasSaved) {
        undoStack.pop();
    }
    if(lapiceroWasJustUsed){
        undoStack.pop();
    }
    redoStack.push(HEXvec);
    HEXvec = undoStack.pop();
    update();
    lastCanvasWasSaved = false;
    lapiceroWasJustUsed = false;
}

/**
 * Actualiza el canvas a un cambio del undo
 */
void MainWindow::on_Redo_clicked()
{
    undoStack.push(HEXvec);
    HEXvec = redoStack.pop();
    update();
    lastCanvasWasSaved = false;
    lapiceroWasJustUsed = false;
}

/**
 * Llama la funcion para cargar una imagen
 */
void MainWindow::on_Cargar_clicked()
{
    loadImage();
    undoStack.push(HEXvec);
    update();
}

//#---------------------- Apartado de filtros -----------------------------------------------

/**
 * Coloca un filtro oscuro en el canvas
 */
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
    undoStack.push(HEXvec);
    update();
}

/**
 * Coloca un filtro de grises en el canvas
 */
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
    undoStack.push(HEXvec);
    update();
}

/**
 *Coloca un filtro de azules en el canvas
 */
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
    undoStack.push(HEXvec);
    update();
}

/**
 * Coloca un filtro raro en el canvas
 */
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
    undoStack.push(HEXvec);
    update();
}

//--------------------------------BFS--------------------------------------------------------------

/**
 * Cambia el color de la zona y color seleccionado
 * @param mat matriz en la que se realiza la busqueda
 * @param r posicion en x donde inicia la busqueda
 * @param c posicion en y donde inicia la busqueda
 * @param target Cambio de color que se desea hacer en la zona
 */
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

/**
 * Cambia el color de la zona seleccionada
 * @param mat matriz en la que se realiza la busqueda
 * @param r posicion en x donde inicia la busqueda
 * @param c posicion en y donde inicia la busqueda
 * @param target Cambio de color que se desea hacer en la zona
 */
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


