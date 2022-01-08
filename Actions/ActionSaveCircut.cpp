#include "ActionSaveCircut.h"
#include "..\ApplicationManager.h"
#include <iostream>
#include <fstream>
ActionSaveCircut::ActionSaveCircut(ApplicationManager* pApp) :Action(pApp)
{

}

ActionSaveCircut::~ActionSaveCircut(void)
{

}


void ActionSaveCircut::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	///////////////////////////////////////////
	
	

	//Print Action Message
	pUI->PrintMsg("Saving...");
	ofstream Save;
	Save.open("Saved\\file1.txt");
 	pManager->SaveCircut(Save);
	pUI->PrintMsg("Saved");
}

void ActionSaveCircut::Undo()
{
}

void ActionSaveCircut::Redo()
{
}


