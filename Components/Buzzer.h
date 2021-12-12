#pragma once
#include "Component.h"

class Buzzer:public Component
{
public:
	Buzzer(GraphicsInfo *r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Buzzer

};
