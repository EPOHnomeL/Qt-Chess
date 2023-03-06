#ifndef CHESS_H
#define CHESS_H

#include <string>

class Chess
{
public:
    explicit Chess(); // Player w, Player b);
    //    void TryMovePiece(Player player, Piece p, Piece to);
    bool GetGameFinished();
    std::string GetGameFinishedMessage();
    bool GetTurn();
    //    Board GetBoard();
    void NextTurn();

private:
    //    Player player[2];
    //    Board board;
    bool gameFinished;
    std::string gameFinishedMessage;
    bool whitesTurn;
};

#endif // CHESS_H
