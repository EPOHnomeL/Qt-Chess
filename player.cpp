#include "player.h"
using namespace std;

Player::Player(QString playerName, bool isWhite)
{
  this->playerName = playerName;
  this->isWhite = isWhite;
}

QString Player::GetPiecesLost()
{
  return this->piecesLost;
}

QString Player::GetPreviousMoves()
{
  return this->previousMoves;
}

void Player::AddPreviousMoves(QString s)
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

const Select &Player::GetSelectTo() const
{
    return selectTo;
}

void Player::SetSelectTo(const Select &newSelectTo)
{
    selectTo = newSelectTo;
}

const Select &Player::GetSelectFrom() const
{
    return selectFrom;
}

void Player::SetSelectFrom(const Select &newSelectFrom)
{
    selectFrom = newSelectFrom;
}

bool Player::GetIsPlayerTurn() const
{
    return isPlayerTurn;
}

void Player::ToggleIsPlayerTurn()
{
    isPlayerTurn = !isPlayerTurn;
}

const QString &Player::GetPlayerName() const
{
    return playerName;
}

void Player::SetPlayerName(const QString &newPlayerName)
{
    playerName = newPlayerName;
}

