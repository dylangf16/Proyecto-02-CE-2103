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
    QPushButton *Lapiz;
    QPushButton *Lapicero;
    QPushButton *Borrador;
    QPushButton *ColorPicker;
    QPushButton *PaintFill;
    QPushButton *PaintFill_2;
    QPushButton *PaintFill_3;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1124, 762);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Lapiz = new QPushButton(centralwidget);
        Lapiz->setObjectName(QString::fromUtf8("Lapiz"));
        Lapiz->setGeometry(QRect(10, 0, 89, 25));
        Lapicero = new QPushButton(centralwidget);
        Lapicero->setObjectName(QString::fromUtf8("Lapicero"));
        Lapicero->setGeometry(QRect(10, 30, 89, 25));
        Borrador = new QPushButton(centralwidget);
        Borrador->setObjectName(QString::fromUtf8("Borrador"));
        Borrador->setGeometry(QRect(110, 0, 89, 25));
        ColorPicker = new QPushButton(centralwidget);
        ColorPicker->setObjectName(QString::fromUtf8("ColorPicker"));
        ColorPicker->setGeometry(QRect(110, 30, 89, 25));
        PaintFill = new QPushButton(centralwidget);
        PaintFill->setObjectName(QString::fromUtf8("PaintFill"));
        PaintFill->setGeometry(QRect(210, 0, 89, 25));
        PaintFill_2 = new QPushButton(centralwidget);
        PaintFill_2->setObjectName(QString::fromUtf8("PaintFill_2"));
        PaintFill_2->setGeometry(QRect(210, 30, 89, 25));
        PaintFill_3 = new QPushButton(centralwidget);
        PaintFill_3->setObjectName(QString::fromUtf8("PaintFill_3"));
        PaintFill_3->setGeometry(QRect(310, 30, 101, 25));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(310, 0, 101, 21));
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
        Lapiz->setText(QApplication::translate("MainWindow", "Lapiz", nullptr));
        Lapicero->setText(QApplication::translate("MainWindow", "Lapicero", nullptr));
        Borrador->setText(QApplication::translate("MainWindow", "Borrador", nullptr));
        ColorPicker->setText(QApplication::translate("MainWindow", "Color-Picker", nullptr));
        PaintFill->setText(QApplication::translate("MainWindow", "PaintFill", nullptr));
        PaintFill_2->setText(QApplication::translate("MainWindow", "Seleccionar", nullptr));
        PaintFill_3->setText(QApplication::translate("MainWindow", "Rotar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
