#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass Buzzer drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo); //update to draw Buzzer

}

void Buzzer::Operate()
{

}