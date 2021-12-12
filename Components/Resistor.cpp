#include "Resistor.h"

Resistor::Resistor(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{
	label = "Resistor";

}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo); //update to draw resistor

}

GraphicsInfo* Resistor::getC()
{
	return m_pGfxInfo;
}

void Resistor::Operate()
{

}