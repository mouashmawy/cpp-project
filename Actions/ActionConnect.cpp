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


Component* ActionConnect::CompInPlace(int xx, int yy, side &lr) 
{
	UI* pUI = pManager->GetUI();
	Component** ListOfComp = pManager->getCompList();
	int CompCount = pManager->getCompCount();

	lr = RIGHT;
	for (int i = 0; i < CompCount; i++) {
		if (
			xx >= ListOfComp[i]->getC()->PointsList[0].x &&
			yy >= ListOfComp[i]->getC()->PointsList[0].y &&
			xx <= ListOfComp[i]->getC()->PointsList[1].x &&
			yy <= ListOfComp[i]->getC()->PointsList[1].y
			)

		{
			if (xx <= ListOfComp[i]->getC()->PointsList[0].x + pUI->getCompWidth()/2
				) lr = LEFT;


			return ListOfComp[i];
		}
			
			
			
	}
	return nullptr;
}



void ActionConnect::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	side lr1, lr2;

	//Print Action Message
	pUI->PrintMsg("Adding a new Connection: Click the first item to connect");
	pUI->GetPointClicked(x1, y1);
	pUI->ClearStatusBar();
	Component* comp1 = CompInPlace(x1, y1, lr1);
	if (comp1 == nullptr) {
		pUI->PrintMsg("Invalid!! you have to choose an item");
		pUI->ClearStatusBar();
		return;
	}
	//Print Action Message
	pUI->PrintMsg("Click the second item to connect");
	pUI->GetPointClicked(x2, y2);
	pUI->ClearStatusBar();
	Component* comp2 = CompInPlace(x2, y2, lr2);
	if (comp2 == nullptr) {
		pUI->PrintMsg("Invalid!! you have to choose an item");
		return;
	}


	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	//cout << "1:   " << lr1 << lr2<<endl;
	pUI->setLRforconnect(lr1, lr2);
	pGInfo->PointsList[0].x = x1;
	pGInfo->PointsList[0].y = y1;
	pGInfo->PointsList[1].x = x2;
	pGInfo->PointsList[1].y = y2;





	if (

		((lr1 == 0 && lr2 == 1 && x1 > x2) || (lr1 == 1 && lr2 == 0 && x2 > x1)) ||
		(lr1 == 0 && lr2 == 0 && x1 > x2)	||
		(lr1 == 0 && lr2 == 0 && x2 > x1)	||
		(lr1 == 1 && lr2 == 1 && x1 < x2)	||
		(lr1 == 1 && lr2 == 1 && x2 < x1)	) {
		Connection* pConn = new Connection(pGInfo, comp1, comp2);
		pManager->AddConnection(pConn);
	}
	else {
		pUI->PrintMsg("Can't connect by these nodes...");
		pUI->GetPointClicked(x1, x2);
		pUI->ClearStatusBar();
	}
}

void ActionConnect::Undo()
{}

void ActionConnect::Redo()
{}

