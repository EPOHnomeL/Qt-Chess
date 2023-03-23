#ifndef BOARD_H
#define BOARD_H

#include "piecemanager.h"
#include "player.h"
#include <QString>
#include <QObject>
#include "ui_chessboard.h"
#include "mygraphicsscene.h"

enum pieces
{
    empty,
    w_pawn,
    b_pawn,
    w_rook,
    b_rook,
    w_bishop,
    b_bishop,
    w_knight,
    b_knight,
    w_queen,
    b_queen,
    w_king,
    b_king,
    valid
};

const QString piecesNames[14] = {
    "empty",
    "w_pawn",
    "b_pawn",
    "w_rook",
    "b_rook",
    "w_bishop",
    "b_bishop",
    "w_knight",
    "b_knight",
    "w_queen",
    "b_queen",
    "w_king",
    "b_king",
    "valid"};

const int starting[8][8] = {
    {b_rook, b_knight, b_bishop, b_queen, b_king, b_bishop, b_knight, b_rook},
    {b_pawn, b_pawn, b_pawn, b_pawn, b_pawn, b_pawn, b_pawn, b_pawn},
    {empty, empty, empty, empty, empty, empty, empty, empty},
    {empty, empty, empty, empty, empty, empty, empty, empty},
    {empty, empty, empty, empty, empty, empty, empty, empty},
    {empty, empty, empty, empty, empty, empty, empty, empty},
    {w_pawn, w_pawn, w_pawn, w_pawn, w_pawn, w_pawn, w_pawn, w_pawn},
    {w_rook, w_knight, w_bishop, w_queen, w_king, w_bishop, w_knight, w_rook}};

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr, Player *w = nullptr, Player *b = nullptr);
    QString GetANotation();
    int GetNameNumber();
    void IncrementMoveNumber();
    void PrintBoard();
    UI_ChessBoard *getUi_chessboard() const;

public slots:
    void selectedSquareChanged(SquarePosition pos);

signals:
    void change();

private:
    PieceManager *pm;
    SquarePosition selectedSquare;
    UI_ChessBoard *ui_chessboard;
    Player *players[2];
    void InitBoardState();
    void PrintBoardState();
    int *boardstate[8][8];
    bool isWhitesTurn;
    int moveNumber;
    QString ANotation;
};

#endif // BOARD_H
