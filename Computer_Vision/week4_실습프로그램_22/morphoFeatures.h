#pragma once

class  MorphoFeatures {
private:
    int  threshold;
    void applyThreshold(cv::Mat& result) {
        if (threshold > 0)
            cv::threshold(result, result, threshold, 255, cv::THRESH_BINARY_INV);
    }
public:
    void setThreshold(int t) { 
        threshold = t; 
    }
    cv::Mat  getEdges(const  cv::Mat& image) {
        cv::Mat  result;
        cv::morphologyEx(image, result, cv::MORPH_GRADIENT, cv::Mat());
        applyThreshold(result);
        return  result;
    }
};