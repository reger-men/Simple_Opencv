#include <cstdint>;
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;


#pragma once
class Image
{

public:
	//Konstuktoren
	Image(const uint16_t M = 0, const uint16_t N = 0, const uint8_t value = 0);
	Image(const cv::Mat &img);
	
	//Kopierkonstruktor
	Image(const Image &obj);
	
	//Zuweisungsoperator
	Image& operator=(const Image& rechts);

	//Setzen der Bild daten mit einem OpenCV Bild
	bool setData(const cv::Mat &img);
	
	//Setzen eines OpenCV Bildes mit dem Inhalt dieser Klasse(fuer die Anzeige)
	bool getData(cv::Mat &img)const;
	
	//Grauwert an einer Position setzen
	bool setGrayLevel(const uint16_t u, const uint16_t v, const uint8_t value);
	
	//Gesamte Bild mit einem Wert belegen
	void initGrayLevel(const uint8_t value);
	
	//Grauwert an einer Position abfragen
	bool getGrayLevel(const uint16_t u, const uint16_t v, uint8_t &value) const;

	uint16_t breite() const { return M; };
	uint16_t hoehe()const { return N; };
	
	//Ist die Bild position inden Grenzen 0<=u<M && 0<=v<N
	bool valid(const uint16_t u, const uint16_t v)const;

	~Image();


	uint8_t *data;
protected:
	void allocateMemory();
	void freeMemory(); 
	
	uint16_t M;//Breite
	uint16_t N;//Hoehe
};