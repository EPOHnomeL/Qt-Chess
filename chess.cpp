#include "chess.h"

Chess::Chess(QObject *parent, Player *w, Player *b) : QObject(parent)
{
    this->player[0] = w;
    this->player[1] = b;
    board = new Board(this, w, b);
    this->whitesTurn = true;
}

void Chess::TryMovePiece(Player player, Piece p, Piece to)
{
    // Check board state, then check piece's valid moves then overlay on board (do not go out of bounds)
    // Then check context (my pieces, other pieces), then check for check, castling and en pessant.
    // If possible, check if it is a take, if it is increase score and player's lost pieces. Return true.
    // If not return false.
}

bool Chess::getGameFinished()
{
    // If Mate or stalemate or resign or draw return true and set gameFinishedMessage.
    // else return false
    return false;
}

QString Chess::getGameFinishedMessage()
{
    return gameFinishedMessage;
}

bool Chess::getTurn()
{
    return whitesTurn;
}

void Chess::NextTurn()
{
    whitesTurn = !whitesTurn;
}

Player *Chess::getCurrentPlayer()
{
    return player[(int)!whitesTurn];
}

Board *Chess::getBoard() const
{
    return board;
}
