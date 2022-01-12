#include "Switch.h"
#include<iostream>
#include <fstream>
Switch::Switch(GraphicsInfo* r_GfxInfo, string name, double value) :Component(r_GfxInfo)
{
	this->value = 0;
	label = name;
	Component_type = "SWT";
}

void Switch::Draw(UI* pUI, bool selected)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, label, selected,true); //update to draw resistor

}

GraphicsInfo* Switch::getC()
{
	return m_pGfxInfo;
}


void Switch::Operate()
{

}
void Switch::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << ID << "  "<< label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
}

void Switch::Load(int ID)
{
	this->ID = ID;
}

void Switch::Delete()
{
	delete m_pGfxInfo;
}