#include "Buzzer.h"
#include<iostream>
#include <fstream>

Buzzer::Buzzer(GraphicsInfo *r_GfxInfo, string name) :Component(r_GfxInfo)
{
	label = name;
	Component_type = "BUZ";
}

void Buzzer::Draw(UI* pUI, bool selected)
{
	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo, label, selected); //update to draw resistor

}

GraphicsInfo* Buzzer::getC()
{
	return m_pGfxInfo;
}


void Buzzer::Operate()
{

}


void Buzzer::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << label << "  " << "No Value" << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
}

void Buzzer::Load(ifstream &file)
{
	char NAME_OF_COMPONENT, LABEL;
	int ID, X, Y, Count, VALUE;
	file >> Count >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;
	cout << Count << ID;
}

void Buzzer::Delete(UI* pUI, bool selected)
{
	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	//pUI->DrawBuzzer(*m_pGfxInfo, label, selected); //update to draw resistor

}