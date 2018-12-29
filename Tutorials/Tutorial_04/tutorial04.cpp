// This program opens camera and captures frames and display on the image window
// To run this program you need to have either built-in camera on laptop or
// external USB camera

// Compile and build this program with
// g++ tutorial04.cpp -o tutorial04 `pkg-config --cflags --libs opencv`

#include "opencv2/opencv.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;
 
int main()
{
    // Create a VideoCapture object and use camera to capture the video
    VideoCapture cap(0);

    // Check if camera opened successfully
    if(!cap.isOpened())
    {
        std::cerr << "Error opening camera" << endl;
        return -1;
    }
 
    // Default resolution of the frame is obtained.The default resolution is system dependent. 
    int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

    while(1)
    {
        Mat frame;

        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        // Display the resulting frame
        imshow( "Frame", frame );

        // Press  ESC on keyboard to  exit
        char c = (char)waitKey(1);
        if( c == 27 )
            break;
    }

    // When everything done, release the video capture and write object
    cap.release();

    // Closes all the windows
    destroyAllWindows();
    return 0;
}
