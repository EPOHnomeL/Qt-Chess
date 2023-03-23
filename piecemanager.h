#ifndef PIECEMANAGER_H
#define PIECEMANAGER_H

#include <QString>

struct SquarePosition
{
    int row, col;
};

struct Map{
    int *map[8][8];
};

class PieceManager
{
public:
    PieceManager();
    Map GetValidMoves(int piece, SquarePosition pos);

private:

};

#endif // PIECEMANAGER_H
