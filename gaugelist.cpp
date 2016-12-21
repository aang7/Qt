#include "gaugelist.h"

#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>


GaugeList::GaugeList(QWidget *parent) : QListWidget(parent)
{
     setDragEnabled(true);
     setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
     setFixedSize(200,100);
     setupList();
}

GaugeList::GaugeList(){
    setDragEnabled(true);
}

void GaugeList::setupList(){
    QListWidgetItem *gauge = new QListWidgetItem("Circular Gauge");
    gauge->setIcon(QIcon(":/images/gaugeicon.png"));
    addItem(gauge);

    QListWidgetItem *attitude= new QListWidgetItem("Attitude");
    attitude->setIcon(QIcon(":/images/attitudeicon.jpg"));
    addItem(attitude);

    QListWidgetItem *indicatorbar= new QListWidgetItem("Indicator Bar");
    indicatorbar->setIcon(QIcon(":/images/baricon.png"));
    addItem(indicatorbar);

}



