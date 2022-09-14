#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	
	//Point_ Class
	cout << "hellow Opencv" << endl;
	Point pt(2, 3), pt1(4, 5);
	Point pt2 = pt + pt1;
	cout << "pt2 = " << pt2 << endl;
	cout << "dot product " << pt.dot(pt1) << endl;


	//Point3_ Class
	Point3f pt3(1.0f, 0.0f, 0.0f);
	cout << "[pt3] " << pt3 << endl;

	//Size_Class
	Size sz(320, 240);
	cout << "Size=" << sz << " 면적=" << sz.area() << endl;
	
	/*
	//Rect
	Mat img(300, 500, CV_8UC1, Scalar(255));
	Point2f  center(250, 150), pts[4];
	Size2f  size(300, 100);
	RotatedRect  rot_Rect(center, size, 20);
	Rect bound_Rect = rot_Rect.boundingRect();
	rectangle(img, bound_Rect, Scalar(0), 1);//그릴 대상 영상, 그릴 사각형, 색상, 두께
	circle(img, rot_Rect.center, 1, Scalar(0), 2);// center, radius, color, thickness
	rot_Rect.points(pts);
	for (int i = 0; i<4; i++) {
		circle(img, pts[i], 4, Scalar(0), 2);
		line(img, pts[i], pts[(i + 1) % 4], Scalar(0), 1);
	}
	imshow("사각형", img);
	waitKey(0);
	*/
	/*
	//Matx_ Class
	Matx<float, 2, 3>  A(1, 2, 3, 4, 5, 6); // Matx23f  A(1,2,3,4,5,6);
	cout<< "A = " << A << endl;
	Matx33f  B = Matx33f::eye();
	cout << "Identity "<<endl<< B << endl;

	//Vec Class
	Vec<float, 3> X(1, 0, 1);
	Vec3f  X1(1, 2, 3);  //Vec3f  X(1,0,1);
	
	cout << "X = " << (Mat)X << endl;
	cout << "X1 = " << X1 << endl;

	//Scalar_ Class
	Scalar_<uchar> S3;   
	S3=S3.all(255); //(255, 255, 255, 255)
	cout << "S3 = " <<endl<< (Mat)S3 << endl;
	*/
	/*
	//Mat Class
	Mat B1(3, 3, CV_8U, 1); //1로 각각초기화
	Mat C1(3, 3, CV_8U, Scalar(2)); //2로 각각초기화
	
	cout << "B1 = " << B1 << endl;
	cout << "C1 = " << C1 << endl;
	
	Mat D1 = B1 + C1;  
	cout << "D1 = " << D1 << endl;
	
	Mat E1 = B1;  E1 = 10;
	cout << "B1 = " << B1 << endl;;


	Mat E2(2, 3, CV_8UC1); //2x3 행렬
	Mat F2(2, 3, CV_8UC1, Scalar(0)); //0으로 초기화된 2x3행렬
	Mat  C2(2, 3, CV_8UC3, Scalar(1, 2, 3));//각원소가 CV_8UC3
	float data[] = { 1,2,3,4,5,6 };
	Mat  D2(Size(3, 2), CV_32FC1, data);
	cout << "E2 = " << (Mat)E2 << endl;
	cout << "F2 = " << F2 << endl;
	cout << "C2 = " << C2 << endl;
	cout << "D2 = " << D2 << endl;
	//
	Mat G(2, 3, CV_32FC1, Scalar(0));//0으로 초기화된 2x3 행렬 생성
	Mat H; H.create(2, 3, CV_32FC1);// 임의의 값으로 초기화 된 2x3 행렬 생성
	Mat K; K.create(Size(3, 2), CV_8UC1);// 임의의 값으로 초기화 된 2x3 행렬
	//Size 원소는 width, height = > cols, rows
	Mat M;
	int size1[] = { 3,3 };
	M.create(2, size1, CV_8UC1);
	
	cout << "G = " << G << endl;
	cout << "H = " << H << endl;
	cout << "K = " << K << endl;
	cout << "M = " << M << endl;
	*/

	/*
	//Image 입출력
	cv::Mat  image;
	image = cv::imread("puppy.bmp");
	if (image.empty()) {
		cout << "Image unloaded" << endl;
		return 0;
	}
	cout << "The image size is " << image.rows << " x " << image.cols << endl;
	cv::namedWindow("Original Image");
	
	//void circle(Mat& img, Point center, int radius, const Scalar& color,
	//	int thickness = 1, int lineType = 8, int shift = 0)
	cv::circle(image, cv::Point(155, 110), 65, 0, 3);
	cv::putText(image, "This is a dog.", cv::Point(40, 200), cv::FONT_HERSHEY_PLAIN, 2.0, 255, 2);//
	cv::Mat  logo = cv::imread("logo.bmp");
	cv::Mat mask = cv::imread("logo.bmp", 0);

	cv::Mat  imageROI(image, cv::Rect(image.cols - logo.cols, image.rows - logo.rows, logo.cols, logo.rows));
	//Mat::Mat(const Mat& m, const Rect& roi)
	cv::imshow("ROI Image", imageROI);
	logo.copyTo(imageROI, mask);//복사 생성자로 imageROI 생성:image와 메모리 공유

	cv::imshow("Original Image", image);
	cv::waitKey(0);  //int waitKey(int delay);

	cv::Mat result;
	cv::flip(image, result, 1);
	cv::imshow(" Output Image ", result);
	vector<int> param_jpg={ IMWRITE_JPEG_QUALITY, 30 };
	//param_jpg.push_back(IMWRITE_JPEG_QUALITY);
	//param_jpg.push_back(50);
	cv::imwrite("output_30.jpg ", result, param_jpg);
	cv::waitKey(0);

	Mat image_jpg = cv::imread("output_30.jpg");
	cv::imshow(" Output Image_jpg ", image_jpg);
	cv::waitKey(0);
	*/

	return 0;


}