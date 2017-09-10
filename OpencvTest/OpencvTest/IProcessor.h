#pragma once
#include "Image.h"

class IProcessor
{
public:
	virtual bool process(const Image& input, Image& output);
protected:
	IProcessor() {};
};


	