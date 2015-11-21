#include "Painter.h"

Painter::Painter(qreal _posx, qreal _posy, qreal _width, qreal _heigh,QWidget *_widget)
{
    //ctor
     posx = _posx;
     posy = _posy;
     width = _width;
     heigh = _heigh;
     widget = _widget;
}

Painter::~Painter()
{
    //dtor
}


QRectF Painter::boundingRect() const
{
    return QRectF(posx,posy,width,heigh);
}



void Painter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
    QPen pen(Qt::red);
    painter->setPen(pen);
    painter->drawRect(posx, posy, width, heigh);
}

