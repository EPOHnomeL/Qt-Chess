#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicsscene.h"
#include <QPainter>
#include <QLayout>
#include <QGraphicsRectItem>
#include "chess.h"
#include "player.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Player *w = new Player("White", true);
    Player *b = new Player("Black", false);
    Chess *chessGame = new Chess(this, w, b);

    this->setCentralWidget(chessGame->getBoard()->getUi_chessboard());
}

MainWindow::~MainWindow()
{
    delete ui;
}
