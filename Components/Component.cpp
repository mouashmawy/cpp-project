#include "Component.h"

int Component::ID = 1;

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

string Component::getType()
{
	return Component_type;
}

bool Component::CheckSelection()
{
	return Selected;
}

void Component::Select() {
	Selected = true;
}

Connection**  Component::getTerm1()
{
	return term1_connections;
}

Connection** Component::getTerm2()
{
	return term2_connections;
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

bool Component::isHere(int x, int y) {
	if (x >= m_pGfxInfo->PointsList[0].x && x <= m_pGfxInfo->PointsList[1].x && y >= m_pGfxInfo->PointsList[0].y && y <= m_pGfxInfo->PointsList[1].y) {
		return true;
	}
	else return false;
}

GraphicsInfo* Component::getC()
{
	return m_pGfxInfo;
}

void Component::setC(GraphicsInfo* c)
{
	m_pGfxInfo = c;
}



Component::~Component()
{}


int Component::t1_conn_c() {
	return term1_conn_count;
}
int Component::t2_conn_c() {
	return term2_conn_count;
}