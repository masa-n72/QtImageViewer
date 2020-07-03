#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include "scene.h"


class View : public QGraphicsView
{
    Q_OBJECT
public:
    View(QWidget *parent);
  //  void mousePressEvent(QMouseEvent *event) override;
//    void paintEvent(QPaintEvent *event) override;
    void setImg(QImage& img);
    QImage m_img;
    QGraphicsPixmapItem *pixmapItem1;
    QGraphicsPixmapItem *pixmapItem2;
    Scene    *scene;
    QGraphicsPixmapItem *pixmapItem=nullptr;
    QWidget *parent_;

    private slots:
    void on_ButtonMagnificationUp_Pushed();
    void on_ButtonMagnificationDown_Pushed();
    void on_ButtonMagnificationReset_Pushed();

private:
    int i=0;
};

#endif // VIEW_H
