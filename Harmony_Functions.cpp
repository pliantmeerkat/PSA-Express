#include "Harmony_Functions.h"
//core harmonic functions
//function to assign numeral from number


//all chords will have the following format [Key, Tone, Modifier] - eg [C, M, 7] = C#M7 || # refers to no modifier/ tonality
//key - a = 0. A = 1, b = 2, c = 3, C = 4, d = 5, D = 6, e = 7, f = 8, F = 9, g = 10, G = 11
//Tone - m = major, M = minor, d = half Diminished, D = Diminished, A = augmented, T = altered, 
//chord mods - 6 - sixth, 7 = Seventh, 9 = ninth, 11 = Eleventh, 13 = Thirteenth ||next values use this logic: n = flat ninth, N = #ninth, E = 11, T = 13, S = 6th, F = 5th

//all weightings values will be in floating point format ranging from 0 to 1

//this function both assigns numerals and assigns them a tonality value
QList <QString> Harmony_Functions::Numeral_Translate(QString Curr_Key, QString Numeral, int Mode, int Num)
{
	QList <QString> Chord; //uses a list to separate tonality and key [0 - key, 1 - tone]

	//code to make sure number is in range
	if (Num < 0)
	{
		Num += 11;
	}
	else if (Num > 11)
	{
		Num -= 11;
	}

	//mode select switch :: Key: 0 = ionian, 1 = dorian, 2 = phrygian, 3 = lydian, 4 = mixolydian, 5 = aeolian, 6 = locrian, 7 = harmonic/natural minor, 8 = custom mode?




	return Chord;

}

QString Harmony_Functions::KeyCode(int Num)//simple function to convert a number to a key value using num assign scale
{
	//def/dec
	QString Key = "";

	switch (Num)
	{
	case 0:
		Key = "a";
		break;

	case 1:
		Key = "A";
		break;
	case 2:
		Key = "b";
		break;
	case 3:
		Key = "c";
		break;
	case 4:
		Key = "C";
		break;
	case 5:
		Key = "d";
		break;
	case 6:
		Key = "D";
		break;
	case 7:
		Key = "e";
		break;
	case 8:
		Key = "f";
		break;
	case 9:
		Key = "F";
		break;
	case 10:
		Key = "g";
		break;
	case 11:
		Key = "G";
		break;
	default:
		break;
	}

	return Key;

}

int Harmony_Functions::Num_Assign(const QString Key)
{
	int Num = 0; // decalre and initialise num variable
	//main conditional
	if (Key == "a")
	{
		Num = 0;
	}
	else if (Key == "A")
	{
		Num = 1;
	}
	else if (Key == "b")
	{
		Num = 2;
	}
	else if (Key == "c")
	{
		Num = 3;
	}
	else if (Key == "C")
	{
		Num = 4;
	}
	else if (Key == "d")
	{
		Num = 5;
	}
	else if (Key == "D")
	{
		Num = 6;
	}
	else if (Key == "e")
	{
		Num = 7;
	}
	else if (Key == "f")
	{
		Num = 8;
	}
	else if (Key == "F")
	{
		Num = 9;
	}
	else if (Key == "g")
	{
		Num = 10;
	}
	else if (Key == "G")
	{
		Num = 11;
	}

	return Num;
}

