#include "Switch.h"

Switch::Switch(GraphicsInfo* r_GfxInfo) : Component (r_GfxInfo)
{}

void Switch::Draw(UI* pUI, bool selected)
{
	
	pUI->DrawSwitch(*m_pGfxInfo,selected);

}

void Switch::Operate()
{

}