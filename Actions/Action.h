#ifndef _ACTION_H
#define _ACTION_H
#include <string>
class ApplicationManager; //forward class declaration


//Base class for all possible actions (abstract class)
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
public:
	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor
	
	//virtual bool isConflict(int, int, int, int) const;

	//Execute action (code depends on action type)
	virtual void Execute()=0;

	//To undo this action (code depends on action type)
	virtual void Undo()=0;

	//To redo this action (code depends on action type)
	virtual void Redo()=0;

};

#endif