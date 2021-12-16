#include "ActionEditL.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;



ActionEditL::ActionEditL(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionEditL::~ActionEditL(void)
{
}





Component* ActionEditL::CompInPlace(int xx, int yy)
{
	cout << "aaaaaaaaaaaaaaaaa";
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






void ActionEditL::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp


	//Print Action Message
	pUI->PrintMsg("editing an item....");
	pUI->GetPointClicked(x1, y1);
	pUI->ClearStatusBar();

	Component* compSel = CompInPlace(x1, y1);
	if (compSel == nullptr) {
		pUI->PrintMsg("Nothing found here!!");
		pUI->GetPointClicked(x1, y1);
		pUI->ClearStatusBar();
		return;
	}

	compSel->Draw(pUI,true);

	pUI->PrintMsg("edit the label write sth...");

	string text = pUI->GetSrting();

	//Clear Status Bar
	pUI->ClearStatusBar();
	
	pUI->ClearLabel(compSel->getC()->PointsList[0].x,
					compSel->getC()->PointsList[0].y);
	compSel->setLabel(text);
										
			
}

void ActionEditL::Undo()
{}

void ActionEditL::Redo()
{}

