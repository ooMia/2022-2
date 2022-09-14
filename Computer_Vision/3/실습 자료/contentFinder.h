#pragma once
#include "opencv2/opencv.hpp"

class ContentFinder {
private:  //histogram parameters
	float  hranges[2];
	const  float* ranges[3];
	int  channels[3];
	float  threshold;
	cv::Mat  histogram;
	cv::SparseMat  shistogram; //only non-zero elements are stores
	bool  isSparse;
public:
	ContentFinder() : threshold(0.1f), isSparse(false) {
		ranges[0] = hranges;  ranges[1] = hranges;  ranges[2] = hranges;
	} //channels
	void setThreshold(float t) { 
		threshold = t; 
	}
	float getThreshold() { 
		return  threshold; 
	}
	void setHistogram(const  cv::Mat& h) {
		isSparse = false;  cv::normalize(h, histogram, 1.0);
	}
	void setHistogram(const  cv::SparseMat& h) {
		isSparse = true;  cv::normalize(h, shistogram, 1.0, cv::NORM_L2);
	}
	//계속
	cv::Mat  find(const  cv::Mat& image) {
		cv::Mat  result;
		hranges[0] = 0.0;   hranges[1] = 255.0;
		channels[0] = 0; channels[1] = 1;  channels[2] = 2;  //세 채널
		return find(image, hranges[0], hranges[1], channels);
	}
	cv::Mat  find(const cv::Mat& image, float minValue, float maxValue, int* channels) {
		cv::Mat  result;
		hranges[0] = minValue;   hranges[1] = maxValue;
		if (isSparse) {
			for (int i = 0; i < shistogram.dims(); i++) this->channels[i] = channels[i];
			cv::calcBackProject(&image, 1, channels, shistogram, result, ranges, 255.0);
		}
		else {
			for (int i = 0; i < histogram.dims; i++) this->channels[i] = channels[i];
			cv::calcBackProject(&image, 1, channels, histogram, result, ranges, 255.0);
		}
		if (threshold > 0)  cv::threshold(result, result, 255.0 * threshold, 255.0, cv::THRESH_BINARY);
		return  result;
	}
};
