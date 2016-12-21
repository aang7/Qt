#include "cgraphicsscene.h"
#include<QGraphicsScene>
#include<QDebug>
#include<QImage>
#include<QPixmap>




CgraphicsScene::CgraphicsScene(QObject* parent) : QGraphicsScene(parent)
{
    //Trying to adjust the size...
    update(0, 0, 300, 300);

}

void CgraphicsScene::updateMat(cv::Mat frame){


    imageCV = frame.clone(); //Esto no esta optimizado, estoy experimentandoxd

    if(!dropped){
        cv::namedWindow("hola", WINDOW_NORMAL);
        cv::Mat sample = imageCV.clone();
        cv::cvtColor(sample, sample, CV_RGB2BGR);
        cv::imshow("hola", sample);
        }else if(dropped){ //Just once the change of BGR 2 RGB
            cv::cvtColor(imageCV, imageCV, CV_BGR2RGB); //BGR 2 RGB
            dropped = false;
        }

    QImage imagen((uchar*)imageCV.data, imageCV.cols, imageCV.rows, imageCV.step, QImage::Format_RGB888);
    QPixmap img(QPixmap::fromImage(imagen.scaled(300, 300, Qt::KeepAspectRatio )));
    this->setBackgroundBrush(img.scaled(300, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    update(); //Actualiza Scene
}


/* ========================Event Handling ===========================================*/
void CgraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{

    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")){
        event->acceptProposedAction();
        qDebug() << "Acepet el formato del mimeData en Scene";
    }
    else{
        qDebug() << "No acepte el drag";

    }
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
    /* Dentro de este metodo tengo controlar que es lo que voy a crear
       dependiendo los valores que reciba de mi gaugeList */

    qDebug("Dropping en la escena");


    /* Handling the DATA */

    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")){
            QByteArray itemData = event->mimeData()->data(
                        "application/x-qabstractitemmodeldatalist");
            QDataStream stream(&itemData, QIODevice::ReadOnly);
            int row, col;
            QMap<int, QVariant> valueMap;
            stream >> row >> col >> valueMap;

            qDebug() << "stream: " << stream << "\n";
            qDebug() << "row : " << row << "\n";
            qDebug() << "valueMap : " << valueMap<< "\n";

            if(!valueMap.isEmpty())
                event->accept();

            /* Controlando por Filas(por el momento) */
            switch(row){
                case 0:{
                    Gauge circularGauge(100, 200, cv::Point(200, 200));
                    circularGauge.onDraw(imageCV, 77);
                    break;
                }

                case 1:{
                    Attitude attitudeGauge(cv::Point(600, 600), cv::Size(400, 500));
                    attitudeGauge.onDraw(imageCV, 0, 0);
                    break;
                }
                case 2:{
                    Bargauge barGauge(cv::Point(1000, 1000), cv::Point(1050, 100));
                    barGauge.onDraw(imageCV, 77);
                    break;
                }


            }

            updateMat(imageCV);
        }
        else
            event->ignore();
}



/* Destructor */
CgraphicsScene::~CgraphicsScene(){
    imageCV.release();
}


/* Ok bien, pues ahora lo que necesito es reconocer los datos
   que estoy jalando al scene, para asi poder crear los objetos
   God is my helper!

   Update1:
        Estoy reconociendo los eventos del gaugeList PERO por filas, no se me hace conveniente pero lo hice para masomenos
        figurarme como es que va a funcionar.
*/
