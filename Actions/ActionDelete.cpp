#include "ActionDelete.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionDelete::~ActionDelete(void)
{
}



void ActionDelete::Execute()
{	
	
	UI* pUI = pManager->GetUI();
	pManager->DeleteAll();
	pUI->PrintMsg("Deleted");
	
}

void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}

