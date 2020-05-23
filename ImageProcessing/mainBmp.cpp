#include <iostream>
#include <fstream>
#include <string>

#include <stdint.h>

//header files Includes

#include "InfoHeader.h"



//Private defines
#define sampleFileName "sample.bmp"
#define my_experFileName "exper.txt"

#define sampleWrite "sample_wrt.txt"

using namespace std;


//function Prototypes


int main(char argv, char* argc[])
{

		ifstream my_file;
		ofstream my_write_file;
		InfoHeader info;

		try
		{
			my_file.open(sampleFileName);
			
			if (my_file.fail())
				throw("cant open file : main.c");
			
			my_file.seekg(0x0E);		// colocar o index de leitura no inicio do InfoHeader

			//teste da leitura do InfoHeader do BMP
			info.Read(my_file);
			cout << my_file.tellg() << endl;
		
			cout << info;

			my_write_file.open(sampleWrite);
		
		
			if (!info.Write(my_write_file))
				throw("main: error in write to file");
		}
		catch (char* str)
		{
			cout << "Exception: " << str; 
		}


		cout << "ora boas";
	return 0;
}



