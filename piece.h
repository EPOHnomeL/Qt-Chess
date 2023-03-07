#ifndef PIECE_H
#define PIECE_H

#include <string>

struct BoardSquares;
struct SquarePosition
{
    int row, col;
};

class Piece
{
public:
    Piece();
    virtual BoardSquares GetValidMoves();
    SquarePosition GetPosition();
    int GetScore();
    // GetModel(): Image
private:
    std::string pieceName;
    bool isOwnerWhite;
    int score;
    SquarePosition pos;
    // Image model
};

struct BoardSquares
{
    SquarePosition board[8][8];
};

#endif // PIECE_H
