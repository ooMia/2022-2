#pragma once
#include <opencv2/opencv.hpp>

class Histogram1D {
private:
	int  histSize[1];
	float  hranges[2];
	const float* ranges[1];
	int channels[1];
public:
	Histogram1D() {
		histSize[0] = 256;
		hranges[0] = 0.0;
		hranges[1] = 255.0;
		ranges[0] = hranges;
		channels[0] = 0;
	}
	//계속
	cv::Mat  getHistogram(const cv::Mat& image) {
		cv::Mat  hist;
		cv::calcHist(&image, 1, channels, cv::Mat(), hist, 1, histSize, ranges);
		return  hist;
	}

	cv::Mat  getHistogramImage(const  cv::Mat& image) {
		cv::Mat  hist = getHistogram(image);
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
