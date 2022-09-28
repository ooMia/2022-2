#include "opencv2/opencv.hpp"
#include "morphoCornerFeatures.h"

using namespace cv;


int main() {
	cv::Mat  image = cv::imread("./media/building.jpg", 0);
	cv::imshow("Image", image);
	MorphoFeatures  morpho;
	morpho.setThreshold(40);
	cv::Mat  edges;
	edges = morpho.getEdges(image);
	cv::imshow("Edge Image", edges);
	cv::waitKey(0);  
	
	morpho.setThreshold(-1);
	cv::Mat  corners;
	corners = morpho.getCorners(image);
	cv::imshow("AbsDifference Image", corners);
	cv::waitKey(0);

	cv::morphologyEx(corners, corners, cv::MORPH_TOPHAT, cv::Mat());
	//dst = src – open(src, kernel): 작은점(코너)이 제거된 영상을 빼줌
	cv::imshow("Corner Candidate", corners);
	waitKey(0);
	
	cv::threshold(corners, corners, 40, 255, cv::THRESH_BINARY_INV);
	cv::imshow("Corner Image", corners);
	cv::waitKey(0);

	morpho.drawOnImage(corners, image);
	cv::imshow("Corners on Image", image);
	cv::waitKey(0);

	return 0;
}
