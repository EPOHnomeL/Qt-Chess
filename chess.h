#ifndef CHESS_H
#define CHESS_H

#include <QString>
#include "player.h"
#include "board.h"
#include "ui_chessboard.h"

class Chess
{
public:
    Chess(Player *w, Player *b);
    void TryMovePiece(Player player, Piece p, Piece to);
    bool GetGameFinished();
    QString GetGameFinishedMessage();
    bool GetTurn();
    Board GetBoard();
    void NextTurn();
    Player *GetCurrentPlayer();
    UI_ChessBoard *ui_chessboard;

private:
    int playerIdx;
    Player *player[2];
    Board *board;
    bool gameFinished;
    QString gameFinishedMessage;
    bool whitesTurn;
};

#endif // CHESS_H
