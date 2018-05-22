#include "recognizer.h"

#include <vector>
#include <string>

#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

Recognizer::Recognizer(const string &filename) :
    m_classifier(new CascadeClassifier(filename))
{

}

Recognizer::~Recognizer()
{
    delete(m_classifier);
}

Mat Recognizer::recognize(Mat &image)
{
    Mat grey = turnGrey(image);

    vector<Rect> objects;

    m_classifier->detectMultiScale(grey, objects, 1.3, 8);

    draw(image, objects);

    return image;

}

Mat Recognizer::turnGrey(Mat &image)
{
    Mat grey;

    cvtColor(image, grey, CV_BGR2GRAY);

    return grey;
}

void Recognizer::draw(Mat &image, vector<Rect> &objects)
{
    for(Rect obj : objects)
    {
        // Mat roi = image(obj);

        rectangle(image, obj, Scalar(255, 0, 0));
    }
}
