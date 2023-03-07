#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicsscene.h"
#include <QPainter>
#include <QLayout>
#include <QGraphicsRectItem>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cb = new UI_ChessBoard();
    this->setCentralWidget(cb);
    cb->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
