// This program reads an image and inverts the image and displays both original and inverted image
// Compile and build this program with
// g++ tutorial08.cpp -o tutorial08 `pkg-config --cflags --libs opencv`
// Run with
// ./tutorial09 ../../images/lenna.bmp

// To run with cmake follow the below steps
// mkdir build
// cd build
// cmake ..
// make
// ./tutorial09 ../../../images/lenna.bmp

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

    Mat single_color_image = image.clone();

    height = image.rows;
    width = image.cols;
    std::cout << "Width = " << width << " Height = " << height << std::endl;
    std::cout << "Width = " << single_color_image.size[0] << std::endl;
    std::cout << "Height = " << single_color_image.size[1] << std::endl;
    std::cout << "Channels = " << single_color_image.channels() << std::endl;

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

    inv_it = single_color_image.begin<Vec3b>();
    for(it = image.begin<Vec3b>(), end = image.end<Vec3b>(); it != end; ++it, ++inv_it)
    {
        (*inv_it)[0] = (*it)[0];
        (*inv_it)[1] = 0;
        (*inv_it)[2] = 0;
    }

    namedWindow("Blue Image", WINDOW_AUTOSIZE);
    imshow("Blue Image", single_color_image);

    inv_it = single_color_image.begin<Vec3b>();
    for(it = image.begin<Vec3b>(), end = image.end<Vec3b>(); it != end; ++it, ++inv_it)
    {
        (*inv_it)[0] = 0;
        (*inv_it)[1] = (*it)[1];
        (*inv_it)[2] = 0;
    }

    namedWindow("Green Image", WINDOW_AUTOSIZE);
    imshow("Green Image", single_color_image);

    inv_it = single_color_image.begin<Vec3b>();
    for(it = image.begin<Vec3b>(), end = image.end<Vec3b>(); it != end; ++it, ++inv_it)
    {
        (*inv_it)[0] = 0;
        (*inv_it)[1] = 0;
        (*inv_it)[2] = (*it)[2];
    }

    namedWindow("Red Image", WINDOW_AUTOSIZE);
    imshow("Red Image", single_color_image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
