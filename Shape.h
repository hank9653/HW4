#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <string>
#include <QGraphicsScene>

class Rectangle;

class Shape {
public:
    virtual int area() = 0;
    virtual Rectangle getBoundingBox()=0;
    virtual std::string describe() {return std::string("");};
    virtual void draw(QGraphicsScene *gs,QPen pen)=0;
};


#endif // SHAPE_H_INCLUDED
