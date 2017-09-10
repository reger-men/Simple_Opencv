#pragma once
#include "IProcessor.h"
class ResizerNearestNeighbor : public IProcessor
{
public:
	ResizerNearestNeighbor();
	~ResizerNearestNeighbor();
	static uint8_t * resizePixels(Image * pixels, int w1, int h1, int w2, int h2);
};

