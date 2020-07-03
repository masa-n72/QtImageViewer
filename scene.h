#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
