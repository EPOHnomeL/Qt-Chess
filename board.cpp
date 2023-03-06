#include "board.h"
using namespace std;

Board::Board()
{
  // Initalize variables
}

std::string Board::GetANotation()
{
  return this->ANotation;
}

void Board::AddMove(std::string m)
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
  // Print board as a string in console
}
