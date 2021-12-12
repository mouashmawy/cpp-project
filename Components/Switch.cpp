#include "Switch.h"

Switch::Switch(GraphicsInfo* r_GfxInfo) : Component (r_GfxInfo)
{}

void Switch::Draw(UI* pUI)
{
	
	pUI->DrawSwitch(*m_pGfxInfo);

}

void Switch::Operate()
{

}