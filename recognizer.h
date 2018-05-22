#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include <opencv2/objdetect/objdetect.hpp>

#include <vector>
#include <string>

using namespace cv;
using namespace std;

class Recognizer
{
public:
    Recognizer(const string &filename);
    ~Recognizer();
    Mat recognize(Mat &image);

private:
    void draw(Mat &image, vector<Rect> &objects);
    Mat turnGrey(Mat &image);

private:
    CascadeClassifier *m_classifier;

};

#endif // RECOGNIZER_H
