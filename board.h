#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <string>
using namespace std;

struct BoardSquares
{
    Piece board[8][8];
};

class Board
{
public:
    Board();
    string GetANotation();
    void MovePiece(Piece from, Piece to);
    int GetNameNumber();
    void IncrementMoveNumber();
    void PrintBoard();

private:
    void AddMove(string m);
    BoardSquares boardstate;
    int moveNumber;
    string ANotation;
};

#endif // BOARD_H
