// This is Hello World program of OpenCV
// Compile and build this program with
// g++ tutorial01.cpp -o tutorial01 `pkg-config --cflags --libs opencv`

// For CMake use the following steps
// mkdir build
// cd build
// cmake ..
// make
// cd ..
// ./build/HelloWorld

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
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

    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
