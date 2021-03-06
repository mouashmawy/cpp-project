#include "Module.h"
#include <iostream>
#include <fstream>

Module::Module(GraphicsInfo *r_GfxInfo, string name, double val):Component(r_GfxInfo)
{
	label = name;
	this->value= val;
	Component_type = "MOD";
}

void Module::Draw(UI* pUI,bool selected)
{
	//Call output class and pass Module drawing info to it.
	pUI->DrawModule(*m_pGfxInfo,label,value, selected); //update to draw Module
	
}

GraphicsInfo* Module::getC()
{
	return m_pGfxInfo;
}

void Module::Operate()
{

}


void Module::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << ID << "  " << label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
	}

void Module::Load(int ID)
{
	this->ID = ID;
}

void Module::Delete()
{
	delete m_pGfxInfo;
}

Point Module::getCPoint() const
{
	return m_pGfxInfo->PointsList[0];
}
