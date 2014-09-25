#include "opencv2\opencv.hpp"
#include "opencv_lib.hpp"

void sharpen2D(const cv::Mat &image, cv::Mat &result){
	//Construct kernel
	cv::Mat kernel(3, 3, CV_32F, cv::Scalar(0));
	//assigns kernel values
	kernel.at<float>(1, 1) = 5.0;
	kernel.at<float>(0, 1) = -1.0;
	kernel.at<float>(2, 1) = -1.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(1, 2) = -1.0;

	//filter the image
	cv::filter2D(image, result, image.depth(), kernel);
}

int main(){
	cv::Mat image = cv::imread("img.jpg", 0);
	cv::Mat result(image.rows, image.cols, 0);

	sharpen2D(image, result);
	cv::imshow("image", image);
	cv::imshow("sharpen2D", result);
	cv::waitKey(0);

	return 0;
}
