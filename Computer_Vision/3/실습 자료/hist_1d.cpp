#include <iostream>
#include <opencv2/opencv.hpp>
#include "histogram.h"

using namespace std;
int main() {
	cv::Mat  image = cv::imread("D:/CV_EXER/group.jpg", 0);
	if (!image.data)  return 0;
	cv::imshow("Image", image);

	Histogram1D   h;
	cv::Mat  histo = h.getHistogram(image);

	for (int i = 0; i < 256; i++)
		cout << "Value " << i << "=" << histo.at<float>(i) << endl;
	cv::imshow("Histogram", h.getHistogramImage(image));
	cv::waitKey(0);
	return 0;
}