//mode definitions
QList <QString> Harmony_Functions::Mode_Child(int Mode, int Num, int Key_Num) //child modal module this selects correct additives for mode calculations
{
	//def/dec
	QList <QString> Complete_Chord;
	QString Key = "";
	QString Tone = "";
	QString Cmod = "#"; //default of no value
	int N = Num + Key_Num; //will change for certain values dependant on mode
	//for testing use
	Mode = 0;


	//list variables for mode
	QList <QList <QString>> ModeVars; //return variable
	QList <QString> NumAdd; //number modifiers
	QList <QString> ToneMod;	//tone modifiers
	QList <QString> S_add;	//for 7ths 9ths etc
	switch (Mode) //to choose the correct mode values
	{
	case 0:
		ModeVars = Mode_00(ModeVars, NumAdd, ToneMod, S_add);
		break;
	case 1:
		ModeVars = Mode_01(ModeVars, NumAdd, ToneMod, S_add);
		break;
	case 2:
		ModeVars = Mode_02(ModeVars, NumAdd, ToneMod, S_add);
		break;
	case 3:
		ModeVars = Mode_03(ModeVars, NumAdd, ToneMod, S_add);
		break;
	case 4:
		ModeVars = Mode_04(ModeVars, NumAdd, ToneMod, S_add);
		break;
	case 5:
		ModeVars = Mode_05(ModeVars, NumAdd, ToneMod, S_add);
		break;
	case 6:
		ModeVars = Mode_06(ModeVars, NumAdd, ToneMod, S_add);
		break;
	case 7:
		ModeVars = Mode_07(ModeVars, NumAdd, ToneMod, S_add);
		break;
	case 8:
		ModeVars = Mode_08(ModeVars, NumAdd, ToneMod, S_add);
	case 9: //will be reserved for user made modes
		break;
	default:
		break;
	}
	
	//obtian correct values from mode functions
	N += ModeVars[0][Num].toInt();
	Tone = ModeVars[1][Num];
	Cmod = ModeVars[2][Num];




	Key = KeyCode(N); // assign a key from keycode and our modified number

	//add or calculated values to chord
	Complete_Chord[0] = Key;
	Complete_Chord[1] = Tone;
	Complete_Chord[2] = Cmod;

	return Complete_Chord;

	//old code //
	/* old code may be removed!
						   //main chord alg
	switch (Num) //here num refers to a numeral or altered numeral
	{
	case 0:	//I	
		N += ModeVars[0][0].toInt();
		Tone = "m";
		Cmod = "";
		break;
	case 1: // bII
		N += 0;
		Tone = "d";
		break;
	case 2: //II
		N += 0;
		Tone = "M";
		break;
	case 3: //bIII or IV7
		N += 3;
		Tone = "m";
		Cmod = "7";
	case 4: //III
		N += 0;
		Tone = "m";
		break;
	case 5: //IV
		N += 0;
		Tone = "M";
		break;
	case 6: //bV
		N += 0;
		Tone = "d";
		break;
	case 7: //V
		N += 0;
		Tone = "m";
		break;
	case 8: //bVI
		N += 0;
		Tone = "D";
		break;
	case 9: //VI
		N += 0;
		Tone = "M";
		break;
	case 10: //bVII or I7		
		N -= 9;
		Tone = "m";
		Cmod = "7";
	case 11: //VII
		N = 0;
		Tone = "d";

	}*/


	

}


//functions to process modal weightings
//function to modify weightins file
void Harmony_Functions::H_add_weight(int &CNum, float &WeightingsMod)
{

	


}

float Harmony_Functions::H_Find_Weight(int &Mode, int &CNum)
{
	float Weight = 0.00; //define and declare wieght float

	



	return Weight; //returns the correct weight value
}


