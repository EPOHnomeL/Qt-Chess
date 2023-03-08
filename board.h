#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "player.h"
#include <QString>

enum pieces
{
    empty,
    w_pawn,
    w_rook,
    w_bishop,
    w_knight,
    w_queen,
    w_king,
    b_pawn,
    b_rook,
    b_bishop,
    b_knight,
    b_queen,
    b_king,
};

class Board
{
public:
    Board(Player *w, Player *b);
    QString GetANotation();
    void MovePiece(Piece &from, SquarePosition to);
    int GetNameNumber();
    void IncrementMoveNumber();
    void PrintBoard();

private:
    Player *players[2];
    void AddMove(QString m);
    int boardstate[8][8];
    int moveNumber;
    QString ANotation;
};

#endif // BOARD_H
