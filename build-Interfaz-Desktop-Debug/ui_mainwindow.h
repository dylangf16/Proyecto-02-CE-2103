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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *framePrincipal;
    QWidget *widget;
    QPushButton *ColorPicker;
    QPushButton *Borrador;
    QPushButton *Rotar;
    QTextEdit *textEdit;
    QPushButton *PaintFill;
    QPushButton *Lapicero;
    QPushButton *Lapiz;
    QPushButton *Seleccionar;
    QPushButton *Negativo;
    QPushButton *Grises;
    QPushButton *Cuadrado;
    QPushButton *Triangulo;
    QPushButton *Circulo;
    QFrame *frameInicio;
    QPlainTextEdit *plainTextGetHeight;
    QPlainTextEdit *plainTextEditGetWidth;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnStart;
    QPlainTextEdit *plainTextGetDir;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1153, 791);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        framePrincipal = new QFrame(centralwidget);
        framePrincipal->setObjectName(QString::fromUtf8("framePrincipal"));
        framePrincipal->setGeometry(QRect(0, 620, 611, 121));
        framePrincipal->setFrameShape(QFrame::StyledPanel);
        framePrincipal->setFrameShadow(QFrame::Raised);
        widget = new QWidget(framePrincipal);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 591, 101));
        ColorPicker = new QPushButton(widget);
        ColorPicker->setObjectName(QString::fromUtf8("ColorPicker"));
        ColorPicker->setGeometry(QRect(110, 40, 89, 25));
        Borrador = new QPushButton(widget);
        Borrador->setObjectName(QString::fromUtf8("Borrador"));
        Borrador->setGeometry(QRect(110, 10, 89, 25));
        Rotar = new QPushButton(widget);
        Rotar->setObjectName(QString::fromUtf8("Rotar"));
        Rotar->setGeometry(QRect(310, 40, 91, 25));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(310, 10, 101, 21));
        PaintFill = new QPushButton(widget);
        PaintFill->setObjectName(QString::fromUtf8("PaintFill"));
        PaintFill->setGeometry(QRect(210, 10, 89, 25));
        Lapicero = new QPushButton(widget);
        Lapicero->setObjectName(QString::fromUtf8("Lapicero"));
        Lapicero->setGeometry(QRect(10, 40, 89, 25));
        Lapiz = new QPushButton(widget);
        Lapiz->setObjectName(QString::fromUtf8("Lapiz"));
        Lapiz->setGeometry(QRect(10, 10, 89, 25));
        Seleccionar = new QPushButton(widget);
        Seleccionar->setObjectName(QString::fromUtf8("Seleccionar"));
        Seleccionar->setGeometry(QRect(210, 40, 89, 25));
        Negativo = new QPushButton(widget);
        Negativo->setObjectName(QString::fromUtf8("Negativo"));
        Negativo->setGeometry(QRect(10, 70, 89, 25));
        Grises = new QPushButton(widget);
        Grises->setObjectName(QString::fromUtf8("Grises"));
        Grises->setGeometry(QRect(110, 70, 89, 25));
        Cuadrado = new QPushButton(widget);
        Cuadrado->setObjectName(QString::fromUtf8("Cuadrado"));
        Cuadrado->setGeometry(QRect(210, 70, 89, 25));
        Triangulo = new QPushButton(widget);
        Triangulo->setObjectName(QString::fromUtf8("Triangulo"));
        Triangulo->setGeometry(QRect(310, 70, 89, 25));
        Circulo = new QPushButton(widget);
        Circulo->setObjectName(QString::fromUtf8("Circulo"));
        Circulo->setGeometry(QRect(410, 70, 89, 25));
        frameInicio = new QFrame(centralwidget);
        frameInicio->setObjectName(QString::fromUtf8("frameInicio"));
        frameInicio->setGeometry(QRect(210, 10, 491, 301));
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1153, 22));
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
        ColorPicker->setText(QApplication::translate("MainWindow", "Color-Picker", nullptr));
        Borrador->setText(QApplication::translate("MainWindow", "Borrador", nullptr));
        Rotar->setText(QApplication::translate("MainWindow", "Rotar", nullptr));
        PaintFill->setText(QApplication::translate("MainWindow", "PaintFill", nullptr));
        Lapicero->setText(QApplication::translate("MainWindow", "Lapicero", nullptr));
        Lapiz->setText(QApplication::translate("MainWindow", "Lapiz", nullptr));
        Seleccionar->setText(QApplication::translate("MainWindow", "Seleccionar", nullptr));
        Negativo->setText(QApplication::translate("MainWindow", "Negativo", nullptr));
        Grises->setText(QApplication::translate("MainWindow", "Grises", nullptr));
        Cuadrado->setText(QApplication::translate("MainWindow", "Cuadrado", nullptr));
        Triangulo->setText(QApplication::translate("MainWindow", "Triangulo", nullptr));
        Circulo->setText(QApplication::translate("MainWindow", "\"Circulo\"", nullptr));
        label->setText(QApplication::translate("MainWindow", "Inserte el tamano del canvas", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Height:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Width", nullptr));
        btnStart->setText(QApplication::translate("MainWindow", "Empezar", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "o escriba la direccion de la imagen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
