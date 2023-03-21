
#include "board.h"
#include <QMessageBox>
using namespace std;

Board::Board(QObject *parent, Player *w, Player *b) : QObject(parent)
{
    this->players[0] = w;
    this->players[1] = b;
    firstSelectedSquare = {-1, -1};
    secondSelectedSquare = {-1, -1};
    ui_chessboard = new UI_ChessBoard();
    QObject::connect(
                ui_chessboard->getScene(),
                SIGNAL(&MyGraphicsScene::selectedSquareChanged),
                this,
                SLOT(&Board::selectedSquareChanged));
}

QString Board::GetANotation()
{
    return this->ANotation;
}

void Board::AddMove(QString m)
{
    // put Algebriac notation
}

int Board::GetNameNumber()
{
    return this->moveNumber;
}

void Board::IncrementMoveNumber()
{
    this->moveNumber++;
}

void Board::PrintBoard()
{
    // Print board as a QString in console
}

UI_ChessBoard *Board::getUi_chessboard() const
{
    return ui_chessboard;
}

void Board::selectedSquareChanged(SquarePosition pos)
{
    QMessageBox msgBox;
    msgBox.setText(QStringLiteral("Hi"));
    msgBox.exec();

    if((firstSelectedSquare.col == -1) &&(firstSelectedSquare.row == -1)){
        firstSelectedSquare = pos;
        ui_chessboard->toggleSquareActive(pos.row, pos.col);
    } else{
        if((secondSelectedSquare.col == -1) &&(secondSelectedSquare.row == -1)){
            secondSelectedSquare = pos;
            ui_chessboard->toggleSquareActive(pos.row, pos.col);
            // Check and Move actual piece
        } else{
            firstSelectedSquare = {-1, -1};
            secondSelectedSquare = {-1, -1};
            ui_chessboard->toggleSquareActive(firstSelectedSquare.row, firstSelectedSquare.col);
            ui_chessboard->toggleSquareActive(secondSelectedSquare.row, secondSelectedSquare.col);
        }
    }

}
