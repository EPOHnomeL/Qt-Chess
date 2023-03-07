#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicsscene.h"
#include <QPainter>
#include <QGraphicsRectItem>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new MyGraphicsScene();
    ui->graphView->setScene(scene);
    QGraphicsRectItem *squares[8][8];
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            squares[i][j] = new QGraphicsRectItem(i * 100, j * 100, 100, 100);
            squares[i][j]->setBrush(QBrush(((i + j) % 2 == 0) ? QColor(238, 238, 210) : QColor(118, 150, 86)));
            scene->addItem(squares[i][j]);
        }
    }
     ui->graphView->setFixedSize(803,803);
}

MainWindow::~MainWindow()
{
    delete ui;
}
