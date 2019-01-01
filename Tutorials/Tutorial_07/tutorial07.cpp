// This program creates Mat object 'm' with predefined values and
// prints the values on the console
// This helps a lot in debugging OpenCV programs

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
    Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
    Mat E = Mat::eye(4, 4, CV_8UC1);
    Mat O = Mat::ones(2, 2, CV_8UC1);
    Mat Z = Mat::zeros(2, 2, CV_8UC1);

    std::cout << "M = " << std::endl << M << std::endl;
    std::cout << "E = " << std::endl << E << std::endl;
    std::cout << "O = " << std::endl << O << std::endl;
    std::cout << "Z = " << std::endl << Z << std::endl;

    return 0;
}
