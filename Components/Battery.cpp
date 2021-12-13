#include "Battery.h"
#include<iostream>

Battery::Battery(GraphicsInfo* r_GfxInfo, string name) :Component(r_GfxInfo)
{
	label = name;
}

void Battery::Draw(UI* pUI, bool selected)
{
	if (selected) cout << "selected" << endl;
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, label, selected); //update to draw resistor


}
GraphicsInfo* Battery::getC()
{
	return m_pGfxInfo;
}

void Battery::Operate()
{

}