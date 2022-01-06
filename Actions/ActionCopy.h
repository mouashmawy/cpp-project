#pragma once

#include "ActionCopyCutPaste.h"
#include "..\ApplicationManager.h"

//Class responsible for adding a new resistor action
class ActionCopy : public ActionCopyCutPaste
{
private:
	ApplicationManager* pApp;
	int x1, y1, x2, y2;	
	 


public:
	ActionCopy(ApplicationManager* pApp);
	virtual ~ActionCopy(void);


	Component* CompInPlace(int xx, int yy);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


