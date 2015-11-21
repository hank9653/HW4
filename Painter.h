#pragma once
#ifndef PAINTER_H
#define PAINTER_H

#include <QPainter>
#include <QGraphicsItem>
#include <QAction>
#include <QStaticText>
#include "qwidget.h"
#include <iostream>
#include <string>
#include <sstream>
#include <QColor>
#include <QPen>
#include <QPointF>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
using namespace std;
class Painter:public QGraphicsItem
{
    public:
        Painter( qreal _posx, qreal _posy, qreal _width, qreal _heigh,QWidget *_widget);
        virtual ~Painter();

        QWidget *widget;
        const QRectF *rectptr;
        qreal posx;
        qreal posy;
        qreal width;
        qreal heigh;
        QRectF boundingRect() const;//必須實做的virtual function，但目前用不到
        void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    protected:
    private:
};

#endif // PAINTER_H
