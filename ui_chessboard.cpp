#include "ui_chessboard.h"
#include "mygraphicsscene.h"
#include <QLayout>
#include <QPixmap>

UI_ChessBoard::UI_ChessBoard(QWidget *parent) : QWidget(parent)
{
    scene = new MyGraphicsScene();
    view = new QGraphicsView(this);
    layout = new QGridLayout(this);

    layout->addWidget(view);
    this->setLayout(layout);
    view->setScene(scene);
    ResetBoard();
    SetBoardInfo(false);


    QImage *image = new QImage(":res/chesspieces/a.png");
    QPixmap p = QPixmap::fromImage(*image).scaled(80,80,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QGraphicsPixmapItem *png = scene->addPixmap(p);
    png->setPos(118, 112);
    view->setFixedSize(803, 803);
    view->show();
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

void UI_ChessBoard::ResetBoard()
{
    scene->clear();
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            squares[i][j] = new QGraphicsRectItem(i * 100, j * 100, 100, 100);
            squares[i][j]->setBrush(QBrush(((i + j) % 2 == 0) ? QColor(238, 238, 210) : QColor(118, 150, 86)));
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
