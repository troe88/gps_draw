#ifndef MYSCENE_H
#define MYSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QFile>
#include <QProcess>
#include <unistd.h>
#include <QGraphicsEllipseItem>

class MapRect {
public:
    double _min_lon;
    double _min_lat;
    double _max_lon;
    double _max_lat;
    int _pix_width;
    int _pix_height;
    QString _image_path;
    QGraphicsPixmapItem *_pixmap;

    MapRect(double c_lat, double c_lon){
        double rate  = 0.004;
        _min_lon = c_lon - rate;
        _min_lat = c_lat + (rate / 2);
        _max_lon = c_lon + rate;
        _max_lat = c_lat - (rate / 2);
        _image_path = "background2.png";

        QFile file("/home/dmitry/Downloads/Maperitive/scr2.txt");

        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);

            stream << "use-ruleset alias=default\n";
            stream << "add-web-map\n";
            stream << qSetRealNumberPrecision(10) << "set-geo-bounds " << _min_lon << "," << _min_lat << ","  << _max_lon << "," << _max_lat << "\n";
            stream << "set-print-bounds-geo\n";
            stream << "export-bitmap map-scale=1100 file=" << _image_path << "\n";

            file.close();
        }

//        chdir("/home/dmitry/Downloads/Maperitive");
//        QProcess process;
//        process.start("./Maperitive_scr.sh");
//        process.waitForFinished(-1); // will wait forever until finished

//        QString stdout = process.readAllStandardOutput();
//        qDebug() << stdout;


    }

    void loadMapImage(){
        QImage image(_image_path);
        if(image.isNull()){
            qDebug() << "load map image error";
        }
        _pix_height = image.height();
        _pix_width = image.width();
        _pixmap = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    }

    int getXfromLon(const double &lon){
        int x = 0;
        double Kx = 1 - qAbs(_max_lon - lon) / qAbs(_max_lon - _min_lon);
        qDebug() << "Kx: " << Kx;
        x = _pix_width * Kx;
        qDebug() << "x: " << x;
        return x;
    }

    int getYfromLat(const double &lat){
        int y = 0;
        double Ky = 1 - qAbs(_max_lat - lat) / qAbs(_min_lat - _max_lat);
        qDebug() << "Ky: " << Ky;
        y = _pix_height * Ky;
        qDebug() << "y: " << y;
        return y;
    }

};

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MapRect *map;
    QVector<QColor> color_data;

public:
    MyScene(QWidget *parent);
    void addWay();

    ~MyScene();
};

#endif // MYSCENE_H
