#ifndef GAUGELIST_H
#define GAUGELIST_H

#include <QListWidget>
#include<QString>

class GaugeList : public QListWidget
{
    Q_OBJECT

public:
    GaugeList(QWidget *parent);
    GaugeList();

private:
    void setupList();

};

#endif // GAUGELIST_H
