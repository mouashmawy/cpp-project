#pragma once

#include "action.h"
#include "..\Components\connection.h"
#include "..\ApplicationManager.h"

//Class responsible for adding a new resistor action
class ActionConnect : public Action
{
private:
	ApplicationManager* pApp;
	//Parameters for rectangular area to be occupied by the comp
	//int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//two points of the line
	int NumOfComp;
	//Component* ListOfComp = new Component[MaxCompCount];
	enum side { LEFT, RIGHT };

public:
	ActionConnect(ApplicationManager* pApp);
	virtual ~ActionConnect(void);

	Component* WhatComponent(int xx, int yy, side &lr) ;

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


