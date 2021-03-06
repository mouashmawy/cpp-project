#include "Lamp.h"
#include<iostream>
#include <fstream>

Lamp::Lamp(GraphicsInfo *r_GfxInfo, string name ,double value) :Component(r_GfxInfo)
{
	label = name;
	Component_type = "LMP";
	this->value = 0;
}

void Lamp::Draw(UI* pUI, bool selected)
{

	//Call output class and pass resistor drawing info to it.
	pUI->DrawLamp(*m_pGfxInfo, label, 5,selected,true); //update to draw resistor

}

GraphicsInfo* Lamp::getC()
{
	return m_pGfxInfo;
}

void Lamp::Operate()
{

}


void Lamp::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << ID << "  " << label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
}

void Lamp::Load(int ID)
{
	this->ID = ID;
}

void Lamp::Delete()
{
	delete m_pGfxInfo;

}

Point Lamp::getCPoint() const
{
	return m_pGfxInfo->PointsList[0];
}
