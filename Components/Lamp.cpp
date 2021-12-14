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
	file << "LMP" << "  " << label << "  " << "Value" << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
}

void Lamp::Load(ifstream &file)
{
	string NAME_OF_COMPONENT, LABEL, VALUE;
	int ID, X, Y;
	while (!file.eof()) {
		file >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;
	}
}