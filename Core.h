#pragma once
#include "stadfx.h"


class Core
{
public:
	Core();
	~Core();


	//file processing assuming all files are in the data folder	
	void Write_file(std::string Filename, float Text, int Pitch);
	std::string Read_Whole_File(std::string Filename, int Length);
	float Read_File_Float(int Pitch, float Change, std::string File_Text); //can be converted to other formats later


};

