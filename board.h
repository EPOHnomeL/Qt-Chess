#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "player.h"
#include <QString>
#include <QObject>
#include "ui_chessboard.h"
#include "mygraphicsscene.h"

enum pieces
{
    empty,
    w_pawn,
    w_rook,
    w_bishop,
    w_knight,
    w_queen,
    w_king,
    b_pawn,
    b_rook,
    b_bishop,
    b_knight,
    b_queen,
    b_king,
};

const QString sStarting[2][2][8] = {
    {{"pawn", "pawn", "pawn", "pawn", "pawn", "pawn", "pawn", "pawn"},
     {"rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"}},
    {{"rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"},
     {"pawn", "pawn", "pawn", "pawn", "pawn", "pawn", "pawn", "pawn"}}};

const int starting[8][8] = {
    {b_rook, b_knight, b_bishop, b_queen, b_king, b_bishop, b_knight, b_rook},
    {
        b_pawn,
        b_pawn,
        b_pawn,
        b_pawn,
        b_pawn,
        b_pawn,
        b_pawn,
        b_pawn,
    },
    {empty, empty, empty, empty, empty, empty, empty, empty},
    {empty, empty, empty, empty, empty, empty, empty, empty},
    {empty, empty, empty, empty, empty, empty, empty, empty},
    {empty, empty, empty, empty, empty, empty, empty, empty},
    {w_pawn, w_pawn, w_pawn, w_pawn, w_pawn, w_pawn, w_pawn, w_pawn},
    {w_rook, w_knight, w_bishop, w_queen, w_king, w_bishop, w_knight, w_rook}};

class Board: public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = nullptr, Player *w = nullptr, Player *b = nullptr);
    QString GetANotation();
    void MovePiece(Piece &from, SquarePosition to);
    int GetNameNumber();
    void IncrementMoveNumber();
    void PrintBoard();
    UI_ChessBoard *getUi_chessboard() const;

private slots:
    void selectedSquareChanged(SquarePosition pos);

private:
    SquarePosition secondSelectedSquare;
    SquarePosition firstSelectedSquare;
    UI_ChessBoard *ui_chessboard;
    Player *players[2];
    void AddMove(QString m);
    int boardstate[8][8];
    int moveNumber;
    QString ANotation;
};

#endif // BOARD_H
