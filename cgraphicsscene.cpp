#include "cgraphicsscene.h"
#include<opencv2/opencv.hpp>
#include<QGraphicsScene>
#include<QDebug>
#include<QImage>
#include<QPixmap>


CgraphicsScene::CgraphicsScene(QObject* parent) : QGraphicsScene(parent)
{
    //Trying to adjust the size -.-

    update(0, 0, 300, 300);
}



void CgraphicsScene::updateMat(cv::Mat frame){
    qDebug("Entere a updateMat wii!!!!");
    cv::cvtColor(frame, frame,CV_BGR2RGB); //BGR 2 RGB

    QImage imagen((uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

    QPixmap img(QPixmap::fromImage(imagen.scaled(300, 300, Qt::KeepAspectRatio )));
    this->setBackgroundBrush(img.scaled(300, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    update(); //Actualiza Scene
}


/* ========================Event Handling ===========================================*/
void CgraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug("Dragging en la escena");

}

void CgraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{

}

void CgraphicsScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
}


/* Making a simple example of how it should works */
void CgraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{


    //updateMat(matriz);
}

