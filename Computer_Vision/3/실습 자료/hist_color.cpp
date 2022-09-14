#include <iostream>
#include "opencv2/opencv.hpp"
#include "colorhistogram.h"

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("D:/CV_EXER/group.jpg");
	if (!image.data)  return 0;
	cv::imshow("Image", image);

	ColorHistogram   h;
	cv::Mat  histimg = h.getHueHistogramImage(image);
	imshow("Hue Histogram", histimg);
	waitKey(0);
	return 0;

}