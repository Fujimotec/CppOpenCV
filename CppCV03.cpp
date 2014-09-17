#include "opencv2\opencv.hpp"
#include "opencv_lib.hpp"

// Get the feature points from the computed corner map
void getCorners(std::vector<cv::Point> &points,
	const cv::Mat& cornerMap) {
	// Iterate over the pixels to obtain all features
	for (int y = 0; y < cornerMap.rows; y++) {
		const uchar* rowPtr = cornerMap.ptr<uchar>(y);
		for (int x = 0; x < cornerMap.cols; x++) {
			// if it is a feature point
			if (rowPtr[x]) {
				points.push_back(cv::Point(x, y));
			}
		}
	}
}

// Draw circles at feature point locations on an image
void drawOnImage(cv::Mat &image,
	const std::vector<cv::Point> &points,
	cv::Scalar color = cv::Scalar(255, 255, 255),
	int radius = 3, int thickness = 2) {
	std::vector<cv::Point>::const_iterator it =
		points.begin();
	// for all corners
	while (it != points.end()) {
		// draw a circle at each corner location
		cv::circle(image, *it, radius, color, thickness);
		++it;
	}
}

int main(){
	cv::Mat image = cv::imread("img.jpg", 0);
	
	// Detect Harris Corners
	cv::Mat cornerStrength/*(image.size().height, image.size().height, CV_32FC1)*/;
	cv::cornerHarris(image, cornerStrength,
		3, // neighborhood size
		3, // aperture size
		0.01, // Harris parameter
		4);

	// image of local maxima (internal)
	cv::Mat localMax;
	// local maxima detection
	cv::Mat dilated; // temporary image
	cv::dilate(cornerStrength, dilated, cv::Mat());
	cv::compare(cornerStrength, dilated,
		localMax, cv::CMP_EQ);

	cv::Mat cornerMap;
	cv::Mat cornerTh;

	// thresholding the corner strength
	// calculated threshold (internal)
	double threshold = 0.0001;
	cv::threshold(cornerStrength, cornerTh,
		threshold, 255, cv::THRESH_BINARY);
	// convert to 8-bit image
	cornerTh.convertTo(cornerMap, CV_8U);
	// non-maxima suppression
	cv::bitwise_and(cornerMap, localMax, cornerMap);

	// Detect Harris corners
	std::vector<cv::Point> pts;
	// Get the corners
	getCorners(pts, cornerMap);

	// Draw Harris corners
	drawOnImage(image, pts);

	cv::imshow("image", image);
	cv::waitKey(0);

	return 0;
}
