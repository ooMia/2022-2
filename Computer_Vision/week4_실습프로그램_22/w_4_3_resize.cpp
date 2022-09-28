#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	cv::Mat  image = cv::imread("D:/CV_EXER/boldt.jpg", 0);
	cv::imshow("Image", image);
	
	//Mean Filter
	cv::Mat  result;
	cv::blur(image, result, cv::Size(5, 5));
	cv::imshow("Mean Filter", result);
	cv::waitKey();
	//Gaussian Filter
	cv::GaussianBlur(image, result, cv::Size(5, 5), 1.5);
	cv::imshow("Gaussian", result);
	cv::waitKey();  
	
	cv::Mat  newImage;
	cv::Mat  reduced(image.rows / 4, image.cols / 4, CV_8U);
	for (int i = 0; i < reduced.rows; i++)
		for (int j = 0; j < reduced.cols; j++)
			reduced.at<uchar>(i, j) = image.at<uchar>(i * 4, j * 4);
	
	cv::resize(reduced, newImage, cv::Size(), 2, 2, cv::INTER_NEAREST);
	cv::imshow("Badly reduced", newImage);

	cv::Mat  reduced2(image.rows / 4, image.cols / 4, CV_8U);
	cv::resize(image, reduced2, cv::Size(), 1.0 / 4.0, 1.0 / 4.0);//default
	cv::resize(reduced2, newImage, cv::Size(), 2, 2, cv::INTER_NEAREST);
	cv::imshow("Bilinear reduced", newImage);
	waitKey(0);

	cv::resize(reduced, newImage, cv::Size(), 3, 3, cv::INTER_NEAREST);
	cv::imshow("Badly reduced resizing", newImage);
	cv::resize(reduced2, newImage, cv::Size(), 3, 3, cv::INTER_NEAREST);
	cv::imshow("Nearest Neighbor resizing", newImage);
	cv::waitKey();
	cv::resize(reduced2, newImage, cv::Size(), 3, 3, cv::INTER_LINEAR);
	cv::imshow("Bilinear resizing", newImage);
	cv::waitKey();

	return 0;
}
