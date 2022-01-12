#pragma once

#include "action.h"

//Class responsible for adding a new resistor action
class ActionLoadCircut : public Action
{
private:
	
public:
	ActionLoadCircut(ApplicationManager* pApp);
	virtual ~ActionLoadCircut(void);


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


