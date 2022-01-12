#include "ActionEditV.h"
#include "..\ApplicationManager.h"
#include <iostream>
#include<sstream>
using namespace std;



ActionEditV::ActionEditV(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
	
}

ActionEditV::~ActionEditV(void)
{
}





Component* ActionEditV::CompInPlace(int xx, int yy)
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






void ActionEditV::Execute()
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

	compSel->Draw(pUI, true);

	pUI->PrintMsg("edit the Value write sth...");

	string text = pUI->GetSrting();

	// turning the string to double
	stringstream v1(text);

	double V = 0;

	v1 >> V;
	

	//Clear Status Bar
	pUI->ClearStatusBar();

	pUI->ClearLabel(compSel->getC()->PointsList[0].x,
		compSel->getC()->PointsList[0].y);
	compSel->setValue(V);


}

void ActionEditV::Undo()
{}

void ActionEditV::Redo()
{}
