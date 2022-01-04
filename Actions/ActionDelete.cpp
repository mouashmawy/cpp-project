#include "ActionDelete.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionDelete::~ActionDelete(void)
{
}


Component* ActionDelete::CompInPlace(int xx, int yy)
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



void ActionDelete::Execute()
{
/*
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	
	//Print Action Message
	//pUI->PrintMsg("selecting an item....");
	pUI->GetPreviousClick(x1, y1);
//	cout <<"xx"<< x1 << " " << y2 << endl;
	//pUI->ClearStatusBar();

	Component* compSel = CompInPlace(x1, y1);
	
	if (compSel == nullptr) {
		return;
	}
	compSel->Delete(pUI,true);
	
	Component* compSel2 = CompInPlace(x1, y1);
	if (compSel2 == nullptr) {
		compSel->Draw(pUI);
		pUI->ClearStatusBar();

		return;
	}
	
	else ActionDelete::Execute();
						*/
	//Component* pR= ..........;
	//pManager->DeleteComponent(pR);
			
}

void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}

