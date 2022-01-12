#include "ActionMove.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionMove::~ActionMove(void)
{
}


Component* ActionMove::CompInPlace(int xx, int yy) 
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


void ActionMove::Execute()
{
	cout << "looooooooooooooooooooooooooooooooooooooool";
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	pUI->GetPreviousClick(x1, y1);

	Component* compSel = CompInPlace(x1, y1);
	
	if (compSel == nullptr) {
		return;
	}

	GraphicsInfo* InitpGInfo = compSel->getC();
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();


	int Cx=0, Cy=0;

	while (1) { //you can ignore this now!!!!!!!!!!!!!!!!!!!!!!!
		int Sx = 0, Sy = 0;



		pUI->GetPreviousClick(Sx, Sy);




		x1 = Sx - compWidth / 2;
		y1 = Sy - compHeight / 2;
		x2 = Sx + compWidth / 2;
		y2 = Sy + compHeight / 2;
		pGInfo->PointsList[0].x = x1;
		pGInfo->PointsList[0].y = y1;
		pGInfo->PointsList[1].x = x2;
		pGInfo->PointsList[1].y = y2;


		if (pUI->isInDrawingArea(*pGInfo)) {
			compSel->setC(pGInfo);
			Sleep(30);
			pUI->ClearDrawingArea();
			pManager->UpdateInterface();
		}
		

		pUI->GetPointClicked2(Cx, Cy);


		if (Cx != 0 || Cy != 0) { //means you clicked the mouse
			if ( pManager->isConflict(Sx, Sy, compWidth, compHeight, compSel)) {
				pUI->ClearStatusBar();
				pUI->PrintMsg("Invalid Point Choose another");
				Cx = 0; Cy = 0;

				//intial pGinfo
				pUI->ClearDrawingArea();
				compSel->setC(InitpGInfo);
				pManager->UpdateInterface();

			}
			else break;

		}

	}


	
	pUI->PrintMsg(compSel->getType()+"::      "+compSel->getLabel()	+
		"  moved successfully");
										
			


}

void ActionMove::Undo()
{}

void ActionMove::Redo()
{}

