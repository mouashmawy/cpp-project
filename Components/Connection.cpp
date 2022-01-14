#include "Connection.h"
#include <fstream>
#include <iostream>
#include "Component.h"


Connection::Connection(GraphicsInfo *r_GfxInfo, string text,Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, ConnLabel);
}

Component* Connection::getCmpt(int order) {
	if (order == 1) {
		return Cmpnt1;
	}
	else if (order == 2) {
		return Cmpnt2;
	}
	else return nullptr;
}

void Connection::Save(ofstream& file, int CmptID, int CmptID2)
{
	file << CmptID << "  " << CmptID2 << endl;
}

Component* Connection::getCmpnt1() {
	return Cmpnt1;
}


Component* Connection::getCmpnt2() {

	return Cmpnt2;
}

GraphicsInfo* Connection::getGFX() {
	return pGfxInfo;
}
void Connection::Select(bool selected) {
	this->selected = selected;
}
bool Connection::checkSelection() {
	return selected;
}

void Connection::Load(UI* pUI)
{
}

bool Connection::isConnected(int x, int y) {
	int x1 = pGfxInfo->PointsList[0].x;
	int x2 = pGfxInfo->PointsList[1].x;
	int y1 = pGfxInfo->PointsList[0].y;
	int y2 = pGfxInfo->PointsList[1].y;
	if ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2)) {
		return true;
	}
	else {
		return false;
	}

}



void Connection::Delete()
{

}
