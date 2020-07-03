#include "scene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
Scene::Scene()
{

}

/**
 * @brief mouse押下した場所に矩形を表示
 * @param event
 */
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "xxxxxxxxxxxxx:" << event->scenePos();
    qDebug() << "xxxxxxxxxxxxx:" << event->pos();
    qDebug() << "xxxxxxxxxxxxx:" << event->screenPos();

    //矩形は一つだけにしたいので一旦削除
    if(items().count()>1){
        removeItem(items()[1]);
     //   items_ = items();
    }
    QPointF p = event->scenePos();
    QGraphicsRectItem *item = addRect(QRectF(p, p + QPointF(64, 32)));
}
