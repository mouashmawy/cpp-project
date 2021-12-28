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

	bool isConflict(int xx, int yy, int ww, int hh) const;

};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in the menu
	//If you want to change the menu items order, just change the order here
	ITM_RES,		//Resistor item in menu
	ITM_LAMP,		//Lamp
	ITM_BATTERY,
	ITM_FUSE,
	ITM_GROUND,
	ITM_SWITCH,
	ITM_BUZZER,
	ITM_CONN,		//to draw connections

	ITM_EXIT,		//Exit item
	//TODO: Add more items names here

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};


#endif