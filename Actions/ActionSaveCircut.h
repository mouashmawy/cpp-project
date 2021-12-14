#pragma once

#include "action.h"

//Class responsible for adding a new resistor action
class ActionSaveCircut : public Action
{
private:
public:
	ActionSaveCircut(ApplicationManager* pApp);
	virtual ~ActionSaveCircut(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


