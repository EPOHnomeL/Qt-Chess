#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QPoint>
#include <QMouseEvent>
#include "piece.h"

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyGraphicsScene(QObject *parent = nullptr);
    ~MyGraphicsScene();

    const SquarePosition &getPos() const;

signals:
    void selectedSquareChanged(SquarePosition pos);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    SquarePosition pos;
};

#endif // MYGRAPHICSSCENE_H
