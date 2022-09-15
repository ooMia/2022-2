#pragma once
#include "opencv2/opencv.hpp"

class ColorHistogram {
private:
	int  histSize[3]; //각 차원의 크기
	float  hranges[2];
	const float* ranges[3];   //각 차원의 범위
	int channels[3];   //고려할 채널
public:
	ColorHistogram() {
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;
		hranges[1] = 255.0;
		ranges[0] = hranges;  ranges[1] = hranges;  ranges[2] = hranges;
		channels[0] = 0; channels[1] = 1;  channels[2] = 2;
	} //세 채널 
	void setSize(int size) {
		histSize[0] = histSize[1] = histSize[2] = size;
	}
	cv::Mat  getHistogram(const cv::Mat& image) {//1600만 컬러의 히스토그램
		cv::Mat  hist;
		//BGR 컬러 히스토그램
		hranges[0] = 0.0;   hranges[1] = 255.0;
		channels[0] = 0; channels[1] = 1;  channels[2] = 2;  //세 채널
		cv::calcHist(&image, 1, channels, cv::Mat(), hist, 3, histSize, ranges);
		return  hist;
	}      //채널 분리 후 채널 별 히스토그램 작성해서 사용
		   //BGR을 HSV로 변환 후 H 히스토
	cv::Mat  getHueHistogram(const cv::Mat& image) {
		cv::Mat  hist;   cv::Mat hue;
		cv::cvtColor(image, hue, cv::COLOR_BGR2HSV);
		hranges[0] = 0.0;   hranges[1] = 180.0;   channels[0] = 0;
		cv::calcHist(&hue, 1, channels, cv::Mat(), hist, 1, histSize, ranges);
		return  hist;
	}
	//채널 분리 후 채널 별 히스토그램 작성해서 사용
	cv::Mat  getHueHistogram(const cv::Mat& image, int minSat) {
		cv::Mat  hist;   cv::Mat hsv;
		cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);
		cv::Mat mask;
		if (minSat > 0) {
			std::vector<cv::Mat> v;  cv::split(hsv, v);
			cv::threshold(v[1], mask, minSat, 255, cv::THRESH_BINARY);
		}
		hranges[0] = 0.0;   hranges[1] = 180.0;   channels[0] = 0;
		cv::calcHist(&hsv, 1, channels, mask, hist, 1, histSize, ranges);
		return  hist;
	}
	cv::Mat  getHueHistogramImage(const  cv::Mat& image) {
		cv::Mat  hist = getHueHistogram(image);
		double  maxVal = 0, minVal = 0;
		cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);

		cv::Mat  histImg(histSize[0], histSize[0], CV_8U, cv::Scalar(255));
		int  hpt = static_cast<int>(0.9 * histSize[0]); // 최고높이가 총 빈 개수의 90%

		for (int h = 0; h < histSize[0]; h++) {
			float binVal = hist.at<float>(h);
			int intensity = static_cast<int>(hpt * binVal / maxVal);
			cv::line(histImg, cv::Point(h, histSize[0]), cv::Point(h, histSize[0] - intensity),
				cv::Scalar::all(0));
		}
		return histImg;
	}

};