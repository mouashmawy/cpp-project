#include "Connection.h"
#include <fstream>
#include <iostream>


Connection::Connection(GraphicsInfo *r_GfxInfo, string text,Component *cmp1, Component *cmp2)
{
	cout << 6;
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
	ConnLabel = text;
	std::cout << "constr";
}
void Connection::Draw(UI* pUI)
{
	cout << "draw";
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

void Connection::Save(ofstream& file, int Cmpt1, int Cmpt2)
{
	file << Cmpt1 << "  " << Cmpt2 << endl;
}

void Connection::Load(ifstream& file)
{

}

void Connection::Delete()
{

}
