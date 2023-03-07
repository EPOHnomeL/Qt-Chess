#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyGraphicsScene(QObject *parent = nullptr);
      ~MyGraphicsScene();

signals:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // MYGRAPHICSSCENE_H
