#include "DrawVisitor.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "Rectangle.h"

    DrawVisitor::DrawVisitor(){

    }
    void DrawVisitor::visitSimpleGraphics(SimpleGraphics *sg){
        sg->shape()->draw(scene,QPen(Qt::blue));
    };
    void DrawVisitor::visitCompositeGraphics (CompositeGraphics *cg){
        cg->getBoundingBox().draw(scene,QPen(Qt::green));
    };
