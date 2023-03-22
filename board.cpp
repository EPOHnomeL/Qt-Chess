
#include "board.h"
#include <QMessageBox>
#include <iostream>
using namespace std;

Board::Board(QObject *parent, Player *w, Player *b) : QObject(parent)
{
    this->players[0] = w;
    this->players[1] = b;
    isWhitesTurn = true;
    selectedSquare = {-1, -1};
    ui_chessboard = new UI_ChessBoard();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            boardstate[i][j] = new int;
            *boardstate[i][j] = 0;
        }
    }
    InitBoardState();
    connect(ui_chessboard->getScene(),
            (&MyGraphicsScene::selectedSquareChanged),
            this,
            (&Board::selectedSquareChanged));
}

QString Board::GetANotation()
{
    return this->ANotation;
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
    if ((*boardstate[pos.row][pos.col] == 0 && selectedSquare.row == -1) || (selectedSquare.row == pos.row && selectedSquare.col == pos.col))
    {
        return;
    }

    if ((selectedSquare.col == -1) && (selectedSquare.row == -1))
    {
        selectedSquare = pos;
        ui_chessboard->toggleSquareActive(pos.row, pos.col);
        // Show valid Moves on UI
    }
    else
    {
        ui_chessboard->RemovePieceAt(pos.row, pos.col);
        // Check if valid move then move or not
        ui_chessboard->toggleSquareActive(selectedSquare.row, selectedSquare.col);
        const int iPiece = *boardstate[selectedSquare.row][selectedSquare.col];
        // Check
        *boardstate[pos.row][pos.col] = iPiece;
        *boardstate[selectedSquare.row][selectedSquare.col] = 0;
        ui_chessboard->PutPieceAt(piecesNames[iPiece], pos.col, pos.row);
        ui_chessboard->RemovePieceAt(selectedSquare.row, selectedSquare.col);
        selectedSquare = {-1, -1};
    }
}

void Board::InitBoardState()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            *boardstate[i][j] = starting[i][j];
            cout << *boardstate[i][j] << " ";
        }
        cout << endl;
    }
}
