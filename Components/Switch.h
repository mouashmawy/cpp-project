#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch (GraphicsInfo* r_GfxInfo);
	virtual void Operate();	
	virtual void Draw(UI*, bool selected = false);

};

