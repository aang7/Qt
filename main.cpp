//#include "mainwindow.h"
#include <QApplication>


#include<QGraphicsView>
#include<QGraphicsScene>
#include"mycustomitem.h"
#include<QPixmap>
#include<QtWidgets>
#include<QHBoxLayout>
#include"gaugelist.h"
#include"cgraphicsscene.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    /* ===========OpenCV step ==========*/
    cv::Mat image;
    image = cv::imread("/home/aang/Imágenes/Wallpaper.png", 1);

    if(!image.data){
      qDebug("No image data\n");
      return -1;
    }
    /* ===========OpenCV step ==========*/

    QGraphicsView view;

    //QGraphicsScene *scene = new QGraphicsScene(0,0,300,300, &view);

    CgraphicsScene *scene = new CgraphicsScene(&view);


    scene->setSceneRect(0, 0, 300, 300);


    //QPixmap imgBackground("/home/aang/Imágenes/Wallpaper.png");

    //fitInView(p, Qt::KeepAspectRatio);
    view.setScene(scene);
    //scene->setBackgroundBrush(imgBackground.scaled(view.size().width(), view.size().height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

    /* Set up the window */
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);
    MyCustomItem *myItem = new MyCustomItem;
    GaugeList *gaugeList = new GaugeList(frame);

    //gaugeList->addItem("Soy un item");
    //gaugeList->addItem("Soy otro item");

    //scene->setFocus();
    //myItem->setFocus();

    scene->updateMat(image); //Jala

    scene->addItem(myItem);

    frameLayout->addWidget(&view);
    frameLayout->addWidget(gaugeList);

    frame->show();

    //frame->resize(300, 300);
    frame->move(50, 50);
    return a.exec();
}


/* Bueno pues por el momento o encontre una forma para hacer el resize correcto de la imagen de fondo
    Intentanre hacer la operacion del nuevo objeto(openCV)
*/
