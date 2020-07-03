#include "view.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>

/**
 * @brief View::View
 * @param parent
 */
View::View(QWidget *parent)
{
    setDragMode(QGraphicsView::ScrollHandDrag);
    scene = new Scene();
    setScene(scene);
}





void View::setImg(QImage &img)
{
    m_img = QImage(img);
    auto pix = QPixmap::fromImage(img);
    if(pixmapItem!=nullptr) delete pixmapItem;
    pixmapItem = new QGraphicsPixmapItem(pix);
    pixmapItem->setTransformationMode(Qt::FastTransformation);
    qDebug() << "Offset" << pixmapItem->offset();
    qDebug() << "Alignment" << alignment();
    qDebug() << "width" << m_img.width();
    qDebug() << "offset" << viewport()->sizeHint();

    scene->addItem(pixmapItem);
    auto ii = scene->items();
    qDebug() << "count:" << ii.count();
    if(scene->items().count()>1){
        scene->removeItem(ii[1]);
        scene->addItem(ii[1]);
        scene->setFocusItem(ii[1]);
    }

    QTransform trans = this->transform();
    qDebug() << "m11" << trans.m11();
    scene->update();
}

void View::on_ButtonMagnificationUp_Pushed()
{
    QTransform trans = this->transform();
    qDebug() << "m11" << trans.m11();
    auto trans2 = trans.scale(1.1,1.1);
    setTransform(trans2);
}

void View::on_ButtonMagnificationDown_Pushed()
{
    QTransform trans = this->transform();
    qDebug() << "m11" << trans.m11();
    auto trans2 = trans.scale(0.9,0.9);
    setTransform(trans2);
}

void View::on_ButtonMagnificationReset_Pushed()
{
    QTransform trans = this->transform();
    qDebug() << "m11" << trans.m11();
    trans.reset();
    auto trans2 = trans.scale(1,1);
    setTransform(trans2);
}
