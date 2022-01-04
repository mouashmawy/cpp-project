#include "Lamp.h"
#include<iostream>
#include <fstream>

Lamp::Lamp(GraphicsInfo *r_GfxInfo, string name) :Component(r_GfxInfo)
{
	label = name;
	Component_type = "LMP";
}

void Lamp::Draw(UI* pUI, bool selected)
{

	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	pUI->DrawLamp(*m_pGfxInfo, label, selected); //update to draw resistor

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
	file << Component_type << "  " << label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
}

void Lamp::Load(ifstream &file)
{
	char NAME_OF_COMPONENT, LABEL;
	int ID, X, Y, Count, VALUE;
	file >> Count >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;

}

void Lamp::Delete(UI* pUI, bool selected)
{
	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	//pUI->DrawGround(*m_pGfxInfo, label, selected); //update to draw resistor

}