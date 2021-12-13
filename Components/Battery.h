#pragma once
#include "Component.h"

class Battery :public Component
{
public:
	Battery(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*, bool selected = false);	//Draws the resistor

};

