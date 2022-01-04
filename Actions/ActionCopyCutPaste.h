#pragma once

#include "action.h"
#include "..\Components\connection.h"
#include "..\ApplicationManager.h"

//Class responsible for adding a new resistor action
class ActionCopyCutPaste : public Action
{
private:
	ApplicationManager* pApp;
	//Parameters for rectangular area to be occupied by the comp
	//int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//two points of the line
	int NumOfComp;
	//Component* ListOfComp = new Component[MaxCompCount];

protected:
	static int cpd_value;
	static string cpd_label;
	static Component* p_cpd_comp;

	 


public:
	ActionCopyCutPaste(ApplicationManager* pApp);
	virtual ~ActionCopyCutPaste(void);


	Component* CompInPlace(int xx, int yy);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


