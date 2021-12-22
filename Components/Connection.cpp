#include "Connection.h"
#include <fstream>

Connection::Connection(GraphicsInfo *r_GfxInfo, string text,Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
	ConnLabel = text;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, ConnLabel);
}

void Connection::Save(ofstream& file)
{
	file << Cmpnt1 << "  " << Cmpnt2 << endl;
}

void Connection::Load(ifstream& file)
{

}


