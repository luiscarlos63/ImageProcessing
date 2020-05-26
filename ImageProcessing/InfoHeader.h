#pragma once

//lib includes
#include <iostream>
#include <stdint.h>
#include <fstream>

//my header includes


//my defines
#define RSETVALUE 0
#define INFOHRDIOFFSET 0x000E
#define	NINFODATA 0xcccc	

using namespace std;
//class InfoHeader
class InfoHeader
{
public:
	InfoHeader();
	InfoHeader(const InfoHeader&);

	//metodos publicos
	void Read(ifstream& file);
	void Write(ofstream& file);
	void validate();
	//gets
	uint32_t get_ImageSize() { return ImageSize; }
	uint32_t get_width() { return width; }
	uint32_t get_heigth() { return heigth; }

	//sets

	//friends
	friend ostream& operator<<(ostream& os, const InfoHeader& ihdr);


private:
	uint32_t size;
	uint32_t width;
	uint32_t heigth;
	uint16_t planes;
	uint16_t bitsPpixel;
	uint32_t compression;
	uint32_t ImageSize;
	uint32_t XpixelsPerM;
	uint32_t YpixelsPerM;
	uint32_t colorsUsed;
	uint32_t ImportantColors;
};

