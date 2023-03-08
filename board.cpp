#include "board.h"
using namespace std;

Board::Board(Player *w, Player *b)
{
    this->players[0] = w;
    this->players[1] = b;
}

QString Board::GetANotation()
{
  return this->ANotation;
}

void Board::AddMove(QString m)
{
  // put Algebriac notation
}

int Board::GetNameNumber()
{
  return this->moveNumber;
}

void Board::IncrementMoveNumber()
{
  this->moveNumber++;
}

void Board::PrintBoard()
{
  // Print board as a QString in console
}
