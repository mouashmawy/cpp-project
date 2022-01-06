#pragma once

#include "ActionCopyCutPaste.h"
#include "..\ApplicationManager.h"

//Class responsible for adding a new resistor action
class ActionCut : public ActionCopyCutPaste
{
private:
	ApplicationManager* pApp;

	int x1, y1, x2, y2;	//two points of the line
	int NumOfComp;

protected:
	static int cpd_value;
	static string cpd_label;

public:
	ActionCut(ApplicationManager* pApp);
	virtual ~ActionCut(void);

	Component* CompInPlace(int xx, int yy);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


