//
// Created by zyj on 10/17/20.
//


#include "visualOdometry.h"

int main ()
{
    //camera patameters
    Mat K = (Mat_<double>(3,3)<<520.9, 0, 325.1, 0, 521.0, 249.7, 0, 0, 1);

    //1 input two images
    string path1 = "../1.png";
    string path2 = "../2.png";
    Mat img_1 = imread(path1, IMREAD_COLOR);
    Mat img_2 = imread(path2, IMREAD_COLOR);

    //2 find feature keypoints
    vector<KeyPoint> keypoints_1,keypoints_2;
    vector<DMatch> matches;
    cout<<"Processing";

    find_feature_matches(img_1,img_2,keypoints_1,keypoints_2,matches);
    cout<<"the number of match point: "<<matches.size()<<endl ;

    //3 pose estimation between two pictures to get R and T
    Mat R, t;
    pose_estimation_2d2d(keypoints_1, keypoints_2, matches, K, R, t);

    //4 triangulation
    vector<Point3d> points;
    triangulation(keypoints_1,keypoints_2,matches,K,R,t,points);
    
    return 0;
}