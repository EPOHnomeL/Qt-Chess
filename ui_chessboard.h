#ifndef UI_CHESSBOARD_H
#define UI_CHESSBOARD_H

#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class UI_ChessBoard : public QWidget
{
    Q_OBJECT
public:
    explicit UI_ChessBoard(QWidget *parent = nullptr);
    void SetBoardInfo(bool b);
    void ClearBoard();
    QGraphicsItem* PutPieceAt(QString resName, int row, int col);
    void ResetBoard();
signals:

private:
    QLayout *layout;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsRectItem *squares[8][8];
    QGraphicsTextItem *text[8][2];
};

#endif // UI_CHESSBOARD_H
