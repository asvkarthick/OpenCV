// This program creates Mat object 'm' with predefined values and
// prints the values on the console

// Compile and build this program with
// g++ tutorial07.cpp -o tutorial07 `pkg-config --cflags --libs opencv`

// To run with cmake follow the below steps
// mkdir build
// cd build
// cmake ..
// make
// ./tutorial07

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main(void)
{
    Mat m(2, 2, CV_8UC3, Scalar(0, 0, 255));

    std::cout << m << std::endl;

    return 0;
}
