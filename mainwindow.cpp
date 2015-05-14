#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QPen>
#include "mygraphicsview.h"
#include <myscene.h>

QString coloredText(const QString &text, QColor color){
    int r, b, g, a;
    color.getRgb(&r,&g,&b, &a);
    qDebug() << r << g << b;
    QString c = "rgb(" + QString::number(r) + "," + QString::number(g) + "," + QString::number(b) + ")";
    qDebug() << c;
    QString res = "<pre style=\" font-weight: bold; color:" + c + ";\">" + text + "  </pre>";

    return res;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    prepareTable();

    // WiFi_1 -> WiFi_2 -> LTE -> WiFi_1

    QVector<QColor> d = ((MyScene*)ui->graphicsView->scene())->color_data;

    foreach (QColor temp, d) {
        ui->textBrowser->insertHtml(coloredText("SOME_NETW", temp));
    }

//    ui->textBrowser->insertHtml(coloredText("WiFi_1", ((MyScene*)ui->graphicsView->scene())->color_data.at(0)));
//    ui->textBrowser->insertHtml(coloredText("WiFi_2", ((MyScene*)ui->graphicsView->scene())->color_data.at(1)));
//    ui->textBrowser->insertHtml(coloredText("LTE", ((MyScene*)ui->graphicsView->scene())->color_data.at(2)));
//    ui->textBrowser->insertHtml(coloredText("WiFi_1", ((MyScene*)ui->graphicsView->scene())->color_data.at(3)));
}

void MainWindow::prepareTable(){
    //Set table row count 1 and column count 3

    QTableWidget *table = ui->tableWidget;
    table->horizontalHeader()->setStretchLastSection(true);
    table->setRowCount(4);
    table->setColumnCount(4);

//    table->setColumnWidth(0,50);
    table->setColumnWidth(1,80);
    table->setColumnWidth(2,50);
    table->setColumnWidth(3,50);
    //    table->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Expanding);

    table->setHorizontalHeaderLabels(QString("HEADER 1;HEADER 2;HEADER 3;HEADER 4").split(";"));

    //Add Table items here
    table->setItem(0,0,new QTableWidgetItem("ITEM 1"));
    table->setItem(0,1,new QTableWidgetItem("ITEM 2"));
    table->setItem(0,2,new QTableWidgetItem("ITEM 3"));
    table->setItem(0,3,new QTableWidgetItem("ITEM 4"));

    table->setItem(1,0,new QTableWidgetItem("ITEM 1"));
    table->setItem(1,1,new QTableWidgetItem("ITEM 2"));
    table->setItem(1,2,new QTableWidgetItem("ITEM 3"));
    table->setItem(1,3,new QTableWidgetItem("ITEM 4"));

    table->setItem(2,0,new QTableWidgetItem("ITEM 1"));
    table->setItem(2,1,new QTableWidgetItem("ITEM 2"));
    table->setItem(2,2,new QTableWidgetItem("ITEM 3"));
    table->setItem(2,3,new QTableWidgetItem("ITEM 4"));

    //    table->setItem(3,0,new QTableWidgetItem("ITEM 1"));
    //    table->setItem(3,1,new QTableWidgetItem("ITEM 2"));
    table->setItem(3,2,new QTableWidgetItem("ITEM 3"));
    table->setItem(3,3,new QTableWidgetItem("ITEM 4"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
