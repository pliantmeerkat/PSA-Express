#include "Core.h"

//for weightings addition
void Core::Write_file(std::string Filename, float Text, int Pitch)
{
	std::string Name = ("Data\\" + Filename);
	std::ofstream File(Name);

	std::string File_Text = "";

	float Line;
	float Original = 0.00; //C.Read_file("Mode00W.txt", 4);
	Text = 0.01;
	int tone = 10;

	//to check if file can be opened
	if (!File)
	{
		std::cerr << "unable to open" + Filename << std::endl;
		exit(1);
	}		

	//code to extract file contents - initially 0.00; 0.00; 0.00; 0.00; 0.00; 0.00; 0.00; 0.00; 0.00; 0.00; 0.00; 0.00; total of 84 chars
	//first read file contents and save to string value
	File_Text = Read_Whole_File(Name, 84);
	//next write float funtion is used to change the correct value
	Line = Read_File_Float(Pitch,Text, File_Text);
	//lastly write the new string value to the text file

	//close the text file
	File.close();

	
	


}
//function to read entire text file
std::string Core::Read_Whole_File(std::string Filename, int Length)
{
	std::string Output = "";
	char C;

	
	std::ifstream File(Filename);
	

	//to read the file and add to output string
	while (File >> C)
	{
		Output += C;
	}
	File.close();
	


	return Output;
}

//this will find the correct float value with or without changing it
//to not change the value and just read simply enter change value of 0.00
float Core::Read_File_Float(int Pitch, float Change, std::string File_Text)
{
	int charcount = 0;
	float Text;
	std::string Floatadd;
	
	//this assumes each float value is made up of 7 characters, so to find the start of the float the equation 7*tone is used
	int PL = 7 * Pitch; // pitch length
	for (char &c : File_Text) // this reads the string char by char
	{	
		//only read in the right place
		while ((charcount >= PL) && (charcount <= PL + 4))
		{
			Floatadd += c;	
			charcount += 1;
		}
		if (charcount > PL + 4) //ends the loop once float has been found
		{
			break;
		}



		charcount += 1; // add our counter
	}
	
	
	Text = std::stof(Floatadd); //convert floatadd to float value
	Text += Change;

	return Text;
}




Core::Core()
{
}


Core::~Core()
{
}
