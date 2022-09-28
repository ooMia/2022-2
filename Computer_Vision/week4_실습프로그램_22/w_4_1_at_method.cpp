#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

	cv::Mat A(3, 3, CV_32F); int idx[2];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A.at<float>(i, j) = i * A.cols + j;
		}
		printf("%dth element %f  %f  %f\n",
			i, A.at<float>(i, 0), A.at<float>(i, 1), A.at<float>(i, 2));
	}

	
	// A.at<float>(cv::Point(j,i))=i*A.cols+j;
	//idx[0]=i; idx[1]=j;  A.at<float>(idx)=i*A.cols+j;
	cv::Mat  B = cv::imread("D:/CV_EXER/puppy.bmp", 1); //CV_8UC3
	imshow("original", B);
	for (int i = 0; i < B.cols; i++) {
		for (int j = 0; j < B.rows; j++) {
			B.at<cv::Vec3b>(j, i)[0] = 255;   //j=y, i=x
			B.at<cv::Vec3b>(j, i)[1] = 0;
			B.at<cv::Vec3b>(j, i)[2] = 0;
		}
	}
	imshow("after", B);

	waitKey(0);
	
	return 0;

}