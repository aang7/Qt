#include "gaugelist.h"

#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>


GaugeList::GaugeList(QWidget *parent) : QListWidget(parent)
{
     setDragEnabled(true);

}

GaugeList::GaugeList(){
    setDragEnabled(true);
}


