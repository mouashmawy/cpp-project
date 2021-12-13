#include "Battery.h"

Battery::Battery(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Battery::Draw(UI* pUI, bool selected)
{
	//Call output class and pass Battery drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo,selected); //update to draw Battery

}

void Battery::Operate()
{

}