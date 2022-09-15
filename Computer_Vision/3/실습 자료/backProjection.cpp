#include <iostream>
#include <opencv2/opencv.hpp>
#include "histogram.h"
#include "contentFinder.h"
#include "colorhistogram.h"

using namespace std;
using namespace cv;

int main() {
	cv::Mat  image = cv::imread("waves.jpg", 0);
	cv::Mat  imageROI = image(cv::Rect(369, 67, 25, 30)); //구름 영역
	cv::imshow("Reference", imageROI);
	Histogram1D h;
	cv::Mat hist = h.getHistogram(imageROI);
	cv::imshow("Reference Hist", h.getHistogramImage(imageROI));
	waitKey(0);

	ContentFinder  finder;
	finder.setHistogram(hist);//정규화 히스토그램 1차원, channels[0] = 0;
	finder.setThreshold(-1.0f);//이진화 작업 취소
	cv::Mat result1;
	result1 = finder.find(image);  //역투영 맵(확률 맵)
	cv::Mat  tmp;    // 밝음(낮은 확률), 어두움(높은 확률)로 표시해 보자
	result1.convertTo(tmp, CV_8U, -1.0, 255.0); //반전 영상 a*result+b
	cv::imshow("BackProjection result", tmp);
	waitKey(0);

	finder.setThreshold(0.12f); //Threshold =0.12*255
	result1 = finder.find(image);//이진화 역투영 맵

	cv::rectangle(image, cv::Rect(369, 67, 25, 30), cv::Scalar(0, 0, 0));
	cv::imshow("Image", image);

	cv::imshow("Detection Result", result1);
	cv::waitKey(0);
	
	//Color image detection

	ColorHistogram  hc;
	cv::Mat  color = cv::imread("waves.jpg");

	imageROI = color(cv::Rect(0, 0, 100, 45)); //푸른 하늘 영역
	hc.setSize(8); //3차원 8x8x8  (채널 당 8 bins )
	cv::Mat shist = hc.getHistogram(imageROI);
	finder.setHistogram(shist); //역투영에 사용될 정규화 히스토그램 생성
	finder.setThreshold(0.05f);
	result1 = finder.find(color);
	cv::imshow("Color Detection Result", result1);

	cv::rectangle(color, cv::Rect(0, 0, 100, 45), cv::Scalar(0, 0, 0));
	imshow("Color", color);
	waitKey(0);



	return 0;
}
