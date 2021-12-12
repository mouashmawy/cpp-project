#include "ActionAddRes.h"
#include "..\ApplicationManager.h"
#include <iostream>
ActionAddRes::ActionAddRes(ApplicationManager *pApp):Action(pApp)
{
	
}

ActionAddRes::~ActionAddRes(void)
{
}


bool ActionAddRes::isConflict(int xx,int yy,int ww,int hh) const
{
	Component** ListOfComp = pManager->getCompList();
	int CompCount = pManager->getCompCount();
	
	
	if (yy > 600 - hh / 2 || yy < 80 + hh) return true;
	for (int i = 0; i < CompCount; i++) {
		if (
			(xx >= ListOfComp[i]->getC()->PointsList[0].x - ww/2 &&
			yy >= ListOfComp[i]->getC()->PointsList[0].y - hh &&
			xx <= ListOfComp[i]->getC()->PointsList[1].x + ww/2 &&
			yy <= ListOfComp[i]->getC()->PointsList[1].y + hh)
			)	return true;
	}
	return false;
}




void ActionAddRes::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

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
	std::cout << conflict <<"   ok\n";
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

