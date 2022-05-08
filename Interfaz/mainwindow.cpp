#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QMouseEvent>
#include <QPainter>
#include <stdlib.h>

const int MAXPOINTS = 2000;                     // maximum number of points
const int MAXCOLORS = 40;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;
    down = false;
    points = new QPoint[MAXPOINTS];
    colors = new QColor[MAXCOLORS];
    for ( int i=0; i<MAXCOLORS; i++ ) // init color array
        colors[i] = QColor( rand()&255, rand()&255, rand()&255 );
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] points; // cleanup
    delete[] colors;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint( this );
        for ( int i=0; i<count-1; i++ ) {   // connect all points
            for ( int j=i+1; j<count; j++ ) {
                paint.setPen(Qt::black); // set random pen color
                paint.drawLine( points[i], points[j] ); // draw line
            }
        }
}

void MainWindow::mousePressEvent(QMouseEvent *)
{
    down = true;
    count = 0;  // start recording points
    //erase();    // erase widget contents
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    down = false; // done recording points
    update();    // draw the lines
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if ( down && count < MAXPOINTS ) {
            QPainter paint( this );
            points[count++] = e->pos(); // add point
            paint.drawPoint( e->pos() ); // plot point
        }
}


