#include "recognizer.h"

#include "mainwindow.h"
#include <QCoreApplication>

#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Recognizer recognizer("/home/openCV/haarcascade_frontalface_alt_tree.xml");

    Mat image = imread("/home/openCV/michael.jpg");

    Mat result = recognizer.recognize(image);

    imshow("Result", result);

    return a.exec();
}
