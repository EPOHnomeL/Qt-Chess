#ifndef PIECE_H
#define PIECE_H

#include <string>

struct BoardSquares;
struct Square
{
    int x, y;
};

class Piece
{
public:
    Piece();
    virtual BoardSquares GetValidMoves();
    Square GetPosition();
    int GetScore();
    // GetModel(): Image
private:
    std::string pieceName;
    bool isOwnerWhite;
    int score;
    Square pos;
    // Image model
};

struct BoardSquares
{
    Square board[8][8];
};

#endif // PIECE_H
