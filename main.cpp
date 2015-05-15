#include "mainwindow.h"
#include <QApplication>
#include <gps.h>

void conditionally_log_fix(gps_data_t* t)
{
    QStringList lst = QString(gps_data(t)).split(",");
    if(lst.size() > 8)
    {
        if(lst[0].split(":")[1].contains("TPV"))
            qDebug() << lst[0] << "\n" << lst[4] << "\n lat" << lst[6].split(":")[1] << "\n lon" << lst[7].split(":")[1] << "\n alt" << lst[8].split(":")[1];

//		double = st[6].split(":")[1].toDouble();

    }
}

int main(int argc, char *argv[])
{

    gps_data_t temp;

    gps_open("localhost", "2947", &temp);


    gps_stream(&temp, WATCH_ENABLE,  NULL);


    gps_mainloop(&temp, 5000000, conditionally_log_fix);
    gps_close(&temp);

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
}
