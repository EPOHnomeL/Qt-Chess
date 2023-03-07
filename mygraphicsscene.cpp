#include "mygraphicsscene.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <string>
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
        int row = (-8+(int)mouseEvent->scenePos().y()/100)*-1;
        char col = (char)(1+(int)mouseEvent->scenePos().x()/100)+64;


        QMessageBox msgBox;
        msgBox.setText(QStringLiteral("%1 %2")
                       .arg(col)
                       .arg(row));
        msgBox.exec();
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}
