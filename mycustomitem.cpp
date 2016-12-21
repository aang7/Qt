#include "mycustomitem.h"
#include<QtGui>

MyCustomItem::MyCustomItem(QGraphicsItem *parent) : QGraphicsItem(parent)
{


    //setFlag(QGraphicsItem::ItemIsFocusable);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable |QGraphicsItem::ItemIsFocusable);

}

QRectF MyCustomItem::boundingRect() const{
    return QRectF(0, 0, 30, 30);
}

void MyCustomItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::blue);
    painter->drawRect(0, 0, 30, 30);
}


void MyCustomItem::keyPressEvent(QKeyEvent *event){

    switch (event->key()) {
    case Qt::Key_Right:{
        moveBy(30, 0);
        break;

    }

    case Qt::Key_Left: {
        moveBy(-30, 0);
        break;
    }

    case Qt::Key_Up: {
        moveBy(0, -30);
        break;

    }

    case Qt::Key_Down:{
        moveBy(0, 30);
        break;
    }

   }

    update();
}


