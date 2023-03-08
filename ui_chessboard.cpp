#include "ui_chessboard.h"
#include "mygraphicsscene.h"
#include <QLayout>
#include <QPixmap>

const QString starting[2][2][8] = {
    {{"pawn", "pawn", "pawn", "pawn", "pawn", "pawn", "pawn", "pawn"},
     {"rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"}},
    {{"rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"},
     {"pawn", "pawn", "pawn", "pawn", "pawn", "pawn", "pawn", "pawn"}}};

UI_ChessBoard::UI_ChessBoard(QWidget *parent) : QWidget(parent)
{
    scene = new MyGraphicsScene();
    view = new QGraphicsView(this);
    layout = new QGridLayout(this);
    label = new QLabel(this);

    layout->addWidget(view);
    layout->addWidget(label);

    this->setLayout(layout);
    view->setScene(scene);

    ResetBoard();
    SetBoardInfo(false);
    SetInfoText("Hello");
    view->setFixedSize(803, 803);
    view->show();
}

QGraphicsItem *UI_ChessBoard::PutPieceAt(QString resName, int row, int col)
{
    QImage *image = new QImage(":res/chesspieces/" + resName + ".png");
    QPixmap p = QPixmap::fromImage(*image).scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QGraphicsPixmapItem *png = scene->addPixmap(p); // Add pointer to array
    png->setPos(17 + (row * 100), 13 + (col * 100));
    return png;
}

void UI_ChessBoard::ResetBoard()
{
    ClearBoard();
    int row = 0;
    for (int color = 0; color < 2; ++color)
    {
        row = color == 0 ? 1 : 7;
        QString c = color == 1 ? "w" : "b";
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {

                QString resName = c + "_" + starting[color][i][j];
                PutPieceAt(resName, j, row-i);
            }
        }
    }

}

void UI_ChessBoard::SetBoardInfo(bool b)
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            b ? text[j][i]->show() : text[j][i]->hide();
        }
    }
}

void UI_ChessBoard::SetInfoText(QString s)
{
    label->setText(s);
}

void UI_ChessBoard::ClearBoard()
{
    scene->clear();
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            squares[i][j] = new QGraphicsRectItem(i * 100, j * 100, 100, 100);
            squares[i][j]->setPen(Qt::NoPen);
            squares[i][j]->setBrush(QBrush(((i + j) % 2 == 0) ? QColor(121, 72, 57) : QColor(93, 50, 49)));
            scene->addItem(squares[i][j]);
            if (j == 0)
            {

                text[i][0] = scene->addText(QString::number(8 - i));
                text[i][0]->setPos(2, 100 * (i));
            }
        }
        if (i == 7)
        {
            for (int k = 0; k < 8; ++k)
            {
                text[k][1] = scene->addText(QString(QChar(k + 65)));
                text[k][1]->setPos(100 * (k) + 3, 100 * i + 79);
            }
        }
    }
}
