#include "Component.h"

string Component::getLabel()
{
	return label;
}

void Component::setLabel(string ll) {
	label = ll;
}

double Component::getValue()
{
	return value;
}

void Component::setValue(double v)
{
	value = v;
}



Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;

}

 
GraphicsInfo* Component::getC()
{
	return m_pGfxInfo;
}



Component::~Component()
{}

