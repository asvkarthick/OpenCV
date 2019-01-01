// This program reads an image and inverts the image and displays both original and inverted image
// Compile and build this program with
// g++ tutorial03.cpp -o tutorial03 `pkg-config --cflags --libs opencv`

// To run with cmake follow the below steps
// mkdir build
// cd build
// cmake ..
// make
// cd ..
// ./build/tutorial03

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main(void)
{
    int width, height;
    Size s;
    Mat image = imread("../../images/lena.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    if(!image.data)
    {
        std::cerr << "Could not open image file" << std::endl;
        return -1;
    }

    Mat inv_image = image.clone();

    s = inv_image.size();
    width = s.width;
    height = s.height;
    std::cout << "Width = " << width << " Height = " << height << std::endl;
    std::cout << "Width = " << inv_image.size[0] << std::endl;
    std::cout << "Height = " << inv_image.size[1] << std::endl;
    std::cout << "Channels = " << inv_image.channels() << std::endl;

    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", image);

    int i, j;

    double start = (double) getTickCount();
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            inv_image.at<unsigned char>(i, j) = 255 - inv_image.at<unsigned char>(i, j);
            // inv_image(i, j)[0] = 255 - inv_image(i, j)[0];
            // inv_image(i, j)[1] = 255 - inv_image(i, j)[1];
            // inv_image(i, j)[2] = 255 - inv_image(i, j)[2];
        }
    }
    double end = (double) getTickCount();
    double t = (end - start) / getTickFrequency();
    std::cout << "Time taken to convert RGB to grayscale = " << t << std::endl;

    namedWindow("Inverted Image", WINDOW_AUTOSIZE);
    imshow("Inverted Image", inv_image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
