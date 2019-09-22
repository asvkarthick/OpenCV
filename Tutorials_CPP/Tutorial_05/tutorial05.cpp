// This program reads color image and converts it to grayscale image
// and displays both RGB and grayscale image

// Compile and build this program with
// g++ tutorial05.cpp -o tutorial05 `pkg-config --cflags --libs opencv`

// Run this program with
// ./tutorial05

// To run with cmake follow the below steps
// mkdir build
// cd build
// cmake ..
// make
// cd ..
// ./build/tutorial05

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;

int main(void)
{
    cv::Mat image = imread("../../images/lenna.bmp", CV_LOAD_IMAGE_COLOR);
    if(!image.data)
    {
        std::cerr << "Could not open image file" << std::endl;
        return -1;
    }

    cv::Mat gray_image;
    // Convert RGB image to grayscale image
    cvtColor(image, gray_image, CV_BGR2GRAY);    

    namedWindow("RGB Image", WINDOW_AUTOSIZE);
    imshow("RGB Image", image);

    namedWindow("Grayscale Image", WINDOW_AUTOSIZE);
    imshow("Grayscale Image", gray_image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
