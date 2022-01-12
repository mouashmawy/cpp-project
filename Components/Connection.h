#pragma once
#include "../UI/UI.h"

class Component;	//forward class declaration

class Connection 
{
	Component* Cmpnt1, * Cmpnt2;//connection connects between two compoenets
	
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection

protected:
	string ConnLabel;


public:
	bool selected;
	Connection(GraphicsInfo *r_GfxInfo, string text, Component *cmp1=nullptr, Component *cmp2=nullptr);

	Component* getCmpnt1();
	Component* getCmpnt2();

	GraphicsInfo* getGFX();

	Component* getCmpt(int order);

	virtual void Draw(UI* );	//for connection to Draw itself
	void Save(ofstream& file, int CmptID1, int CmptID2); //for saving the component
	void Load(UI* pUI);
	void Delete();
	void Select(bool selected);
	bool checkSelection();

	bool isConnected(int x, int y); // to check if it is connected or not 

};


