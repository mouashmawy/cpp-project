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
	compSel->Draw(pUI,true);
	
	pUI->PrintMsg(compSel->getType()+"::      "+
		"Label: "+compSel->getLabel()	+
		"   ---   Value: " + to_string(compSel->getValue())  );
	pUI->GetPointClicked(x1, y1);

	Component* compSel2 = CompInPlace(x1, y1);
	if (compSel2 == nullptr) {
		compSel->Draw(pUI);
		pUI->ClearStatusBar();

		return;
	}
	else ActionCopy::Execute();
										
			
}

void ActionCopy::Undo()
{}

void ActionCopy::Redo()
{}

