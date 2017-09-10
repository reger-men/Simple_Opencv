#include "opencv2/highgui.hpp"

using namespace cv;

int main(int argc, char* argv[])
{
	namedWindow("Original", WINDOW_NORMAL);
	Mat image = imread("./n01.png", 0);

	imshow("Original", image);

	waitKey(0);
	return 0;
}

