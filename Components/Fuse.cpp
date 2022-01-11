#include "Fuse.h"
#include<iostream>
#include <fstream>

Fuse::Fuse(GraphicsInfo* r_GfxInfo, string name) :Component(r_GfxInfo)
{
	label = name;
	Component_type = "FUS";
}

void Fuse::Draw(UI* pUI, bool selected)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawFuse(*m_pGfxInfo, label, selected); //update to draw resistor

}

GraphicsInfo* Fuse::getC()
{
	return m_pGfxInfo;
}

void Fuse::Operate()
{

}


void Fuse::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << ID << "  " << label << "  " << "No Value" << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
}

void Fuse::Load(int ID)
{
	this->ID = ID;
}

void Fuse::Delete()
{
	delete m_pGfxInfo;

}