//list of mode functions
//ionaian mode
QList <QList <QString>> Harmony_Functions::Mode_00 (QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{
	//unique values for list
//scale :	   1	  2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "0" << "0" << "3" << "0" << "0" << "0" << "0" << "0" << "0" << "-10" << "0"; //mode numeric additives
	Tone   << "m" << "d" << "M" << "m" << "M" << "m" << "d" << "m" << "D" << "M" << "m " << "d"; //mode tonality values
	S_add  << "#" << "#" << "#" << "7" << "#" << "#" << "#" << "#" << "#" << "#" << "7 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;

}
//dorian mode
QList <QList <QString>> Harmony_Functions::Mode_01(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{
	//unique values for list
	//scale :	1	  2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "2" << "0" << "0" << "0" << "0" << "0" << "0" << "2" << "0" << "0"  << "0"; //mode numeric additives
	Tone   << "M" << "m" << "M" << "m" << "d" << "m" << "d" << "M" << "m" << "d" << "m " << "d"; //mode tonality values
	S_add  << "#" << "7" << "#" << "#" << "#" << "#" << "#" << "#" << "7" << "#" << "0 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;

}
//phrygian mode
QList <QList <QString>> Harmony_Functions::Mode_02(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{
	//unique values for list
	//scale :	1	  2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "2" << "0" << "0" << "0" << "0" << "0" << "0" << "2" << "0" << "0"  << "0"; //mode numeric additives
	Tone   << "M" << "m" << "M" << "m" << "d" << "m" << "d" << "M" << "m" << "d" << "m " << "d"; //mode tonality values
	S_add  << "#" << "7" << "#" << "#" << "#" << "#" << "#" << "#" << "7" << "#" << "0 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;

}

//lydian mode
QList <QList <QString>> Harmony_Functions::Mode_03(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{


	//unique values for list
	//scale :  1	  2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "0" << "0" << "0" << "0" << "2" << "0" << "0" << "0" << "0" << "-9" << "0"; //mode numeric additives
	Tone   << "m" << "d" << "m" << "d" << "m" << "m" << "d" << "m" << "d" << "M" << "m " << "M"; //mode tonality values
	S_add  << "#" << "#" << "#" << "#" << "#" << "7" << "#" << "#" << "#" << "#" << "7 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;



}
/**/
//mixolydian mode
QList <QList <QString>> Harmony_Functions::Mode_04(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{


	//unique values for list
	//scale :  1	  2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "0" << "0" << "0" << "0" << "2" << "0" << "0" << "0" << "0" << "-9" << "0"; //mode numeric additives
	Tone << "m" << "d" << "m" << "d" << "m" << "m" << "d" << "m" << "d" << "M" << "m " << "M"; //mode tonality values
	S_add << "#" << "#" << "#" << "#" << "#" << "7" << "#" << "#" << "#" << "#" << "7 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;



}

//aeolian mode
QList <QList <QString>> Harmony_Functions::Mode_05(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{


	//unique values for list
	//scale : 1	      2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "2" << "0" << "3" << "0" << "0" << "2" << "0" << "0" << "0" << "0"  << "0"; //mode numeric additives
	Tone   << "M" << "m" << "d" << "m" << "d" << "M" << "m" << "M" << "m" << "d" << "m " << "d"; //mode tonality values
	S_add  << "#" << "7" << "#" << "#" << "#" << "#" << "7" << "#" << "#" << "#" << "0 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;



}
/**/
//locrian mode
QList <QList <QString>> Harmony_Functions::Mode_06(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{
	//unique values for list
	//scale :	1	  2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "2" << "0" << "0" << "0" << "0" << "0" << "0" << "2" << "0" << "0" << "0"; //mode numeric additives
	Tone << "M" << "m" << "M" << "m" << "d" << "m" << "d" << "M" << "m" << "d" << "m " << "d"; //mode tonality values
	S_add << "#" << "7" << "#" << "#" << "#" << "#" << "#" << "#" << "7" << "#" << "0 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;

}
//natural minor - up
QList <QList <QString>> Harmony_Functions::Mode_07(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{
	//unique values for list
	//scale :	1	  2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "2" << "0" << "0" << "0" << "0" << "0" << "0" << "2" << "0" << "0" << "0"; //mode numeric additives
	Tone << "M" << "m" << "M" << "m" << "d" << "m" << "d" << "M" << "m" << "d" << "m " << "d"; //mode tonality values
	S_add << "#" << "7" << "#" << "#" << "#" << "#" << "#" << "#" << "7" << "#" << "0 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;

}

//harmonic minor
QList <QList <QString>> Harmony_Functions::Mode_08(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add)
{
	//unique values for list
	//scale :	1	  2		 3		4	   5      6		 7	    8      9	  10     11	   12
	NumAdd << "0" << "2" << "0" << "0" << "0" << "0" << "0" << "0" << "2" << "0" << "0" << "0"; //mode numeric additives
	Tone << "M" << "m" << "M" << "m" << "d" << "m" << "d" << "M" << "m" << "d" << "m " << "d"; //mode tonality values
	S_add << "#" << "7" << "#" << "#" << "#" << "#" << "#" << "#" << "7" << "#" << "0 " << "#";

	ModeVars[0] << NumAdd;
	ModeVars[1] << Tone;
	ModeVars[2] << S_add;

	return ModeVars;

}







Harmony_Functions::Harmony_Functions()
{
}


Harmony_Functions::~Harmony_Functions()
{
}


