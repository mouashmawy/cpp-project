#include "Battery.h"
#include<iostream>
#include <fstream>

Battery::Battery(GraphicsInfo* r_GfxInfo, string name, double val) :Component(r_GfxInfo)
{
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
	file << "BUZ" << "  " << label << "  " << "Value" << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
}

void Battery::Load(ifstream &file)
{
	string NAME_OF_COMPONENT, LABEL, VALUE;
	int ID, X, Y;
	while (!file.eof()) {
		file >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;
	}
}