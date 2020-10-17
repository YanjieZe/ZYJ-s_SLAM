//
// Created by zyj on 10/17/20.
//
#include "visualOdometry.h"


void pose_estimation_2d2d(
        std::vector<KeyPoint> keypoints_1,
        std::vector<KeyPoint> keypoints_2,
        std::vector<DMatch> matches,
        Mat& K,
        Mat& R,
        Mat& t )
{
    //1 convert points
    vector<Point2f> points1;
    vector<Point2f> points2;

    for (int i=0; i<(int)matches.size();i++)
    {
        points1.push_back(keypoints_1[matches[i].queryIdx].pt);
        points2.push_back(keypoints_2[matches[i].trainIdx].pt);
    }


    //2 compute fundamental matrix
    Mat fundamental_matrix;
    fundamental_matrix = findFundamentalMat(points1,points2,FM_8POINT);
    cout<<"fundamental_matrix is "<<endl<<fundamental_matrix<<endl;

    //3 compute essential_matrix;
    Point2d principal_point(325.1,249.7); // 光心，标定值
    int focal_length = 521;// 焦距，标定值
    Mat essential_matrix;
    essential_matrix = findEssentialMat(points1,points2,focal_length,principal_point,RANSAC);
    cout<<"essential_matrix is "<<endl<<essential_matrix<<endl;

    //4 compute homography matrix
    Mat homography_matrix;
    homography_matrix = findHomography(points1,points2,RANSAC,3,noArray(),2000,0.99);
    cout<<"homography_matrix is "<<endl<<homography_matrix<<endl;

    recoverPose(essential_matrix,points1,points2,R,t,focal_length,principal_point);
    cout<<"R is "<<endl<<R<<endl;
    cout<<"t is "<<endl<<t<<endl;
}
