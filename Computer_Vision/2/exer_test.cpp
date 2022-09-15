#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cout << "HELLOW" << std::endl;
	cv::Mat image;
	image = cv::imread("D:/CV_EXER/puppy.bmp");
	if (image.empty()) {
		cout << "Image unloaded" << endl; return 0;
	}
	cout << "Image size is " << image.rows << " x " << image.cols << endl;
	cv::namedWindow("New");
	cv::imshow("New", image);
	cv::waitKey(0);
	return 0;
}