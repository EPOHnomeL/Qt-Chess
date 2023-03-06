#include "piece.h"
#include "board.h"

Piece::Piece()
{
}

Square Piece::GetPosition()
{
    return {0, 0};
}

int Piece::GetScore()
{
    return 0;
}

BoardSquares Piece::GetValidMoves()
{ };

// Piece::GetModel();
