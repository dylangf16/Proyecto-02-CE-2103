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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *ColorPicker;
    QPushButton *Borrador;
    QPushButton *PaintFill_3;
    QTextEdit *textEdit;
    QPushButton *PaintFill;
    QPushButton *Lapicero;
    QPushButton *Lapiz;
    QPushButton *PaintFill_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1124, 725);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 0, 1111, 80));
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1124, 22));
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
        PaintFill_3->setText(QApplication::translate("MainWindow", "Rotar", nullptr));
        PaintFill->setText(QApplication::translate("MainWindow", "PaintFill", nullptr));
        Lapicero->setText(QApplication::translate("MainWindow", "Lapicero", nullptr));
        Lapiz->setText(QApplication::translate("MainWindow", "Lapiz", nullptr));
        PaintFill_2->setText(QApplication::translate("MainWindow", "Seleccionar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
