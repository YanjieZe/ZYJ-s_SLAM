//
// Created by zyj on 10/17/20.
//


#include "visualOdometry.h"

int main ()
{
    //camera patameters
    Mat K = (Mat_<double>(3,3)<<520.9, 0, 325.1, 0, 521.0, 249.7, 0, 0, 1);

    // input two images
    string path1 = "../1.png";
    string path2 = "../2.png";
    Mat img_1 = imread(path1, IMREAD_COLOR);
    Mat img_2 = imread(path2, IMREAD_COLOR);

    //feature keypoints
    vector<KeyPoint> keypoints_1,keypoints_2;
    vector<DMatch> matches;
    cout<<"Processing";

    find_feature_matches(img_1,img_2,keypoints_1,keypoints_2,matches);

    return 0;
}