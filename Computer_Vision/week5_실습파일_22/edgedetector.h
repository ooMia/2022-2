#pragma once

#define PI 3.141592
class EdgeDetector {
private:
    int  apeture;
    cv::Mat  sobelMagnitude, sobelDirection;
public:
    EdgeDetector() : apeture(3) { }
    void setApeture(int a) { 
        apeture = a; 
    }
    int  getApeture() const { 
        return  apeture; 
    }
    void computeSobel(const cv::Mat& image) {
        cv::Mat sobelX, sobelY;
        cv::Sobel(image, sobelX, CV_32F, 1, 0, apeture);
        cv::Sobel(image, sobelY, CV_32F, 0, 1, apeture);
        cv::cartToPolar(sobelX, sobelY, sobelMagnitude, sobelDirection);
    }
    cv::Mat  getMagnitude() { return  sobelMagnitude; }
    cv::Mat  getDirection() { return  sobelDirection; }
    cv::Mat  getBinaryMap(double  threshold) {
        cv::Mat  bin;
        cv::threshold(sobelMagnitude, bin, threshold, 255, cv::THRESH_BINARY_INV);
        return  bin;
    }
    cv::Mat getSobelImage() {
        cv::Mat  bin;
        double  minval, maxval;
        cv::minMaxLoc(sobelMagnitude, &minval, &maxval);
        sobelMagnitude.convertTo(bin, CV_8U, 255 / maxval);
        return  bin;
    }
    cv::Mat getSobelDirectionImage() {
        cv::Mat bin;  //1 gray-level = 2 degrees
        sobelDirection.convertTo(bin, CV_8U, 90 / PI);
        return  bin;
    }
};
