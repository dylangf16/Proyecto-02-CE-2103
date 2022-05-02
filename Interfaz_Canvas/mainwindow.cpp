#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QPixmap"
#include "QPainter"

bool lapicero = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    startPos = QPoint();
    endPos = QPoint();
    inDrawing = false;
    setMouseTracking(true);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//---------------------------------------------------------------------------------
//Lapicero
void MainWindow::on_Lapicero_clicked()
{
    lapicero = true;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        if (!inDrawing)
        {
            startPos = event->pos();
        }
        else
        {
            endPos = event->pos();

            QLine line = QLine(startPos, event->pos());
            lines.append(line);
        }

        inDrawing = !inDrawing;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (inDrawing)
    {
        endPos = event->pos();
        update();
    }
}
void MainWindow::drawLines(QPainter *p)
{
    if (!startPos.isNull() && !endPos.isNull())
    {
        p->drawLine(startPos, endPos);
    }

    p->drawLines(lines);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if (lapicero == true){
        QPainter p(this);
        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(4);
        p.setPen(pen);
        drawLines(&p);
    }

}
