#include "Ground.h"
#include<iostream>
#include <fstream>

Ground::Ground(GraphicsInfo* r_GfxInfo , string name, double value) :Component(r_GfxInfo)
{
	this->value = value;
	label = name;
	Component_type = "GND";
}

void Ground::Draw(UI* pUI, bool selected)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo, label, selected); //update to draw resistor

}

GraphicsInfo* Ground::getC()
{
	return m_pGfxInfo;
}

void Ground::Operate()
{

}


void Ground::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << ID << "  " << label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
}

void Ground::Load(int ID)
{
	this->ID = ID;
}

void Ground::Delete()
{
	delete m_pGfxInfo;
}

Point Ground::getCPoint() const
{
	return m_pGfxInfo->PointsList[0];
}
