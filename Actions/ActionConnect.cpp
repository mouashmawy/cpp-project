#include "ActionConnect.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

ActionConnect::ActionConnect(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionConnect::~ActionConnect(void)
{
}



Component* ActionConnect::CompInPlace(int xx, int yy) 
{
	Component** ListOfComp = pManager->getCompList();
	int CompCount = pManager->getCompCount();


	for (int i = 0; i < CompCount; i++) {
		if (
				xx >= ListOfComp[i]->getC()->PointsList[0].x  &&
				yy >= ListOfComp[i]->getC()->PointsList[0].y &&
				xx <= ListOfComp[i]->getC()->PointsList[1].x  &&
				yy <= ListOfComp[i]->getC()->PointsList[1].y 
			)	return ListOfComp[i];
	}
	return nullptr;
}



void ActionConnect::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	
	//Print Action Message
	pUI->PrintMsg("Adding a new Connection: Click the first item to connect");
	pUI->GetPointClicked(x1, y1);
	pUI->ClearStatusBar();
	Component* comp1 = CompInPlace(x1, y1);
	if (comp1 == nullptr) {
		pUI->PrintMsg("Invalid!! you have to choose an item");
		return;
	}
	//Print Action Message
	pUI->PrintMsg("Click the second item to connect");
	pUI->GetPointClicked(x2, y2);
	pUI->ClearStatusBar();
	Component* comp2 = CompInPlace(x2, y2);
	if (comp2 == nullptr) {
		pUI->PrintMsg("Invalid!! you have to choose an item");
		return;
	}


	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();



	pGInfo->PointsList[0].x = comp1->getC()->PointsList[1].x;
	pGInfo->PointsList[0].y = comp1->getC()->PointsList[1].y - compHeight / 2;
	pGInfo->PointsList[1].x = comp2->getC()->PointsList[0].x;
	pGInfo->PointsList[1].y = comp2->getC()->PointsList[0].y + compHeight / 2;


	
												
												/*
	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	
	pGInfo->PointsList[0].x = x1;
	pGInfo->PointsList[0].y = y1;


	//for (int i = 0; i < NumOfComp; i++) {
		//if ()
	//}
	pApp->getCompCount();


	cout << x1 << "  " << y1 << endl;



	//Print Action Message
	pUI->PrintMsg("Click the second item to connect");
	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(x2, y2);
	pUI->ClearStatusBar();
	
	pGInfo->PointsList[1].x = x2;
	pGInfo->PointsList[1].y = y2;
	cout << x2 << "  " << y2 << endl << endl;
	*/
	Connection* pConn = new Connection(pGInfo);
	pManager->AddConnection(pConn);
}

void ActionConnect::Undo()
{}

void ActionConnect::Redo()
{}

