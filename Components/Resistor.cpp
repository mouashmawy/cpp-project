#include "Resistor.h"
#include <iostream>
#include <fstream>

Resistor::Resistor(GraphicsInfo *r_GfxInfo, string name, double value):Component(r_GfxInfo)
{
	label = name;
	this->value = value;
	Component_type = "RES";
}

void Resistor::Draw(UI* pUI,bool selected)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo,label,value, selected); //update to draw resistor
	
}

GraphicsInfo* Resistor::getC()
{
	return m_pGfxInfo;
}

void Resistor::Operate()
{

}


void Resistor::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << ID << "  " << label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
}

void Resistor::Load(int ID)
{
	this->ID = ID;
	
}

void Resistor::Delete()
{
	delete m_pGfxInfo;
}