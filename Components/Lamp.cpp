#include "Lamp.h"

Lamp::Lamp(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{}

void Lamp::Draw(UI* pUI)
{
	//Call output class and pass Lamp drawing info to it.

	/////////////////555555555555555555555555555555555555555555555555555
	// why I have to put true or false????
	pUI->DrawLamp(*m_pGfxInfo); //update to draw Lamp 

}

void Lamp::Operate()
{

}