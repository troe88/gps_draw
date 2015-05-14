#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget *parent);
    ~MyGraphicsView();
};

#endif // MYGRAPHICSVIEW_H
