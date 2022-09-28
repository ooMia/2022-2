#include "opencv2/opencv.hpp"

using namespace cv;

int main() {
	cv::Mat  image = cv::imread("D:/CV_EXER/binary.bmp");
	cv::imshow("Binary", image);
	cv::waitKey(0);
	
	cv::Mat  eroded;
	cv::erode(image, eroded, cv::Mat());
	//cv::erode(image, eroded, cv::Mat(), cv::Point(-1, -1), 3);
		cv::Mat  dilated;
	cv::dilate(image, dilated, cv::Mat());
	//������ �� �� ħ��/��â���� ����� �� ��
	cv::imshow("Erode", eroded);
	cv::waitKey(0);
	cv::imshow("Dilate", dilated);
	cv::waitKey(0);  
	//����, �ݱ⵵ �ǽ��� �� ��
	//����
	//�ݱ�

	return 0;
}
