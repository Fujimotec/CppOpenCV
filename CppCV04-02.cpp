#include "opencv2\opencv.hpp"
#include "opencv_lib.hpp"

int main(){
	cv::Mat image = cv::imread("img.jpg", 0);
	cv::Mat image2 = cv::imread("img2.jpg", 0);
	cv::Mat result(image.size(), 0);
	
	cv::imshow("image", image);
	cv::imshow("image2", image2);

	cv::add(image, image2, result);
	cv::imshow("add", result);
	cv::waitKey(0);
	cv::add(image, cv::Scalar(50), result);
	cv::imshow("add", result);
	cv::waitKey(0);
	cv::addWeighted(image, 0.7, image2, 0.1, 0, result);
	cv::imshow("add", result);
	cv::waitKey(0);
	cv::scaleAdd(image, 0.5, image2, result);
	cv::imshow("add", result);
	cv::waitKey(0);
	result = image*0.7 + image2*0.1;
	cv::imshow("add", result);
	cv::waitKey(0);

	return 0;
}
