# ZYJ's SLAM

## 1. visualOdometry.h

### （1）特征点匹配
> void find_feature_matches(
Mat& img_1, 
Mat& img_2,
vector<KeyPoint>& keypoints_1,
vector<KeyPoint>& keypoints_2, 
vector<DMatch>& good_matches)

封装了特征点提取以及匹配的功能

### （2）对极约束
> void pose_estimation_2d2d(
        std::vector<KeyPoint> keypoints_1,
        std::vector<KeyPoint> keypoints_2,
        std::vector<DMatch> matches,
        Mat& K,
        Mat& R,
        Mat& t )
        
 封装了使用**对极约束**进行相机运动的求解的功能。
 
 ### （3）三角测量
 >void triangulation(
        const vector<KeyPoint>& keypoint_1,
        const vector<KeyPoint>& keypoint_2,
        const std::vector<DMatch>& matches,
        const Mat& K,
        const Mat& R,
        const Mat& t,
        vector<Point3d>& points
);

利用**三角测量**获得三维空间中的点的坐标
 
###  (4)像素坐标转化到相机坐标

> Point2d pixel2cam ( const Point2d& p, const Mat& K )


