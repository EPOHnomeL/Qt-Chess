#ifndef CHESS_H
#define CHESS_H

#include <QString>
#include "player.h"
#include "board.h"


class Chess: public QObject
{
    Q_OBJECT
public:
    explicit Chess(QObject *parent = nullptr, Player *w = nullptr, Player *b = nullptr);
    void TryMovePiece(Player player, Piece p, Piece to);
    bool getGameFinished();
    QString getGameFinishedMessage();
    bool getTurn();
    void NextTurn();
    Player *getCurrentPlayer();


    Board *getBoard() const;

private:
    Player *player[2];
    Board *board;
    bool gameFinished;
    QString gameFinishedMessage;
    bool whitesTurn;
};

#endif // CHESS_H
