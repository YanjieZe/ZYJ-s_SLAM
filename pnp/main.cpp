#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

int main() {
    // camera parameters
    double camD[9]={913.1838519635979, 0, 642.675229085825,
    0, 766.0147575172565, 365.0250373802296,
    0, 0, 1};

    // distortion
    double distCoeffD[5] = {-0.4338629777541601, 0.2967710571102112, -0.0004557785585483899, -0.0002240604911029394, -0.1410073068885603};

    Mat camera_matrix = Mat(3,3,CV_64FC1,camD);
    Mat distortion_coefficients = Mat(5,1,CV_64FC1,distCoeffD);

    solvePnP();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
