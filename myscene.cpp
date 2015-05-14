#include "myscene.h"
#include <math.h>
#include <QtMath>


MyScene::MyScene(QWidget *parent)
    : QGraphicsScene(parent)
{
    QPen black(Qt::red);
    black.setWidth(6);
    //60.00394 30.34475

    double lon=30.34475;
    double lat=60.00394 ;
    map = new MapRect(lat, lon);
    map->loadMapImage();

    setSceneRect(map->_pixmap->boundingRect());
    addItem(map->_pixmap);

    addEllipse(map->getXfromLon(lon), map->getYfromLat(lat), 10, 10, black);
}

MyScene::~MyScene()
{

}

