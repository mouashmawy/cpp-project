#include "Buzzer.h"
#include<iostream>
#include <fstream>

Buzzer::Buzzer(GraphicsInfo *r_GfxInfo, string name, double value ) :Component(r_GfxInfo)
{
	label = name;
	Component_type = "BUZ";
	this->value = value;
}

void Buzzer::Draw(UI* pUI, bool selected)
{
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
	file << Component_type << "  " << ID << "  " << label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
}

void Buzzer::Load(int ID)
{
	this->ID = ID;
}

void Buzzer::Delete()
{
	delete m_pGfxInfo;
}

Point Buzzer::getCPoint() const
{
	return m_pGfxInfo->PointsList[0];
}
