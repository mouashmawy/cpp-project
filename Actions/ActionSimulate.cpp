#include "ActionSimulate.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionSimulate::ActionSimulate(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionSimulate::~ActionSimulate(void)
{
}



void ActionSimulate::Execute()
{
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	cout << "lol";
	pUI->SwitchToSimulate();
			
}

void ActionSimulate::Undo()
{}

void ActionSimulate::Redo()
{}

