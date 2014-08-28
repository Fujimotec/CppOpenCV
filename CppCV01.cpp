#include <opencv2\opencv.hpp>
#include <opencv_lib.hpp>

using namespace cv;

int main(){
	Mat image;
	image = imread("img.jpg", 1);
	imshow("img", image);

	Mat gray(image.size().height, image.size().width, CV_8UC1);
	cvtColor(image, gray, CV_RGB2GRAY);
	imshow("gray", gray);

	Mat result;
	flip(gray, result, 0);
	imshow("flip", result);
	waitKey(0);

	return 0;
}
