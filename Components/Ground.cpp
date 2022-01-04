#include "Ground.h"
#include<iostream>
#include <fstream>

Ground::Ground(GraphicsInfo* r_GfxInfo , string name) :Component(r_GfxInfo)
{
	label = name;
	Component_type = "GND";
}

void Ground::Draw(UI* pUI, bool selected)
{
	if (selected) cout << "selected" << endl;
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
	file << Component_type << "  " << label << "  " << "No Value" << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
}

void Ground::Load(ifstream &file)
{
	string NAME_OF_COMPONENT, LABEL, VALUE;
	int ID, X, Y;
	while (!file.eof()) {
		file >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;
	}
}