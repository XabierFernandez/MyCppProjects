#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main(int argc, char** argv )
{
    Mat image;

    image = imread( "/home/xabier/Pictures/dog-park-guide.jpeg", IMREAD_COLOR );

    if ( !image.data )
    {
        cout << "No image data \n";
        return -1;
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}

