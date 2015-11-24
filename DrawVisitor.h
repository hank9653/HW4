#ifndef DRAWVISITOR_H_INCLUDED
#define DRAWVISITOR_H_INCLUDED
#include "GraphicsVisitor.h"
#include <QGraphicsScene>

class DrawVisitor : public GraphicsVisitor {
public:
    DrawVisitor();
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics (CompositeGraphics *cg);
    void setScene(QGraphicsScene *s){scene=s;};
private:
    QGraphicsScene *scene;
};

#endif // DRAWVISITOR_H_INCLUDED
