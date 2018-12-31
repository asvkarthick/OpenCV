// This is Hello World program of OpenCV
// Compile and build this program with
// g++ tutorial02.cpp -o tutorial02 `pkg-config --cflags --libs opencv`

// To run with cmake follow the below steps
// mkdir build
// cd build
// cmake ..
// make
// ./tutorial02

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main(void)
{
    Mat image = Mat::zeros(512, 512, CV_8UC3);

    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
