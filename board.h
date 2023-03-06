#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <string>

class Board
{
public:
    Board();
    std::string GetANotation();
    void MovePiece(Piece &from, Square to);
    int GetNameNumber();
    void IncrementMoveNumber();
    void PrintBoard();

private:
    void AddMove(std::string m);
    std::string boardstate[9][9];
    int moveNumber;
    std::string ANotation;
};

#endif // BOARD_H
