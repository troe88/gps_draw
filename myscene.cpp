#include "myscene.h"
#include <math.h>
//#include <QtMath>
#include <QVector>
#include <QPainter>

#define O(x) map->getXfromLon(x)
#define A(x) map->getYfromLat(x)

MyScene::MyScene(QWidget *parent)
    : QGraphicsScene(parent)
{
    double lon=30.3768888503044;
    double lat=60.0072587926437;
    map = new MapRect(lat, lon);
    map->loadMapImage();

    setSceneRect(map->_pixmap->boundingRect());
    addItem(map->_pixmap);

    addEllipse(map->getXfromLon(lon), map->getYfromLat(lat), 10, 10, QPen(Qt::red, 6));

    QGraphicsLineItem* item = new QGraphicsLineItem(QLine(0,0,100,100));
    item->setPen(QPen(QColor(200,0,0), 5));

    addItem(item);

    addWay();
}

void MyScene::addWay(){
    QVector<QPoint> wayData = QVector<QPoint>();

    wayData.push_back(QPoint(O(30.3755833744242), A(60.0077028265297)));
    wayData.push_back(QPoint(O(30.3766562308945), A(60.0075371389102)));
    wayData.push_back(QPoint(O(30.3775110271066), A(60.0074150527647)));
    wayData.push_back(QPoint(O(30.3781739302915), A(60.0073016866545)));
    wayData.push_back(QPoint(O(30.3783309336774), A(60.0072144816899)));
    wayData.push_back(QPoint(O(30.3779820372643), A(60.006695607396 )));
    wayData.push_back(QPoint(O(30.3774968431115), A(60.0060620482694)));
    wayData.push_back(QPoint(O(30.3773754663374), A(60.0058800159727)));
    wayData.push_back(QPoint(O(30.3767685824665), A(60.0059793064406)));
    wayData.push_back(QPoint(O(30.3768016852231), A(60.0062109830397)));
    wayData.push_back(QPoint(O(30.3765920344314), A(60.0063985295741)));
    wayData.push_back(QPoint(O(30.3761396300913), A(60.0065033345271)));
    wayData.push_back(QPoint(O(30.3756651572468), A(60.0064316259109)));
    wayData.push_back(QPoint(O(30.3754003351941), A(60.0062220152182)));
    wayData.push_back(QPoint(O(30.3746279375403), A(60.0063544010734)));
    wayData.push_back(QPoint(O(30.3748817253408), A(60.0066963954133)));
    wayData.push_back(QPoint(O(30.3750141363672), A(60.0069721947242)));
    wayData.push_back(QPoint(O(30.3753120611765), A(60.0073031508611)));

    color_data = QVector<QColor>();

    QGraphicsLineItem* item;
    for (int i = 0; i < wayData.size(); ++i) {
        addEllipse(wayData.at(i).x(), wayData.at(i).y(), 10, 10, QPen(Qt::green, 6));
        if(i == wayData.size() - 1){
            item = new QGraphicsLineItem(QLine(wayData.at(i), wayData.at(0)));
        } else {
            item = new QGraphicsLineItem(QLine(wayData.at(i), wayData.at(i+1)));
        }
        QColor color(qrand() % 255, qrand() % 255, qrand() % 255);
        color_data.push_back(color);
        item->setPen(QPen(color, 5));
        addItem(item);
    }
}

MyScene::~MyScene()
{

}

