#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.moc"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    QColor color;
    bool pressed;
    delete ui;
}

void MainWindow::MousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton)
        color = color == Qt::black ? Qt::white : Qt::black;
    else {
        pressed = 1;
        Draw(e);
    }
}

void MainWindow::MouseRealeaseEvent(QMouseEvent *e)
{
    pressed = 0;
}

void MainWindow::Draw(QMouseEvent *e)
{
    if (pressed) {
        QPainter painter(this);
        painter.setPen(color);
        int x = e->pos().x() / 12;
        int y = e->pos().y() / 12;
        painter.drawPoint(x, y);
        repaint();
    }
}

void MainWindow::MouseMoveEvent(QMouseEvent *e)
{
    Draw(e);
}

/*

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0) : QWidget(parent), pressed(0) {
        color = Qt::black;
        pixmap = new QPixmap("h:/small.png");
        resize(240, 240);
    }
    ~Widget() { if (pixmap) delete pixmap; }

protected:
    void paintEvent(QPaintEvent *) {
        QPainter painter(this);
        painter.drawPixmap(0, 0, pixmap->scaled(240, 240));
        painter.drawPixmap(0, 0, *pixmap);
    }

    void mousePressEvent(QMouseEvent *e) {
        if (e->button() == Qt::RightButton)
            color = color == Qt::black ? Qt::white : Qt::black;
        else {
            pressed = 1;
            draw(e);
        }
    }

    void mouseReleaseEvent(QMouseEvent *) { pressed = 0; }
    void mouseMoveEvent(QMouseEvent *e) { draw(e); }

private:
    void draw(QMouseEvent *e) {
        if (pressed) {
            QPainter painter(pixmap);
            painter.setPen(color);
            int x = e->pos().x() / 12;
            int y = e->pos().y() / 12;
            painter.drawPoint(x, y);
            repaint();
        }
    }

    QColor color;
    QPixmap *pixmap;
    bool pressed;
};
*/
