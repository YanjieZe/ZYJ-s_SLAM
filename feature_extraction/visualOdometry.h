//
// Created by zyj on 10/17/20.
//

#ifndef FEATURE_EXTRACTION_VISUALODOMETRY_H
#define FEATURE_EXTRACTION_VISUALODOMETRY_H

# include <iostream>
# include <opencv2/core/core.hpp>
# include <opencv2/features2d/features2d.hpp>
# include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d.hpp>

using namespace std;
using namespace cv;

void find_feature_matches(
        Mat& img_1,
        Mat& img_2,
        vector<KeyPoint>& keypoints_1,
        vector<KeyPoint>& keypoints_2,
        vector<DMatch>& good_matches);

void pose_estimation_2d2d(
        std::vector<KeyPoint> keypoints_1,
        std::vector<KeyPoint> keypoints_2,
        std::vector<DMatch> matches,
        Mat& K,
        Mat& R,
        Mat& t );

void triangulation(
        const vector<KeyPoint>& keypoint_1,
        const vector<KeyPoint>& keypoint_2,
        const std::vector<DMatch>& matches,
        const Mat& K,
        const Mat& R,
        const Mat& t,
        vector<Point3d>& points
)

#endif //FEATURE_EXTRACTION_VISUALODOMETRY_H
