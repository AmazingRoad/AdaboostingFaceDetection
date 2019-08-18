#include "opencv2/opencv.hpp"

using namespace cv;
int main(int argc, char** argv){
    CascadeClassifier cascade;
    cascade.load("../haarcascade_frontalface_default.xml");

    Mat image = imread("../jay.jpg");
    int w = image.cols;
    int h = image.rows;

    float maxRatio = 0.5;
    float minRatio = 0.1;
    double scaleFactor = 1.1;
    int minNeighbors = 3;
    int flags = 0|CV_HAAR_FIND_BIGGEST_OBJECT;
    Size minSize(w*minRatio, h*minRatio);
    Size maxSize(w*maxRatio, h*maxRatio);
    std::vector<Rect> detectResults;

    cascade.detectMultiScale(image, detectResults, scaleFactor, minNeighbors, flags, minSize, maxSize);

    for(int i = 0; i < detectResults.size(); i++){
        std::cout<<detectResults[i]<<std::endl;
        rectangle(image, detectResults[i], Scalar(0,0,255), 1);
    }
    imshow("face detection", image);
    waitKey(0);

    return 0;
}
