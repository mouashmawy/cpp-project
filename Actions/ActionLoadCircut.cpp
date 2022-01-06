#include "ActionLoadCircut.h"
#include "..\ApplicationManager.h"
#include <iostream>
#include <fstream>
ActionLoadCircut::ActionLoadCircut(ApplicationManager* pApp) :Action(pApp)
{

}

ActionLoadCircut::~ActionLoadCircut(void)
{
}


void ActionLoadCircut::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	
	//Print Action Message
	pUI->PrintMsg("Loading...");
	ifstream Load("file1.txt");

	pManager->LoadCircut(Load);
	pUI->PrintMsg("Loaded");
}

void ActionLoadCircut::Undo()
{
}

void ActionLoadCircut::Redo()
{
}


