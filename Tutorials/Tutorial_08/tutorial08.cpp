// This program reads an image and inverts the image and displays both original and inverted image
// Compile and build this program with
// g++ tutorial08.cpp -o tutorial08 `pkg-config --cflags --libs opencv`
// Run with
// ./tutorial08 ../../images/lenna.bmp

// To run with cmake follow the below steps
// mkdir build
// cd build
// cmake ..
// make
// ./tutorial08 ../../../images/lenna.bmp

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char *argv[])
{
    int width, height;

    if(argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " image-file" << std::endl;
        return -1;
    }

    Mat image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if(!image.data)
    {
        std::cerr << "Could not open image file" << std::endl;
        return -1;
    }

    Mat inv_image = image.clone();

    height = image.rows;
    width = image.cols;
    std::cout << "Width = " << width << " Height = " << height << std::endl;
    std::cout << "Width = " << inv_image.size[0] << std::endl;
    std::cout << "Height = " << inv_image.size[1] << std::endl;
    std::cout << "Channels = " << inv_image.channels() << std::endl;

    if(image.channels() != 3)
    {
        std::cerr << "This program only works for color image" << std::endl;
        return -1;
    }

    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", image);

    int i, j;
    MatIterator_<Vec3b> it, end;
    MatIterator_<Vec3b> inv_it;

    double start = (double) getTickCount();
    inv_it = inv_image.begin<Vec3b>();
    for(it = image.begin<Vec3b>(), end = image.end<Vec3b>(); it != end; ++it, ++inv_it)
    {
        (*inv_it)[0] = (*it)[2];
        (*inv_it)[1] = (*it)[1];
        (*inv_it)[2] = (*it)[0];
    }
    double end_t = (double) getTickCount();
    double t = (end_t - start) / getTickFrequency();
    std::cout << "Time taken to convert RGB to grayscale = " << t << std::endl;

    namedWindow("Color swapped Image", WINDOW_AUTOSIZE);
    imshow("Color swapped Image", inv_image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
