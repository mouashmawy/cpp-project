#include "Buzzer.h"
#include<iostream>

Buzzer::Buzzer(GraphicsInfo *r_GfxInfo, string name) :Component(r_GfxInfo)
{
	label = name;
}

void Buzzer::Draw(UI* pUI, bool selected)
{
	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, label, selected); //update to draw resistor

}

GraphicsInfo* Buzzer::getC()
{
	return m_pGfxInfo;
}


void Buzzer::Operate()
{

}