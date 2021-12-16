#include "ActionAddRes.h"
#include "..\ApplicationManager.h"
#include <iostream>
ActionAddRes::ActionAddRes(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddRes::~ActionAddRes(void)
{
}

void ActionAddRes::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	//pUI->Get();
	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

	int i = 0;
	while (0) { //you can ignore this now!!!!!!!!!!!!!!!!!!!!!!!
		int Sx=0, Sy=0;
		cout << "x1";
		

		pUI->GetPreviousClick(Sx, Sy);
		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		cout <<endl<< Cx << " "<< Cy << endl;


		int x1= Sx - compWidth / 2,
			y1= Sy - compHeight / 2,
			x2= Sx + compHeight / 2,
			y2= Sy + compHeight / 2;


		pGInfo->PointsList[0].x = x1;
		pGInfo->PointsList[0].y = y1;
		pGInfo->PointsList[1].x = x2;
		pGInfo->PointsList[1].y = y2;


		cout << pGInfo->PointsList[0].x << " " <<
			pGInfo->PointsList[0].y << " " <<
			pGInfo->PointsList[1].x << " " <<
			pGInfo->PointsList[1].y << " " << endl;

		if (! isConflict(Sx, Sy, compWidth, compHeight)) {
			pUI->DrawSpam(*pGInfo);
			Sleep(100);
			pUI->ClearSth(x1,y1,x2,y2);
		}
	}
	



	
	pUI->GetPointClicked(Cx, Cy);
	pUI->ClearStatusBar();	
	bool conflict = isConflict(Cx, Cy, compWidth, compHeight);
	if (conflict) {
		
		pUI->PrintMsg("Invalid Point!!!");

		pUI->GetPointClicked(Cx, Cy);
		pUI->ClearStatusBar();

		return;
	}
	//Print Action Message
	pUI->PrintMsg("Enter a label for it");

	//Get Center point of the area where the Comp should be drawn
	string text = pUI->GetSrting();

	//Clear Status Bar
	pUI->ClearStatusBar();
	

	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	


	pGInfo->PointsList[0].x = Cx - compWidth/2;
	pGInfo->PointsList[0].y = Cy - compHeight/2;
	pGInfo->PointsList[1].x = Cx + compWidth/2;
	pGInfo->PointsList[1].y = Cy + compHeight/2;
	 
	Resistor* pR = new Resistor(pGInfo,text);
	pManager->AddComponent(pR);

	
	}

void ActionAddRes::Undo()
{}

void ActionAddRes::Redo()
{}

