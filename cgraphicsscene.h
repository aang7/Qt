#ifndef CGRAPHICSSCENE_H
#define CGRAPHICSSCENE_H


#include<QGraphicsScene>
#include<QMimeData>
#include<QDragEnterEvent>
#include<QDropEvent>
#include<QGraphicsSceneDragDropEvent>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include"gauge.h"


class CgraphicsScene : public QGraphicsScene
{

public:
    CgraphicsScene(QObject* parent = NULL);
    ~CgraphicsScene();

    void updateMat(cv::Mat frame);
    //not using for the moment
    //enum Mode { InsertItem, InsertLine, InsertText, MoveItem }; //Tipos de modos de creacion

private:
    cv::Mat imageCV;
    bool dropped = true;
public slots:
    //void setMode(Mode mode);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

};

#endif // CGRAPHICSSCENE_H


