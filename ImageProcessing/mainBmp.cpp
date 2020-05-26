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
			my_file.close();
			cout << info;

			my_write_file.open(sampleWrite);
			if (my_write_file.fail())
				throw("cant open file : main.c");
		
			info.Write(my_write_file);
			my_write_file.close();
		}
		catch (char* str)
		{
			cout << "Exception: " << str; 
		}


		cout << "ora boas";
	return 0;
}



