#pragma once

using namespace std;

class LaplacianZC {
private:
    cv::Mat laplace;      
    int apeture;
    double  lapmin, lapmax;
public:
    LaplacianZC() : apeture(3) { }
    void  setApeture(int a) {
        apeture = a;
    }
    int  getApeture() { 
        return  apeture; 
    }
    cv::Mat  computeLaplacian(const cv::Mat& image) {
        cv::Laplacian(image, laplace, CV_32F, apeture);
        return  laplace;
    }
    cv::Mat  getLaplacianImage(double scale = -1) {
        if (scale < 0) {
            double  lapmin, lapmax;
            cv::minMaxLoc(laplace, &lapmin, &lapmax);
            scale = 127 / max(-lapmin, lapmax);
        }  //-127 ~ 127
        cv::Mat  laplacianImage; //영상 값을 0 ~ 255로 변환
        laplace.convertTo(laplacianImage, CV_8U, scale, 128);
        return  laplacianImage;
    }
    cv::Mat  getZeroCrossing(cv::Mat  laplace) {
        //threshold =0, negative value is black, positive value is white
        cv::Mat signImage;
       
        //cv::minMaxLoc(laplace, &lapmin, &lapmax);
        //cv::threshold(laplace, signImage, 0.05*max(-lapmin,lapmax), 255, cv::THRESH_BINARY);
        cv::threshold(laplace, signImage, 0, 255, cv::THRESH_BINARY);
        cv::Mat  binary;
        signImage.convertTo(binary, CV_8U);
        cv::Mat  dilated;
        cv::dilate(binary, dilated, cv::Mat());
        return  dilated - binary;
    }
    cv::Mat  getZeroCrossingDog(cv::Mat  dog) {
        //threshold =0, negative value is black, positive value is white
        cv::Mat signImage;
      
        //cv::minMaxLoc(dog, &lapmin, &lapmax);
        //cv::threshold(dog, signImage, 0.05 * max(-lapmin, lapmax), 255, cv::THRESH_BINARY);
        cv::threshold(laplace, signImage, 0, 255, cv::THRESH_BINARY);
        cv::Mat  binary;
        signImage.convertTo(binary, CV_8U);
        cv::Mat  dilated;
        cv::dilate(binary, dilated, cv::Mat());
        return  dilated - binary;
    }
};
