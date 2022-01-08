#include "Switch.h"
#include<iostream>
#include <fstream>
Switch::Switch(GraphicsInfo* r_GfxInfo, string name) :Component(r_GfxInfo)
{

	label = name;
	Component_type = "SWT";
}

void Switch::Draw(UI* pUI, bool selected)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, label, selected,true); //update to draw resistor

}

GraphicsInfo* Switch::getC()
{
	return m_pGfxInfo;
}


void Switch::Operate()
{

}
void Switch::Save(ofstream &file)
{
	GraphicsInfo* List = getC();
	file << Component_type << "  " << ID << "  "<< label << "  " << "No Value" << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
	ID++;
}

void Switch::Load(ifstream &file)
{
	string NAME_OF_COMPONENT, LABEL, VALUE;
	int ID, X, Y;
	while (!file.eof()) {
		file >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;
	}
}

void Switch::Delete()
{
	delete m_pGfxInfo;
}