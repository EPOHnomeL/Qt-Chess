#include "player.h"
using namespace std;

Player::Player(string playerName, bool isWhite)
{
  this->playerName = playerName;
  this->isWhite = isWhite;
}

string Player::GetPiecesLost()
{
  return this->piecesLost;
}

string Player::GetPreviousMoves()
{
  return this->previousMoves;
}

void Player::AddPreviousMoves(string s)
{
  this->previousMoves = this->previousMoves + '-' + s;
}

int Player::GetScore()
{
  return this->score;
}

void Player::IncreaseScore(int score)
{
  this->score += score;
}
