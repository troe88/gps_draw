#include "mygraphicsview.h"
#include "myscene.h"

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    MyScene *scene = new MyScene(this);
    setScene(scene);
}

MyGraphicsView::~MyGraphicsView()
{

}

