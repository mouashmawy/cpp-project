#include "Lamp.h"
#include<iostream>

Lamp::Lamp(GraphicsInfo *r_GfxInfo, string name) :Component(r_GfxInfo)
{
	label = name;
}

void Lamp::Draw(UI* pUI, bool selected)
{

	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, label, selected); //update to draw resistor

}

GraphicsInfo* Lamp::getC()
{
	return m_pGfxInfo;
}

void Lamp::Operate()
{

}