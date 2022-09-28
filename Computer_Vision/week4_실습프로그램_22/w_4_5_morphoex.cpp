#include "opencv2/opencv.hpp"
#include "morphoFeatures.h"

using namespace cv;

int main() {
	cv::Mat  image = cv::imread("D:/CV_EXER/building.jpg", 0);
	cv::imshow("Image", image);
	waitKey(0);

	MorphoFeatures  morpho;
	morpho.setThreshold(40);
	cv::Mat  edges;
	edges = morpho.getEdges(image);
	cv::imshow("Edge Image", edges);
	cv::waitKey(0);  
	return 0;
}
