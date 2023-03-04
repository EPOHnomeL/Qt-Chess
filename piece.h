#ifndef PIECE_H
#define PIECE_H

#include "board.h";
#include <string>;
using namespace std;

struct pos
{
    int x, y;
};

class Piece
{
public:
    Piece();
    Board GetValidMoves();
    void SetPostion(Piece p);
    pos GetPosition();
    int GetScore();
    // GetModel(): Image
private:
    string pieceName;
    bool isOwnerWhite;
    int score;
    pos pos;
    // Image model
};

#endif // PIECE_H
