#include "ActionLoadCircut.h"
#include "..\ApplicationManager.h"
#include <iostream>
#include <fstream>
ifstream file;
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

	pManager->LoadCircut(file , "Saved/file1.txt");
	pUI->PrintMsg("Loaded");

}

void ActionLoadCircut::Undo()
{
}

void ActionLoadCircut::Redo()
{
}


