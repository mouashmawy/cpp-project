#pragma once
#include "Component.h"

class Lamp:public Component
{
public:
	Lamp(GraphicsInfo *r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Lamp

};
