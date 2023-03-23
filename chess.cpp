#include "chess.h"

Chess::Chess(QObject *parent, Player *w, Player *b) : QObject(parent)
{
    this->player[0] = w;
    this->player[1] = b;
    board = new Board(this, w, b);
    this->whitesTurn = true;
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
