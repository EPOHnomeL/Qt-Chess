#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

struct Select
{
    int pos[2];
    QString pieceName;
};

class Player
{
public:
    explicit Player(QString playerName, bool isWhite);
    QString GetPiecesLost();
    QString GetPreviousMoves();
    void AddPreviousMoves(QString s);
    int GetScore();
    void IncreaseScore(int score);

    const Select &GetSelectTo() const;
    void SetSelectTo(const Select &newSelectTo);

    const Select &GetSelectFrom() const;
    void SetSelectFrom(const Select &newSelectFrom);

    bool GetIsPlayerTurn() const;
    void ToggleIsPlayerTurn();

    const QString &GetPlayerName() const;
    void SetPlayerName(const QString &newPlayerName);

private:
    bool isPlayerTurn;
    Select selectTo;
    Select selectFrom;
    QString playerName;
    QString piecesLost;
    QString previousMoves;
    bool isWhite;
    int score;
};

#endif // PLAYER_H
