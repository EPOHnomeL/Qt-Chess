#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
public:
    Player(string playerName, bool isWhite);
    string GetPiecesLost();
    string GetPreviousMoves();
    void AddPreviousMoves(string s);
    int GetScore();
    void IncreaseScore(int score);

private:
    string playerName;
    string piecesLost;
    string previousMoves;
    bool isWhite;
    int score;
};

#endif // PLAYER_H
