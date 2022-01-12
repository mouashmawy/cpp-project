#include "ActionDesign.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionDesign::ActionDesign(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionDesign::~ActionDesign(void)
{
}



void ActionDesign::Execute()
{
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	cout << "lol2";
	pUI->BackToDesign();
			
}

void ActionDesign::Undo()
{}

void ActionDesign::Redo()
{}

