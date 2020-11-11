#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("C:/Users/DELL/Desktop/0.jpg", 1);
	if (srcMat.empty()) return-1;
	float angle = -10.0, scale = 1;
	cv::Point2f center(srcMat.cols / 2.0, srcMat.rows / 2.0);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, scale);
	cv::Rect bbox = cv::RotatedRect(center, srcMat.size(), angle).boundingRect();
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	cv::warpAffine(srcMat, dstMat, rot, bbox.size());
	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);

}