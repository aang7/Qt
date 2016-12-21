#ifndef MYCUSTOMITEM_H
#define MYCUSTOMITEM_H
#include<QGraphicsItem>

class MyCustomItem : public QGraphicsItem
{

public:
    MyCustomItem(QGraphicsItem *parent = NULL);

protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    QRectF boundingRect() const;

    virtual void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
};

#endif // MYCUSTOMITEM_H
