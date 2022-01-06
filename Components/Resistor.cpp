#include "Resistor.h"
#include <iostream>
#include <fstream>

Resistor::Resistor(GraphicsInfo *r_GfxInfo, string name, double val):Component(r_GfxInfo)
{
	label = name;
	value = val;
	Component_type = "RES";
}

void Resistor::Draw(UI* pUI,bool selected)
{
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
	file << Component_type << "  " << label << "  " << value << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
}

void Resistor::Load(ifstream &file)
{
	char NAME_OF_COMPONENT, LABEL;
	int ID, X, Y, Count, VALUE;
	file >> Count >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;
	
	
}

void Resistor::Delete(UI* pUI, bool selected)
{
	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	//pUI->DrawGround(*m_pGfxInfo, label, selected); //update to draw resistor



}