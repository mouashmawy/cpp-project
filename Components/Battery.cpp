#include "Battery.h"
#include<iostream>
#include <fstream>

Battery::Battery(GraphicsInfo* r_GfxInfo, string name, double val) :Component(r_GfxInfo)
{
	this ->value= val;
	label = name;
	Component_type = "BAT";
}

void Battery::Draw(UI* pUI, bool selected)
{

	//Call output class and pass resistor drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo, label, selected); //update to draw resistor


}
GraphicsInfo* Battery::getC()
{
	return m_pGfxInfo;
}

void Battery::Operate()
{

}


void Battery::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << ID << "  " << label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
	}

void Battery::Load(int ID)
{
	this->ID = ID;
}

void Battery::Delete()
{
	delete m_pGfxInfo;
}