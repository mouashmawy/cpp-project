#include "ActionCut.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionCut::ActionCut(ApplicationManager* pApp) :ActionCopyCutPaste(pApp)
{
	this->pApp = pApp;
}



ActionCut::~ActionCut(void)
{
}




Component* ActionCut::CompInPlace(int xx, int yy)
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


void ActionCut::Execute()
{
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); 	
	pUI->PrintMsg("Press sth to cut");

	pUI->GetPointClicked(x1, y1);
	Component* compSel = CompInPlace(x1, y1);
	
	if (compSel == nullptr) {
		pUI->PrintMsg("nothing to cut");
		pUI->GetPointClicked(x1, y1);
		pUI->ClearStatusBar();
		return;
	}
	compSel->Draw(pUI,true);
	pManager->setCpdComp(compSel);
	/// <here we must make Delete section >
	/// //////////////////////////////////
	/// </from Ayyad>
	pUI->PrintMsg("Comp "+compSel->getType() + " " + compSel->getLabel() + " cut successfully");
	pUI->GetPointClicked(x1, y1);
	pUI->ClearStatusBar();
	compSel->Draw(pUI);


										
			
}

void ActionCut::Undo()
{}

void ActionCut::Redo()
{}

