#include "chess.h"

Chess::Chess(Player *w, Player *b)
{
    this->player[0] = w;
    this->player[1] = b;
    board = new Board(w, b);
    playerIdx = 0;
    ui_chessboard = new UI_ChessBoard();
}

void Chess::TryMovePiece(Player player, Piece p, Piece to)
{
    // Check board state, then check piece's valid moves then overlay on board (do not go out of bounds)
    // Then check context (my pieces, other pieces), then check for check, castling and en pessant.
    // If possible, check if it is a take, if it is increase score and player's lost pieces. Return true.
    // If not return false.
}

bool Chess::GetGameFinished()
{
    // If Mate or stalemate or resign or draw return true and set gameFinishedMessage.
    // else return false
    return false;
}

QString Chess::GetGameFinishedMessage()
{
    return gameFinishedMessage;
}

bool Chess::GetTurn()
{
    return whitesTurn;
}

Board Chess::GetBoard()
{
    return *board;
}

void Chess::NextTurn()
{
    whitesTurn = !whitesTurn;
}

Player *Chess::GetCurrentPlayer()
{
    return player[playerIdx];
}
