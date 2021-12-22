#pragma once
#include "../UI/UI.h"

class Component;	//forward class declaration

class Connection 
{
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection

protected:
	string ConnLabel;


public:

	Connection(GraphicsInfo *r_GfxInfo, string text, Component *cmp1=nullptr, Component *cmp2=nullptr);

	virtual void Draw(UI* );	//for connection to Draw itself
	void Save(ofstream& file);
	void Load(ifstream& file);
	

};


