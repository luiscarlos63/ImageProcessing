#include "InfoHeader.h"


InfoHeader::InfoHeader()
	:size(RSETVALUE), width(RSETVALUE), heigth(RSETVALUE), planes(RSETVALUE),
		bitsPpixel(RSETVALUE), compression(RSETVALUE), XpixelsPerM(RSETVALUE),
			YpixelsPerM(RSETVALUE), colorsUsed(RSETVALUE), ImportantColors(RSETVALUE)
{
}

InfoHeader::InfoHeader(const InfoHeader& iHdr_cpy)
{
	*this = iHdr_cpy;
}

/*
*LER O INFOHEADER
*/
void InfoHeader::Read(ifstream & file)
{

	if (file.fail())
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.fail()");
			
	if (file.tellg() != INFOHRDIOFFSET)	//verifica se o "index de leitura do ficheiro" se encontra na posiçao certa (0x0E)
		throw("InfoHeader Error: InfoHeaderRead_f_File, info header OFFSET != 0x0E");

	//leitura dos parâmetros
	if (!file.read(reinterpret_cast <char*>(&size), sizeof(size)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_size");

	if (!file.read(reinterpret_cast <char*>(&width), sizeof(width)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_width");

	if (!file.read(reinterpret_cast <char*>(&heigth), sizeof(heigth)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_heith");

	if (!file.read(reinterpret_cast <char*>(&planes), sizeof(planes)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_planes");

	if (!file.read(reinterpret_cast <char*>(&bitsPpixel), sizeof(bitsPpixel)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_bitsPpixel");

	if (!file.read(reinterpret_cast <char*>(&compression), sizeof(compression)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_compression");

	if (!file.read(reinterpret_cast <char*>(&ImageSize), sizeof(ImageSize)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_ImageSize");

	if (!file.read(reinterpret_cast <char*>(&XpixelsPerM), sizeof(XpixelsPerM)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_XpixelsPerM");

	if (!file.read(reinterpret_cast <char*>(&YpixelsPerM), sizeof(YpixelsPerM)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_YpixelsPerM");

	if (!file.read(reinterpret_cast <char*>(&colorsUsed), sizeof(colorsUsed)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_colorsUsed");

	if (!file.read(reinterpret_cast <char*>(&ImportantColors), sizeof(ImportantColors)))
		throw("InfoHeader Error: InfoHeaderRead_f_File, file.read()_ImportantColors");

}

void InfoHeader::Write(ofstream & file)
{
	
	if (!file.write(reinterpret_cast <char*> (size), sizeof(size)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_size";
	if (!file.write(reinterpret_cast <char*> (width), sizeof(width)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_width";
	if (!file.write(reinterpret_cast <char*> (heigth), sizeof(heigth)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_heith";
	if (!file.write(reinterpret_cast <char*> (planes), sizeof(planes)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_planes";
	if (!file.write(reinterpret_cast <char*> (bitsPpixel), sizeof(bitsPpixel)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_bitsPpixel";
	if (!file.write(reinterpret_cast <char*> (compression), sizeof(compression)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_compression";
	if (!file.write(reinterpret_cast <char*> (ImageSize), sizeof(ImageSize)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_ImageSize";
	if (!file.write(reinterpret_cast <char*> (XpixelsPerM), sizeof(XpixelsPerM)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_XpixelPerM";
	if (!file.write(reinterpret_cast <char*> (YpixelsPerM), sizeof(YpixelsPerM)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_YpixelPerM";
	if (!file.write(reinterpret_cast <char*> (colorsUsed), sizeof(colorsUsed)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_colorsUsed";
	if (!file.write(reinterpret_cast <char*> (ImportantColors), sizeof(ImportantColors)))
		throw "InfoHeader Error : InfoHeaderWrite_f_File, file.write()_ImportantColors";

}

void InfoHeader::validate()
{
	if (planes != 1)
		throw("Validate: size InfoHeader invalide size");
	if(bitsPpixel != 24)
		throw("Validate: bits_per_pixel InfoHeader invalide bitsPpixel");
	if(!compression)
		throw("Validate: compression InfoHeader invalide compression");
	//penso que seja so isto
}


ostream& operator<<(ostream& os, const InfoHeader& ihrd)
{
	os	<< "size: " << ihrd.size << endl 
		<< "width: " << ihrd.width << endl
		<< "heith: " << ihrd.heigth << endl 
		<< "planes: " << ihrd.planes << endl 
		<< "bitsPpixel: " << ihrd.bitsPpixel << endl 
		<< "compression: " << ihrd.compression << endl 
		<< "ImageSize: " << ihrd.ImageSize << endl
		<< "XpixelsPerM: " << ihrd.XpixelsPerM << endl 
		<< "YpixelsPerM: " << ihrd.YpixelsPerM << endl
		<< "colorsUsed: " << ihrd.colorsUsed << endl 
		<< "ImportantColors: " << ihrd.ImportantColors << endl;
	
	return os;
}
