#pragma once
#include "Component.h"

class Resistor:public Component
{
	int Cx, Cy;


public:
	Resistor(GraphicsInfo *r_GfxInfo,string name,double val=0);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*,bool selected=false);	//Draws the resistor
	GraphicsInfo* getC();
	void Save(ofstream& file);
	void Load(ifstream& file);


};
