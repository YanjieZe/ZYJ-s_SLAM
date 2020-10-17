//
// Created by zyj on 10/17/20.
//

#ifndef FEATURE_EXTRACTION_VISUALODOMETRY_H
#define FEATURE_EXTRACTION_VISUALODOMETRY_H

# include <iostream>
# include <opencv2/core/core.hpp>
# include <opencv2/features2d/features2d.hpp>
# include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void find_feature_matches(Mat& img_1, Mat& img_2,vector<KeyPoint>& keypoints_1,vector<KeyPoint>& keypoints_2, vector<DMatch>& good_matches);

#endif //FEATURE_EXTRACTION_VISUALODOMETRY_H
