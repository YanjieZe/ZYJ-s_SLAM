# ZYJ's SLAM

## 1. visualOdometry.h

> void find_feature_matches(
Mat& img_1, 
Mat& img_2,
vector<KeyPoint>& keypoints_1,
vector<KeyPoint>& keypoints_2, 
vector<DMatch>& good_matches)

封装了特征点提取以及匹配的功能

> void pose_estimation_2d2d(
        std::vector<KeyPoint> keypoints_1,
        std::vector<KeyPoint> keypoints_2,
        std::vector<DMatch> matches,
        Mat& K,
        Mat& R,
        Mat& t )
        
 封装了使用**对极约束**进行相机运动的求解的功能。
