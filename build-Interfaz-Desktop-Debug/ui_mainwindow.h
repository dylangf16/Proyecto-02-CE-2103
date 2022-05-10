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
    QFrame *frameInicio;
    QPlainTextEdit *plainTextHeight;
    QPlainTextEdit *plainTextEditWidth;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnStart;
    QFrame *framePrincipal;
    QWidget *widget;
    QPushButton *ColorPicker;
    QPushButton *Borrador;
    QPushButton *PaintFill_3;
    QTextEdit *textEdit;
    QPushButton *PaintFill;
    QPushButton *Lapicero;
    QPushButton *Lapiz;
    QPushButton *PaintFill_2;
    QPushButton *Negativo;
    QPushButton *Grises;
    QPushButton *PaintFill_4;
    QPushButton *PaintFill_5;
    QPushButton *PaintFill_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1145, 789);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frameInicio = new QFrame(centralwidget);
        frameInicio->setObjectName(QString::fromUtf8("frameInicio"));
        frameInicio->setGeometry(QRect(250, 10, 491, 211));
        frameInicio->setFrameShape(QFrame::StyledPanel);
        frameInicio->setFrameShadow(QFrame::Raised);
        plainTextHeight = new QPlainTextEdit(frameInicio);
        plainTextHeight->setObjectName(QString::fromUtf8("plainTextHeight"));
        plainTextHeight->setGeometry(QRect(50, 100, 101, 31));
        plainTextHeight->setOverwriteMode(false);
        plainTextEditWidth = new QPlainTextEdit(frameInicio);
        plainTextEditWidth->setObjectName(QString::fromUtf8("plainTextEditWidth"));
        plainTextEditWidth->setGeometry(QRect(320, 100, 111, 31));
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
        btnStart->setGeometry(QRect(190, 150, 89, 25));
        framePrincipal = new QFrame(centralwidget);
        framePrincipal->setObjectName(QString::fromUtf8("framePrincipal"));
        framePrincipal->setGeometry(QRect(0, 620, 531, 121));
        framePrincipal->setFrameShape(QFrame::StyledPanel);
        framePrincipal->setFrameShadow(QFrame::Raised);
        widget = new QWidget(framePrincipal);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 521, 101));
        ColorPicker = new QPushButton(widget);
        ColorPicker->setObjectName(QString::fromUtf8("ColorPicker"));
        ColorPicker->setGeometry(QRect(110, 40, 89, 25));
        Borrador = new QPushButton(widget);
        Borrador->setObjectName(QString::fromUtf8("Borrador"));
        Borrador->setGeometry(QRect(110, 10, 89, 25));
        PaintFill_3 = new QPushButton(widget);
        PaintFill_3->setObjectName(QString::fromUtf8("PaintFill_3"));
        PaintFill_3->setGeometry(QRect(310, 40, 101, 25));
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
        PaintFill_2 = new QPushButton(widget);
        PaintFill_2->setObjectName(QString::fromUtf8("PaintFill_2"));
        PaintFill_2->setGeometry(QRect(210, 40, 89, 25));
        Negativo = new QPushButton(widget);
        Negativo->setObjectName(QString::fromUtf8("Negativo"));
        Negativo->setGeometry(QRect(10, 70, 89, 25));
        Grises = new QPushButton(widget);
        Grises->setObjectName(QString::fromUtf8("Grises"));
        Grises->setGeometry(QRect(110, 70, 89, 25));
        PaintFill_4 = new QPushButton(widget);
        PaintFill_4->setObjectName(QString::fromUtf8("PaintFill_4"));
        PaintFill_4->setGeometry(QRect(210, 70, 89, 25));
        PaintFill_5 = new QPushButton(widget);
        PaintFill_5->setObjectName(QString::fromUtf8("PaintFill_5"));
        PaintFill_5->setGeometry(QRect(310, 70, 101, 25));
        PaintFill_6 = new QPushButton(widget);
        PaintFill_6->setObjectName(QString::fromUtf8("PaintFill_6"));
        PaintFill_6->setGeometry(QRect(420, 70, 91, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1145, 22));
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
        ColorPicker->setText(QApplication::translate("MainWindow", "Color-Picker", nullptr));
        Borrador->setText(QApplication::translate("MainWindow", "Borrador", nullptr));
        PaintFill_3->setText(QApplication::translate("MainWindow", "Rotar", nullptr));
        PaintFill->setText(QApplication::translate("MainWindow", "PaintFill", nullptr));
        Lapicero->setText(QApplication::translate("MainWindow", "Lapicero", nullptr));
        Lapiz->setText(QApplication::translate("MainWindow", "Lapiz", nullptr));
        PaintFill_2->setText(QApplication::translate("MainWindow", "Seleccionar", nullptr));
        Negativo->setText(QApplication::translate("MainWindow", "Negativo", nullptr));
        Grises->setText(QApplication::translate("MainWindow", "Grises", nullptr));
        PaintFill_4->setText(QApplication::translate("MainWindow", "Cuadrado", nullptr));
        PaintFill_5->setText(QApplication::translate("MainWindow", "Triangulo", nullptr));
        PaintFill_6->setText(QApplication::translate("MainWindow", "C\303\255rculo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
