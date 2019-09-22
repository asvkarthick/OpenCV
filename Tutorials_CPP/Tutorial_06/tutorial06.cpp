// This program generates grayscale gradient

// Compile and build this program with
// g++ tutorial06.cpp -o tutorial06 `pkg-config --cflags --libs opencv`

// To run with cmake follow the below steps
// mkdir build
// cd build
// cmake ..
// make
// ./tutorial06

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main(void)
{
    Mat image = Mat::zeros(256, 256, CV_8UC1);

    int width = image.size[0];
    int height = image.size[1];

    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            image.at<unsigned char>(row, col) = (row + col) & 0xFF;
        }
    }

    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
