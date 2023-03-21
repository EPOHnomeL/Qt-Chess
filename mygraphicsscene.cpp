#include "mygraphicsscene.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QString>

MyGraphicsScene::MyGraphicsScene(QObject *parent) : QGraphicsScene(parent)
{

}

MyGraphicsScene::~MyGraphicsScene()
{
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if (mouseEvent->button() == Qt::LeftButton)
    {
        int irow = (-8 + (int)mouseEvent->scenePos().y() / 100) * -1;
        int icol = 1 + (int)mouseEvent->scenePos().x() / 100;
        char ccol = (char)(1 + (int)mouseEvent->scenePos().x() / 100) + 64;

        emit MyGraphicsScene::selectedSquareChanged({irow, icol});

        // send signals out to select square.
        QMessageBox msgBox;
        msgBox.setText(QStringLiteral("%1 %2")
                           .arg(ccol)
                           .arg(irow));
        msgBox.exec();
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}


