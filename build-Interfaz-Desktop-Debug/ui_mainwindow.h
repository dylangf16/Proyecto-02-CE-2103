/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frameInicio;
    QPlainTextEdit *plainTextGetHeight;
    QPlainTextEdit *plainTextEditGetWidth;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnStart;
    QPlainTextEdit *plainTextGetDir;
    QLabel *label_4;
    QFrame *framePrincipal;
    QWidget *widget;
    QPushButton *ColorPicker;
    QPushButton *Borrador;
    QPushButton *RotarDer;
    QPushButton *PaintFill;
    QPushButton *Lapicero;
    QPushButton *Lapiz;
    QPushButton *Seleccionar;
    QPushButton *Grises;
    QPushButton *Cuadrado;
    QPushButton *Triangulo;
    QPushButton *Circulo;
    QPlainTextEdit *plainTextGetName;
    QPushButton *Save;
    QPushButton *RotarIzq;
    QPushButton *RotarVer;
    QPushButton *RotarHor;
    QPushButton *Negativo;
    QLabel *label_5;
    QPushButton *SeleccionarGrosor;
    QPlainTextEdit *Grosor;
    QPushButton *Color1;
    QPushButton *Color2;
    QPushButton *Color3;
    QPushButton *Color4;
    QPushButton *Color5;
    QPushButton *Color7;
    QPushButton *Color6;
    QPushButton *Color8;
    QPushButton *Color12;
    QPushButton *Color9;
    QPushButton *Color11;
    QPushButton *Color10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1072, 757);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frameInicio = new QFrame(centralwidget);
        frameInicio->setObjectName(QString::fromUtf8("frameInicio"));
        frameInicio->setGeometry(QRect(140, 10, 491, 301));
        frameInicio->setFrameShape(QFrame::StyledPanel);
        frameInicio->setFrameShadow(QFrame::Raised);
        plainTextGetHeight = new QPlainTextEdit(frameInicio);
        plainTextGetHeight->setObjectName(QString::fromUtf8("plainTextGetHeight"));
        plainTextGetHeight->setGeometry(QRect(50, 100, 101, 31));
        plainTextGetHeight->setOverwriteMode(false);
        plainTextEditGetWidth = new QPlainTextEdit(frameInicio);
        plainTextEditGetWidth->setObjectName(QString::fromUtf8("plainTextEditGetWidth"));
        plainTextEditGetWidth->setGeometry(QRect(320, 100, 111, 31));
        label = new QLabel(frameInicio);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 30, 201, 17));
        label_2 = new QLabel(frameInicio);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 67, 17));
        label_3 = new QLabel(frameInicio);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 80, 67, 17));
        btnStart = new QPushButton(frameInicio);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(190, 230, 89, 25));
        plainTextGetDir = new QPlainTextEdit(frameInicio);
        plainTextGetDir->setObjectName(QString::fromUtf8("plainTextGetDir"));
        plainTextGetDir->setGeometry(QRect(140, 170, 181, 31));
        plainTextGetDir->setOverwriteMode(false);
        label_4 = new QLabel(frameInicio);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 140, 241, 17));
        framePrincipal = new QFrame(centralwidget);
        framePrincipal->setObjectName(QString::fromUtf8("framePrincipal"));
        framePrincipal->setGeometry(QRect(0, 0, 811, 171));
        framePrincipal->setFrameShape(QFrame::StyledPanel);
        framePrincipal->setFrameShadow(QFrame::Raised);
        widget = new QWidget(framePrincipal);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 801, 161));
        ColorPicker = new QPushButton(widget);
        ColorPicker->setObjectName(QString::fromUtf8("ColorPicker"));
        ColorPicker->setGeometry(QRect(0, 90, 89, 25));
        Borrador = new QPushButton(widget);
        Borrador->setObjectName(QString::fromUtf8("Borrador"));
        Borrador->setGeometry(QRect(0, 60, 89, 25));
        RotarDer = new QPushButton(widget);
        RotarDer->setObjectName(QString::fromUtf8("RotarDer"));
        RotarDer->setGeometry(QRect(300, 0, 121, 25));
        PaintFill = new QPushButton(widget);
        PaintFill->setObjectName(QString::fromUtf8("PaintFill"));
        PaintFill->setGeometry(QRect(100, 0, 89, 25));
        Lapicero = new QPushButton(widget);
        Lapicero->setObjectName(QString::fromUtf8("Lapicero"));
        Lapicero->setGeometry(QRect(0, 30, 89, 25));
        Lapiz = new QPushButton(widget);
        Lapiz->setObjectName(QString::fromUtf8("Lapiz"));
        Lapiz->setGeometry(QRect(0, 0, 89, 25));
        Seleccionar = new QPushButton(widget);
        Seleccionar->setObjectName(QString::fromUtf8("Seleccionar"));
        Seleccionar->setGeometry(QRect(100, 90, 89, 25));
        Grises = new QPushButton(widget);
        Grises->setObjectName(QString::fromUtf8("Grises"));
        Grises->setGeometry(QRect(100, 30, 89, 25));
        Cuadrado = new QPushButton(widget);
        Cuadrado->setObjectName(QString::fromUtf8("Cuadrado"));
        Cuadrado->setGeometry(QRect(200, 0, 89, 25));
        Triangulo = new QPushButton(widget);
        Triangulo->setObjectName(QString::fromUtf8("Triangulo"));
        Triangulo->setGeometry(QRect(200, 30, 89, 25));
        Circulo = new QPushButton(widget);
        Circulo->setObjectName(QString::fromUtf8("Circulo"));
        Circulo->setGeometry(QRect(200, 60, 89, 25));
        plainTextGetName = new QPlainTextEdit(widget);
        plainTextGetName->setObjectName(QString::fromUtf8("plainTextGetName"));
        plainTextGetName->setGeometry(QRect(630, 60, 151, 31));
        plainTextGetName->setOverwriteMode(false);
        Save = new QPushButton(widget);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(660, 100, 89, 25));
        RotarIzq = new QPushButton(widget);
        RotarIzq->setObjectName(QString::fromUtf8("RotarIzq"));
        RotarIzq->setGeometry(QRect(300, 60, 121, 25));
        RotarVer = new QPushButton(widget);
        RotarVer->setObjectName(QString::fromUtf8("RotarVer"));
        RotarVer->setGeometry(QRect(300, 30, 121, 25));
        RotarHor = new QPushButton(widget);
        RotarHor->setObjectName(QString::fromUtf8("RotarHor"));
        RotarHor->setGeometry(QRect(300, 90, 121, 25));
        Negativo = new QPushButton(widget);
        Negativo->setObjectName(QString::fromUtf8("Negativo"));
        Negativo->setGeometry(QRect(100, 60, 89, 25));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(430, 0, 111, 17));
        SeleccionarGrosor = new QPushButton(widget);
        SeleccionarGrosor->setObjectName(QString::fromUtf8("SeleccionarGrosor"));
        SeleccionarGrosor->setGeometry(QRect(430, 50, 111, 25));
        Grosor = new QPlainTextEdit(widget);
        Grosor->setObjectName(QString::fromUtf8("Grosor"));
        Grosor->setGeometry(QRect(430, 20, 111, 21));
        Color1 = new QPushButton(widget);
        Color1->setObjectName(QString::fromUtf8("Color1"));
        Color1->setGeometry(QRect(430, 80, 21, 21));
        Color2 = new QPushButton(widget);
        Color2->setObjectName(QString::fromUtf8("Color2"));
        Color2->setGeometry(QRect(460, 80, 21, 21));
        Color3 = new QPushButton(widget);
        Color3->setObjectName(QString::fromUtf8("Color3"));
        Color3->setGeometry(QRect(490, 80, 21, 21));
        Color4 = new QPushButton(widget);
        Color4->setObjectName(QString::fromUtf8("Color4"));
        Color4->setGeometry(QRect(520, 80, 21, 21));
        Color5 = new QPushButton(widget);
        Color5->setObjectName(QString::fromUtf8("Color5"));
        Color5->setGeometry(QRect(430, 110, 21, 21));
        Color7 = new QPushButton(widget);
        Color7->setObjectName(QString::fromUtf8("Color7"));
        Color7->setGeometry(QRect(490, 110, 21, 21));
        Color6 = new QPushButton(widget);
        Color6->setObjectName(QString::fromUtf8("Color6"));
        Color6->setGeometry(QRect(460, 110, 21, 21));
        Color8 = new QPushButton(widget);
        Color8->setObjectName(QString::fromUtf8("Color8"));
        Color8->setGeometry(QRect(520, 110, 21, 21));
        Color12 = new QPushButton(widget);
        Color12->setObjectName(QString::fromUtf8("Color12"));
        Color12->setGeometry(QRect(520, 140, 21, 21));
        Color9 = new QPushButton(widget);
        Color9->setObjectName(QString::fromUtf8("Color9"));
        Color9->setGeometry(QRect(430, 140, 21, 21));
        Color11 = new QPushButton(widget);
        Color11->setObjectName(QString::fromUtf8("Color11"));
        Color11->setGeometry(QRect(490, 140, 21, 21));
        Color10 = new QPushButton(widget);
        Color10->setObjectName(QString::fromUtf8("Color10"));
        Color10->setGeometry(QRect(460, 140, 21, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1072, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Inserte el tamano del canvas", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Height:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Width", nullptr));
        btnStart->setText(QApplication::translate("MainWindow", "Empezar", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "o escriba la direccion de la imagen", nullptr));
        ColorPicker->setText(QApplication::translate("MainWindow", "Color-Picker", nullptr));
        Borrador->setText(QApplication::translate("MainWindow", "Borrador", nullptr));
        RotarDer->setText(QApplication::translate("MainWindow", "Rotar Derecha", nullptr));
        PaintFill->setText(QApplication::translate("MainWindow", "PaintFill", nullptr));
        Lapicero->setText(QApplication::translate("MainWindow", "Lapicero", nullptr));
        Lapiz->setText(QApplication::translate("MainWindow", "Lapiz", nullptr));
        Seleccionar->setText(QApplication::translate("MainWindow", "Seleccionar", nullptr));
        Grises->setText(QApplication::translate("MainWindow", "Grises", nullptr));
        Cuadrado->setText(QApplication::translate("MainWindow", "Cuadrado", nullptr));
        Triangulo->setText(QApplication::translate("MainWindow", "Triangulo", nullptr));
        Circulo->setText(QApplication::translate("MainWindow", "\"Circulo\"", nullptr));
        Save->setText(QApplication::translate("MainWindow", "Guardar", nullptr));
        RotarIzq->setText(QApplication::translate("MainWindow", "Rotar Izquirda", nullptr));
        RotarVer->setText(QApplication::translate("MainWindow", "Rotar Vertical", nullptr));
        RotarHor->setText(QApplication::translate("MainWindow", "Rotar Horizontal", nullptr));
        Negativo->setText(QApplication::translate("MainWindow", "Negativo", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Grosor del pixel", nullptr));
        SeleccionarGrosor->setText(QApplication::translate("MainWindow", "Seleccionar", nullptr));
        Color1->setText(QString());
        Color2->setText(QString());
        Color3->setText(QString());
        Color4->setText(QString());
        Color5->setText(QString());
        Color7->setText(QString());
        Color6->setText(QString());
        Color8->setText(QString());
        Color12->setText(QString());
        Color9->setText(QString());
        Color11->setText(QString());
        Color10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
