#include "ActionAddBattery.h"
#include "..\ApplicationManager.h"
#include<iostream>

ActionAddBat::ActionAddBat(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBat::~ActionAddBat(void)
{
}

void ActionAddBat::Execute()
{

	////Get a Pointer to the user Interfaces
	//UI* pUI = pManager->GetUI();

	////Print Action Message
	//pUI->PrintMsg("Adding a new Battery: Click anywhere to add");

	////Get Center point of the area where the Comp should be drawn
	//pUI->GetPointClicked(Cx, Cy);

	////Clear Status Bar
	//pUI->ClearStatusBar();


	//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	////Calculate the rectangle Corners
	//int compWidth = pUI->getCompWidth();
	//int compHeight = pUI->getCompHeight();

	//pGInfo->PointsList[0].x = Cx - compWidth / 2;
	//pGInfo->PointsList[0].y = Cy - compHeight / 2;
	//pGInfo->PointsList[1].x = Cx + compWidth / 2;
	//pGInfo->PointsList[1].y = Cy + compHeight / 2;

	//Battery* pBat = new Battery(pGInfo);
	//pManager->AddComponent(pBat);



	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	//Print Action Message
	pUI->PrintMsg("Adding a new Battery: Click anywhere to add");

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

	Battery* pR = new Battery(pGInfo, text);
	pManager->AddComponent(pR);
}

void ActionAddBat::Undo()
{}

void ActionAddBat::Redo()
{}

