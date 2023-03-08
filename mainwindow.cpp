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
    Chess *chessGame = new Chess(w, b);

    this->setCentralWidget(chessGame->ui_chessboard);

    ui->label->setText(chessGame->GetCurrentPlayer()->GetPlayerName()+"'s turn");
}

MainWindow::~MainWindow()
{
    delete ui;
}
