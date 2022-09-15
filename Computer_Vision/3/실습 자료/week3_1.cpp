# include <iostream>
# include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("boldt.jpg");
	if (image.empty()) {
		cout << "Imag eis not loaded";
		return 0;
	}
	cv::Mat hsv;
	cv::cvtColor(image, hsv, COLOR_BGR2HSV);
	std::vector<cv::Mat>  channels;
	cv::split(hsv, channels);
	//channels[0] 색상(H),  channels[1]  채도(S),  channels[2]  명도(V)
	//각 채널 출력
	cv::imshow("Original", image);
	cv::imshow("Hue", channels[0]);
	cv::imshow("Saturate", channels[1]);
	cv::imshow("Value", channels[2]);
	cv::waitKey(0);

	channels[2] = 255;
	cv::merge(channels, hsv);
	cv::Mat newImage;
	cv::cvtColor(hsv, newImage, COLOR_HSV2BGR);
	cv::imshow("Fixed Value Image", newImage);
	cv::waitKey(0);
	return 0;
}