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
	if (selected) cout << "selected" << endl;
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
	file << "FUS" << "  " << label << "  " << "Value" << "  " << List->PointsList[0].x << "  " << List->PointsList[0].y << endl;
}

void Fuse::Load(ifstream &file)
{
	string NAME_OF_COMPONENT, LABEL, VALUE;
	int ID, X, Y;
	while (!file.eof()) {
		file >> ID >> NAME_OF_COMPONENT >> LABEL >> VALUE >> X >> Y;
	}
}