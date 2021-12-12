#include "ActionAddSwitch.h"
#include "..\ApplicationManager.h"
#include "../Components/Switch.h"

ActionAddSwitch::ActionAddSwitch(ApplicationManager* pApp) : Action(pApp)
{
}

ActionAddSwitch::~ActionAddSwitch(void)
{
}

void ActionAddSwitch::Execute()
{

	
	UI* pUI = pManager->GetUI();

	
	pUI->PrintMsg("Adding a new Swtich: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Switch* pR = new Switch(pGInfo);
	pManager->AddComponent(pR);
}

void ActionAddSwitch::Undo()
{}

void ActionAddSwitch::Redo()
{}

