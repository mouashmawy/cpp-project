#include "ActionModDes.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionModDes::ActionModDes(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionModDes::~ActionModDes(void)
{
}



void ActionModDes::Execute()
{
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	cout << "lolX";
	pUI->SwitchToModDes();
			
}

void ActionModDes::Undo()
{}

void ActionModDes::Redo()
{}

