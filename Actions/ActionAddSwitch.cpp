#include "ActionAddSwitch.h"
#include "..\ApplicationManager.h"
#include "../Components/Switch.h"
#include<iostream>

ActionAddSwitch::ActionAddSwitch(ApplicationManager* pApp) : Action(pApp)
{
}

ActionAddSwitch::~ActionAddSwitch(void)
{
}

void ActionAddSwitch::Execute()
{
//
//UI* pUI = pManager->GetUI();
//
//	
//	pUI->PrintMsg("Adding a new Swtich: Click anywhere to add");
//
//	//Get Center point of the area where the Comp should be drawn
//	pUI->GetPointClicked(Cx, Cy);
//
//	//Clear Status Bar
//	pUI->ClearStatusBar();
//
//
//	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
//
//	//Calculate the rectangle Corners
//	int compWidth = pUI->getCompWidth();
//	int compHeight = pUI->getCompHeight();
//
//	pGInfo->PointsList[0].x = Cx - compWidth / 2;
//	pGInfo->PointsList[0].y = Cy - compHeight / 2;
//	pGInfo->PointsList[1].x = Cx + compWidth / 2;
//	pGInfo->PointsList[1].y = Cy + compHeight / 2;
//
//	Switch* pR = new Switch(pGInfo);
//	pManager->AddComponent(pR);


	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	//Print Action Message
	pUI->PrintMsg("Adding a new Switch: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	bool conflict = isConflict(Cx, Cy, compWidth, compHeight);
	if (conflict) {

		pUI->PrintMsg("Invalid Point!!!");
		std::cout << "a777aaaaaaaaaa";
		pUI->GetPointClicked(Cx, Cy);
		pUI->ClearStatusBar();

		return;
	}
	//Print Action Message
	std::cout << conflict << "   ok\n";
	pUI->PrintMsg("Enter a label for it");

	//Get Center point of the area where the Comp should be drawn
	string text = pUI->GetSrting();

	//Clear Status Bar
	pUI->ClearStatusBar();





	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp



	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Switch* pR = new Switch(pGInfo, text);

	pManager->AddComponent(pR);
}

void ActionAddSwitch::Undo()
{}

void ActionAddSwitch::Redo()
{}

