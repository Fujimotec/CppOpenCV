#include "opencv2\opencv.hpp"
#include "opencv_lib.hpp"

int main(){
	cv::Mat image = cv::imread("img.jpg", 0);
	cv::Mat result(image.size(), 0);
	cv::Mat logo = cv::imread("logo.jpg", 0);
	// define image ROI
	cv::Mat imageROI;
	imageROI = image(cv::Rect(150, 150, logo.cols, logo.rows));
	// add logo to image
	cv::addWeighted(imageROI, 1.0, logo, 0.3, 0., imageROI);
	cv::imshow("ROI", imageROI);
	cv::waitKey(0);
	cv::imshow("image", image); //再表示でROIが反映、Resetする必要ない
	cv::waitKey(0);
	return 0;
}
