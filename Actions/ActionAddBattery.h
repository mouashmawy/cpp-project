#pragma once

#include "action.h"
#include "..\Components\Battery.h"

//Class responsible for adding a new resistor action
class ActionAddBat : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddBat(ApplicationManager* pApp);
	virtual ~ActionAddBat(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


