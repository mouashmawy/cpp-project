#include "ActionPaste.h"

#include "..\Components\Resistor.h"
#include "..\Components\Lamp.h"
#include "..\Components\Battery.h"
#include "..\Components\Switch.h"
#include "..\Components\Buzzer.h"
#include "..\Components\Fuse.h"
#include "..\Components\Ground.h"
#include "..\Components\Module.h"


#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionPaste::ActionPaste(ApplicationManager* pApp) :ActionCopyCutPaste(pApp)
{
	this->pApp = pApp;
}

ActionPaste::~ActionPaste(void)
{
}




Component* ActionPaste::CompInPlace(int xx, int yy)
{

	UI* pUI = pManager->GetUI();
	Component** ListOfComp = pManager->getCompList();
	int CompCount = pManager->getCompCount();


	for (int i = 0; i < CompCount; i++) {
		if (
			xx >= ListOfComp[i]->getC()->PointsList[0].x &&
			yy >= ListOfComp[i]->getC()->PointsList[0].y &&
			xx <= ListOfComp[i]->getC()->PointsList[1].x &&
			yy <= ListOfComp[i]->getC()->PointsList[1].y
			)	return ListOfComp[i];


	}
	return nullptr;
}

void ActionPaste::Execute()
{

	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	int Sx = 0, Sy = 0;
	

	pUI->PrintMsg("Press anywhere to paste the component");
	pUI->GetPointClicked(Sx, Sy);
	if (isConflict(Sx, Sy, pUI->getCompWidth(), pUI->getCompHeight())) {
		pUI->PrintMsg("Press anywhere else to paste it");
		pUI->GetPointClicked(x1, y1);
		pUI->ClearStatusBar();
		ActionPaste::Execute();

	}
	else {

		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();
		x1 = Sx - compWidth / 2;
		y1 = Sy - compHeight / 2;
		x2 = Sx + compWidth / 2;
		y2 = Sy + compHeight / 2;
		pGInfo->PointsList[0].x = x1;
		pGInfo->PointsList[0].y = y1;
		pGInfo->PointsList[1].x = x2;
		pGInfo->PointsList[1].y = y2;





		Resistor* pR = new Resistor(pGInfo, "", 0);

		pManager->AddComponent(pR);

	}
										
			
}

void ActionPaste::Undo()
{}

void ActionPaste::Redo()
{}

