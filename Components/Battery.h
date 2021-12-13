#pragma once
#include "Component.h"

class Battery :public Component
{
	int Cx, Cy;


public:
	Battery(GraphicsInfo* r_GfxInfo, string name);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*, bool selected = false);	//Draws the resistor
	GraphicsInfo* getC();
};

