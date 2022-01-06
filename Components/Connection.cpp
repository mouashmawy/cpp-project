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

void Connection::Save(ofstream& file)
{
	file << Cmpnt1 << "  " << Cmpnt2 << endl;
}

void Connection::Load(ifstream& file)
{

}

void Connection::Delete()
{

}
