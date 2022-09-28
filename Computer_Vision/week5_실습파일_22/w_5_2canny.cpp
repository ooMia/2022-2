#include "opencv2/opencv.hpp"
#include "edgedetector.h"

using namespace cv;

int main() {
	cv::Mat  image = cv::imread("D:/CV_EXER/road.jpg", 0);
	cv::imshow("Image", image);
	EdgeDetector  ed;
	ed.computeSobel(image);
	cv::imshow("Sobel(Direction)", ed.getSobelDirectionImage());
	cv::waitKey();
	cv::imshow("Sobel(low)", ed.getBinaryMap(125));   cv::waitKey();
	cv::imshow("Sobel(high))", ed.getBinaryMap(350));   cv::waitKey();
	cv::Mat contours;
	cv::Canny(image, contours, 125, 350);
	cv::imshow("Canny", 255 - contours);
	cv::waitKey();
	return 0;
}
