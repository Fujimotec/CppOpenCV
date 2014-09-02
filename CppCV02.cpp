#include "opencv2\opencv.hpp"
#include "opencv_lib.hpp"

using namespace cv;
using namespace std;

void salt1(Mat &image, int n){
	for (int k = 0; k < n; k++){
		//rand() 乱数の発生
		int i = (int)(rand() % image.size().width);
		int j = (int)(rand() % image.size().height);
		if (image.channels() == 1){ //グレースケール
			image.data[image.step*j + i] = 255;
		}
		else { //カラー画像
			image.data[image.step*j + i * 3] = 255;
			image.data[image.step*j + i * 3 + 1] = 255;
			image.data[image.step*j + i * 3 + 2] = 255;
		}
	}
}

void salt2(Mat &image, int n){
	for (int k = 0; k < n; k++){
		//rand() 乱数の発生
		int i = (int)(rand() % image.size().width);
		int j = (int)(rand() % image.size().height);
		if (image.channels() == 1){ //グレースケール
			image.at<uchar>(j, i) = 255;
		}
		else { //カラー画像
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}
	}
}

int main(){
	Mat image = imread("img.jpg", 1);
	cout << image.channels() << endl;
	
	double t;
	t = getTickCount();
	salt2(image, 100);
	cout << (getTickCount() - t) / cvGetTickFrequency() << "[ms]" << endl;

	t = getTickCount();
	salt1(image, 100);
	cout << (getTickCount() - t) / cvGetTickFrequency() << "[ms]" << endl;

	imshow("image_salt", image);
	waitKey(0);
	return 0;
}
