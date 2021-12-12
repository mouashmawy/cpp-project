#pragma once
#include "Component.h"

class Resistor:public Component
{
	int Cx, Cy;


public:
	Resistor(GraphicsInfo *r_GfxInfo,string name);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	GraphicsInfo* getC();

};
