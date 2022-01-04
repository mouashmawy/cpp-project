#include "Resistor.h"
#include <iostream>
#include <fstream>

Resistor::Resistor(GraphicsInfo *r_GfxInfo, string name, double val):Component(r_GfxInfo)
{
	label = name;
	value = val;
	Component_type = "MOD";
}

void Resistor::Draw(UI* pUI,bool selected)
{
	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo,label,value, selected); //update to draw resistor
	
}

GraphicsInfo* Resistor::getC()
{
	return m_pGfxInfo;
}

void Resistor::Operate()
{

}


void Resistor::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << "MOD" << "  " << label << "  " << "Value" << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
}

void Resistor::Load(ifstream &file)
{
	string NAME_OF_COMPONENT, LABEL, VALUE;
	int ID, X, Y;
	while (!file.eof()) {
		file >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;
	}
}