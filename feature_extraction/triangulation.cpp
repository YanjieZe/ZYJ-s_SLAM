//
// Created by zyj on 10/17/20.
//

#include "visualOdometry.h"

void triangulation(
        const vector<KeyPoint>& keypoint_1,
        const vector<KeyPoint>& keypoint_2,
        const std::vector<DMatch>& matches,
        const Mat& K,
        const Mat& R,
        const Mat& t,
        vector<Point3d>& points
        )
{
    Mat T1 = (Mat_<double>(3,4)<<
            1,0,0,0,
            0,1,0,0,
            0,0,1,0);

    Mat T2 = (Mat_<double>(3,4)<<
            R.at<double>(0,0), R.at<double>(0,1), R.at<double>(0,2),t.at<double>(0,0),
            R.at<double>(1,0), R.at<double>(1,1), R.at<double>(1,2), t.at<double>(1,0),
            R.at<double>(2,0), R.at<double>(2,1), R.at<double>(2,2), t.at<double>(2,0)
            );


}