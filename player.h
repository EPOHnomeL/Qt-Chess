#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player(std::string playerName, bool isWhite);
    std::string GetPiecesLost();
    std::string GetPreviousMoves();
    void AddPreviousMoves(std::string s);
    int GetScore();
    void IncreaseScore(int score);

private:
    std::string playerName;
    std::string piecesLost;
    std::string previousMoves;
    bool isWhite;
    int score;
};

#endif // PLAYER_H
