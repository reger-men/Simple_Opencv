#include "ResizerNearestNeighbor.h"



ResizerNearestNeighbor::ResizerNearestNeighbor()
{
}

uint8_t* ResizerNearestNeighbor::resizePixels(Image* pixels, int w1, int h1, int w2, int h2) {
	uint8_t * temp;
	temp = new uint8_t[w2 * h2];
	double x_ratio = w1 / (double)w2;
	double y_ratio = h1 / (double)h2;
	double px, py;
	for (int i = 0; i<h2; i++) {
		for (int j = 0; j<w2; j++) {
			px = floor(j*x_ratio);
			py = floor(i*y_ratio);
			temp[(i*w2) + j] = pixels->data[(int)((py*w1) + px)];
		}
	}
	return temp;
}


bool IProcessor::process(const Image& input, Image& output)
{
	uint8_t* ret = ResizerNearestNeighbor::resizePixels(input, input.breite(), input.hoehe(), 512, 512);
	return false;
}



