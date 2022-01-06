#include "ActionCopy.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionCopy::ActionCopy(ApplicationManager* pApp) :ActionCopyCutPaste(pApp)
{
	this->pApp = pApp;
}



ActionCopy::~ActionCopy(void)
{
}




Component* ActionCopy::CompInPlace(int xx, int yy)
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

void ActionCopy::Execute()
{
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); 	
	pUI->PrintMsg("Press sth to copy");

	pUI->GetPointClicked(x1, y1);
	Component* compSel = CompInPlace(x1, y1);
	
	if (compSel == nullptr) {
		pUI->PrintMsg("nothing to copy");
		pUI->GetPointClicked(x1, y1);
		pUI->ClearStatusBar();
		return;
	}
	compSel->Draw(pUI,true);
	pManager->setCpdComp(compSel);
	
	pUI->PrintMsg(compSel->getType()+" "+compSel->getLabel() + " copied successfully");
	pUI->GetPointClicked(x1, y1);
	pUI->ClearStatusBar();
	compSel->Draw(pUI);


										
			
}

void ActionCopy::Undo()
{}

void ActionCopy::Redo()
{}

