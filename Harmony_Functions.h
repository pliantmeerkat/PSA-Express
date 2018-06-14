#pragma once
#include "stadfx.h"


class Harmony_Functions
{
public:
	Harmony_Functions();
	~Harmony_Functions();

	//core harmonic functions	
	QList <QString> Numeral_Translate(QString Curr_Key, QString Numeral, int Mode, int Num);

	QString KeyCode(int Num);

	int Num_Assign(const QString Key);

	//weightings code
	void H_add_weight(int &CNum, float &WeightingsMod); //this will process modifications of weightings file
	float H_Find_Weight(int &Mode, int &CNum); //this will obtain the weighting value from the txt file


private:

	


	//modes Key: 0 = ionian, 1 = dorian, 2 = phrygian, 3 = lydian, 4 = mixolydian, 5 = aeolian, 6 = locrian, 7 = harmonic/natural minor, 8 = custom mode?
	QList <QString> Mode_Child(int Mode, int Num, int Key_Num);
	QList <QList <QString>> Mode_00 (QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);
	QList <QList <QString>> Mode_01(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);
	QList <QList <QString>> Mode_02(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);
	QList <QList <QString>> Mode_03(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);
	QList <QList <QString>> Mode_04(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);
	QList <QList <QString>> Mode_05(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);
	QList <QList <QString>> Mode_06(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);
	QList <QList <QString>> Mode_07(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);
	QList <QList <QString>> Mode_08(QList <QList <QString>> &ModeVars, QList <QString> &NumAdd, QList <QString> &Tone, QList <QString> S_add);



};

