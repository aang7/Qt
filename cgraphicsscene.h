#ifndef CGRAPHICSSCENE_H
#define CGRAPHICSSCENE_H


#include<QGraphicsScene>
#include<QMimeData>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>


class CgraphicsScene : public QGraphicsScene
{
    //Q_OBJECT

public:
    CgraphicsScene(QObject* parent = NULL);
    void updateMat(cv::Mat frame);
    //not using for the moment
    //enum Mode { InsertItem, InsertLine, InsertText, MoveItem }; //Tipos de modos de creacion

public slots:
    //void setMode(Mode mode);



/* Event handling */
protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

};

#endif // CGRAPHICSSCENE_H


