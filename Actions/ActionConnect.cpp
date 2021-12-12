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

void ActionConnect::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Connection: Click the first item to connect");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(x1, y1);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

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

	Connection* pConn = new Connection(pGInfo);
	pManager->AddConnection(pConn);
}

void ActionConnect::Undo()
{}

void ActionConnect::Redo()
{}

