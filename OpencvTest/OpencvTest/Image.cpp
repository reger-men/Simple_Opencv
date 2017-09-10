#include "Image.h"




Image::Image(const uint16_t M, const uint16_t N, const uint8_t value)
{
	//set init parameters.
	this->M = M;
	this->N = N;

	//Memory allocation.
	allocateMemory();

	//Gray value initialization. Data is until now Black.
	initGrayLevel(value);
}

Image::Image(const cv::Mat &img)
{
	//set init parameters.
	N = img.rows;
	M = img.cols;
	
	if (img.isContinuous())
	{
		allocateMemory();
		data = img.data;
	}
}

Image::Image(const Image& obj)
{
	if (data == NULL)
	{
		(*this).N = obj.hoehe();
		(*this).M = obj.breite();
		allocateMemory();
	}

	(*this).data = obj.data;
}

Image& Image::operator=(const Image& rechts)
{
	if (this != NULL)
	{
		if (this == &rechts) return *this;
		delete[] data; //freeing used memory
		(*this).data = rechts.data;
	}
	return *this;
}

bool Image::setData(const cv::Mat &img)
{
	if(img.rows != N || img.cols != M) return false;
	//else copy img data into data.
	data = img.data;
	return true;
}

bool Image::getData(cv::Mat &img) const
{
	if (img.rows != N || img.cols != M) return false;
	//else copy this data into img data.
	img.data = data;
	return true;
}

bool Image::setGrayLevel(const uint16_t u, const uint16_t v, const uint8_t value)
{
	if (!valid(u,v)) return false;
	//else set pixel value into the right position
	data[u*N + v*M] = value;
	return true;
}

bool Image::valid(const uint16_t u, const uint16_t v) const
{
	if ((u < 0 || u >= M) || (v < 0 || v >= N)) return false;
	return true;
}

Image::~Image()
{
	M = 0;
	N = 0;
	freeMemory();
}

void Image::allocateMemory()
{
	data = new uint8_t[N*M];
}

void Image::freeMemory()
{
	//delete data;
}

/*
* init image value.
*/
void Image::initGrayLevel(const uint8_t value)
{
	for (int i = 0; i < N*M; i++)
	{
		data[i] = value;
	}
}

bool Image::getGrayLevel(const uint16_t u, const uint16_t v, uint8_t &value) const
{
	if (!valid(u, v)) return false;
	//else get pixel value from the right position
	value = data[u*N + v*M];
	return true;
}
