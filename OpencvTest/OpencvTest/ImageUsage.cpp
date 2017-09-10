#include "Image.h"
#include "ResizerNearestNeighbor.h"


/// Global variables
Mat src;
Image *img1, *img2, *img3, *img4, *img5;


void displayImg(Image &img, String title)
{
	Mat outMat;
	outMat.create(img.hoehe(), img.breite(), CV_8U);
	img.getData(outMat);

	namedWindow(title, WINDOW_AUTOSIZE);
	imshow(title, outMat);
}


/**
* @function main
* call from command prompt like: thisSolution.exe p01.png
*/
int main(int, char** argv)
{
	/// Load an image
	src = imread(argv[1], CV_8U);

	if (src.empty())
	{
		return -1;
	}
	
	//test first constructor.
	img1 = new Image(64, 64, 255);
	displayImg(*img1, "Test1");


	//test second constructor (Mat as parameter).
	img2 = new Image(src);
	displayImg(*img2, "Test2");
	

	//test assignment (Image as parameter).
	img3 = new Image(src.cols, src.rows, 0);
	*img3 = *img2;
	displayImg(*img3, "Test3");


	//test Copy constructor (Image as parameter).
	img4 = new Image(*img2);
	displayImg(*img4, "Test4");
	
	//test ResizerNearestNeighbor (Image as parameter).
	uint16_t desire_N = 512;
	uint16_t desire_M = 512;
	img5 = new Image(desire_M, desire_N, 0);
	Mat outMat;
	outMat.create(img2->hoehe(), img2->breite(), CV_8U);
	img2->getData(outMat);

	uint8_t* outresize;
	outresize = ResizerNearestNeighbor::resizePixels(&outMat, img2->breite(), img2->hoehe(), 512, 512);

	cv::Mat dummy_query = cv::Mat(512, 512, CV_32F, outresize);
	namedWindow("title", WINDOW_AUTOSIZE);
	imshow("title", dummy_query);
	

	waitKey(0);



	return 0;
}

