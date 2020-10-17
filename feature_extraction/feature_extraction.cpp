//
// Created by zyj on 10/17/20.
//

#include "visualOdometry.h"

void find_feature_matches(Mat& img_1, Mat& img_2,vector<KeyPoint>& keypoints_1,vector<KeyPoint>& keypoints_2, vector<DMatch>& good_matches)
{
    //0 create ORB feature extraction

    Mat descriptors_1, descriptors_2;
    Ptr<ORB> orb = ORB::create(500, 1.2f, 8, 31, 0, 2, ORB::HARRIS_SCORE, 31, 20);

    //1 detect keypoints
    orb->detect(img_1, keypoints_1);
    orb->detect(img_2, keypoints_2);

    //2 computer descriptors
    orb->compute( img_1, keypoints_1, descriptors_1);
    orb->compute(img_2, keypoints_2, descriptors_2);

    //show keypoints
    Mat outimg1;
    drawKeypoints(img_1,keypoints_1,outimg1,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
//    imshow("ORB Keypoints", outimg1);

    //3 match points
    vector<DMatch> matches;
    BFMatcher matcher(NORM_HAMMING);
    matcher.match(descriptors_1,descriptors_2,matches);

    //4 choose good points
    double min_dist=10000, max_dist=0;
    for (int i=0; i<descriptors_1.rows; i++)
    {
        double dist = matches[i].distance;
        if (dist < min_dist) min_dist = dist;
        if (dist > max_dist) max_dist = dist;
    }
    printf("-- Max dist: %f \n", max_dist);
    printf("-- Min dist: %f \n", min_dist);


    for( int i=0; i<descriptors_1.rows; i++)
    {
        if(matches[i].distance <= max(2*min_dist, 30.0))
        {
            good_matches.push_back(matches[i]);
        }
    }

    //5 draw
    Mat img_match;
    Mat img_goodmatch;
    drawMatches(img_1, keypoints_1, img_2, keypoints_2, matches, img_match);
    drawMatches(img_1, keypoints_1, img_2, keypoints_2, good_matches, img_goodmatch);

//    imshow("all match points:", img_match);
    imshow("good match points", img_goodmatch);
    waitKey(0);

}