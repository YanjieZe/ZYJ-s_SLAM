//
// Created by zyj on 10/17/20.
//
#include "visualOdometry.h"

/*
void pose_estimation_2d2d(
        std::vector<KeyPoint> keypoints_1,
        std::vector<KeyPoint> keypoints_2,
        std::vector<DMatch> matches,
        Mat& K,
        Mat& R, Mat& t )
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
    fundamental_matrix = findFundamentalMat(points1,points2,CV_FM_8P0INT);
    cout<<"fundamental_matrix is"<<endl<<fundamental_matrix<<endl;

}
 */