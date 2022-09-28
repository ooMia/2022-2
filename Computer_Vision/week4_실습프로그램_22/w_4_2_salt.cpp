#include <random>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void salt(cv::Mat image, int n) {
    default_random_engine  generator;
    uniform_int_distribution<int> randomRow(0, image.rows - 1);
    uniform_int_distribution<int> randomCol(0, image.cols - 1);
    int i, j;
    for (int k = 0; k < n; k++) {
        j = randomRow(generator);
        i = randomCol(generator);  //j=y, i=x
        if (image.type() == CV_8UC1) {
            image.at<uchar>(j, i) = 255;
        }
        else if (image.type() == CV_8UC3) {        //컬러 영상인 경우
            image.at<cv::Vec3b>(j, i)[0] = 255;
            image.at<cv::Vec3b>(j, i)[1] = 255;
            image.at<cv::Vec3b>(j, i)[2] = 255;
        }
    }
}

int main() {
    cv::Mat image = cv::imread("D:/CV_EXER/boldt.jpg");
    imshow("Original", image);
    salt(image, 3000);
    cv::imshow("Image", image);
    waitKey(0);

    cv::imwrite("salted.bmp", image);
    image = cv::imread("salted.bmp",0); 
    //칼라로 읽어서 필터를 적용해 볼 것
    
    cv::Mat result;
    GaussianBlur(image, result, cv::Size(5, 5), 1.5);
    cv::imshow("Gaussian Filtered", result);
    cv::waitKey(0);
    cv::medianBlur(image, result, 5);
    cv::imshow("Median Filtered", result);
    cv::waitKey(0);

    return 0;
}