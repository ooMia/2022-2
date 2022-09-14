#include <iostream>
#include <opencv2/opencv.hpp>
#include "histogram.h"
#include "contentFinder.h"
#include "colorhistogram.h"

using namespace std;
using namespace cv;

int main() {
	cv::Mat  image = cv::imread("waves.jpg", 0);
	cv::Mat  imageROI = image(cv::Rect(369, 67, 25, 30)); //���� ����
	cv::imshow("Reference", imageROI);
	Histogram1D h;
	cv::Mat hist = h.getHistogram(imageROI);
	cv::imshow("Reference Hist", h.getHistogramImage(imageROI));
	waitKey(0);

	ContentFinder  finder;
	finder.setHistogram(hist);//����ȭ ������׷� 1����, channels[0] = 0;
	finder.setThreshold(-1.0f);//����ȭ �۾� ���
	cv::Mat result1;
	result1 = finder.find(image);  //������ ��(Ȯ�� ��)
	cv::Mat  tmp;    // ����(���� Ȯ��), ��ο�(���� Ȯ��)�� ǥ���� ����
	result1.convertTo(tmp, CV_8U, -1.0, 255.0); //���� ���� a*result+b
	cv::imshow("BackProjection result", tmp);
	waitKey(0);

	finder.setThreshold(0.12f); //Threshold =0.12*255
	result1 = finder.find(image);//����ȭ ������ ��

	cv::rectangle(image, cv::Rect(369, 67, 25, 30), cv::Scalar(0, 0, 0));
	cv::imshow("Image", image);

	cv::imshow("Detection Result", result1);
	cv::waitKey(0);
	
	//Color image detection

	ColorHistogram  hc;
	cv::Mat  color = cv::imread("waves.jpg");

	imageROI = color(cv::Rect(0, 0, 100, 45)); //Ǫ�� �ϴ� ����
	hc.setSize(8); //3���� 8x8x8  (ä�� �� 8 bins )
	cv::Mat shist = hc.getHistogram(imageROI);
	finder.setHistogram(shist); //�������� ���� ����ȭ ������׷� ����
	finder.setThreshold(0.05f);
	result1 = finder.find(color);
	cv::imshow("Color Detection Result", result1);

	cv::rectangle(color, cv::Rect(0, 0, 100, 45), cv::Scalar(0, 0, 0));
	imshow("Color", color);
	waitKey(0);



	return 0;
}
