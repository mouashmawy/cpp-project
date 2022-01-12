#pragma once

#include "action.h"
#include "..\Components\connection.h"
#include "..\ApplicationManager.h"

#include<iostream>
#include<Windows.h>
#include<string>
#include<mmsystem.h>
#include<conio.h>

using namespace std;



//Class responsible for adding a new resistor action
class ActionBuzzer_Sound : public Action
{
private:
	ApplicationManager* pApp;
	//Parameters for rectangular area to be occupied by the comp
	//int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//two points of the line
	int NumOfComp;
	//Component* ListOfComp = new Component[MaxCompCount];


public:
	ActionBuzzer_Sound(ApplicationManager* pApp);
	virtual ~ActionBuzzer_Sound(void);


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


