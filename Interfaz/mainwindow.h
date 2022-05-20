#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMouseEvent>
#include <QWidget>
#include <vector>
#include <queue>
#include <iomanip>
#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void createCanvas();
    void loadImage();
    void rotateToTheRight();
    void rotateToTheLeft();
    void verticalRotation();
    void horizontalRotation();
    void conversionHEXtoRGB(std::string HEXvalue);
    void borrar(QMouseEvent *event);
    void pintarConLapiz(QMouseEvent *event);
    void pintarConLapicero(QMouseEvent *event, int, int, int, int, int, int, int);
    void pickColor(QMouseEvent *event);
    void dibujarCuadrado(QMouseEvent *event);
    void dibujarTriangulo(QMouseEvent *event);
    void dibujarCirculo(QMouseEvent *event);
    void deactivateAllButtons();
    void deactivateAllColors();
    void PaintFill(QMouseEvent *event);
    void BFS(vector<vector<std::string>> &mat, int x, int y, std::string replacement);
    void BFSSeleccionLapiz(vector<vector<std::string>> &mat, int r, int c, std::string replacement);
    void CuadradoSeleccion(QMouseEvent *event);
    void MagicSeleccion(QMouseEvent *event);
    void LapizSeleccion(QMouseEvent *event);


private slots:
    void on_Lapiz_clicked();

    void on_Borrador_clicked();

    void on_Lapicero_clicked();

    void on_btnStart_clicked();

    void on_Negativo_clicked();

    void on_Grises_clicked();

    void on_ColorPicker_clicked();

    void on_Cuadrado_clicked();

    void on_Triangulo_clicked();

    void on_Circulo_clicked();

    void on_Save_clicked();

    void on_RotarDer_clicked();

    void on_RotarIzq_clicked();

    void on_RotarVer_clicked();

    void on_RotarHor_clicked();

    void on_SeleccionarGrosor_clicked();

    void on_Color1_clicked();

    void on_Color2_clicked();

    void on_Color3_clicked();

    void on_Color4_clicked();

    void on_Color5_clicked();

    void on_Color6_clicked();

    void on_Color7_clicked();

    void on_Color8_clicked();

    void on_Color9_clicked();

    void on_Color10_clicked();

    void on_Color11_clicked();

    void on_Color12_clicked();

    void on_Undo_clicked();

    void on_Redo_clicked();

    void on_FiltroAzules_clicked();

    void on_FiltroRaro_clicked();

    void on_PaintFill_clicked();

    void on_SeleccionarLapiz_clicked();

    void on_SeleccionarCuadrado_clicked();

    void on_SeleccionarMagico_clicked();

    void on_zoom_clicked();

    void on_Cargar_clicked();

private:
    Ui::MainWindow *ui;
    QColor color;
    bool pressed = false, lapiz = false, lapicero = false, borrador = false, ColorPicker = false;
    bool cuadrado = false, triangulo = false, circulo = false;
    int PosX,PosY, LapiceroX1 = 0, LapiceroY1 = 0, grosor = 15, SelecPosX1, SelecPosY1, SelecPosX2, SelecPosY2;
    int canvasHeight, canvasWidth;
    int RED, GREEN, BLUE;
    bool iniciarPaint, Color1Pressed = false, Color2Pressed = false, Color3Pressed = false, Color4Pressed = false, Color5Pressed = false, Color6Pressed = false, Color7Pressed = false, Color8Pressed = false, Color9Pressed = false, Color10Pressed = false, Color11Pressed = false, Color12Pressed = false;
    bool LapiceroClicked1 = false, LapiceroClicked2 = false, Fill = false, SelecCuadrado1 = false, SelecCuadrado2 = false, SelecCuadrado = false, SelecLapiz = false, SelecMagic = false;
    std:: string Color1 = "#ff0000", Color2 = "#ff7300", Color3 = "#ffff00", Color4 = "#55ff00", Color5 = "#00ffe5", Color6 = "#0037ff", Color7 = "#7300ff", Color8 = "#d900ff", Color9 = "#2bff00", Color10 = "#000000", Color11 = "#ffffff", Color12 = "#424242";
    std::vector<QPoint> puntos;
    vector<vector<std::string>> SelecPuntos;
    int row[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int col[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };


};
#endif // MAINWINDOW_H
