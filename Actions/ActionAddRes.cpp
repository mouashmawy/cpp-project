#include "ActionAddRes.h"
#include "..\ApplicationManager.h"
#include <iostream>

ActionAddRes::ActionAddRes(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddRes::~ActionAddRes(void)
{
}

void ActionAddRes::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	//pUI->Get();
	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

	int i = 0;

	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	while (1) { //you can ignore this now!!!!!!!!!!!!!!!!!!!!!!!
		int Sx=0, Sy=0;
		cout << "x1";
		

		pUI->GetPreviousClick(Sx, Sy);
		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		cout <<endl<< Cx << " "<< Cy << endl;


		x1 = Sx - compWidth / 2;
		y1 = Sy - compHeight / 2;
		x2 = Sx + compWidth / 2;
		y2 = Sy + compHeight / 2;


		pGInfo->PointsList[0].x = x1;
		pGInfo->PointsList[0].y = y1;
		pGInfo->PointsList[1].x = x2;
		pGInfo->PointsList[1].y = y2;


		cout << pGInfo->PointsList[0].x << " " <<
			pGInfo->PointsList[0].y << " " <<
			pGInfo->PointsList[1].x << " " <<
			pGInfo->PointsList[1].y << " " << endl;

		if (! pManager->isConflict(Sx, Sy, compWidth, compHeight)) {
			cout << "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu";
			pUI->DrawSpam(*pGInfo);
			Sleep(10);
			pUI->ClearSth(x1,y1,x2,y2);
		}
		pUI->GetPointClicked2(Cx, Cy);
		
		
		if (Cx != 0 || Cy != 0) { //means you clicked the mouse
			if (pManager->isConflict(Sx, Sy, compWidth, compHeight)) {
				pUI->ClearStatusBar();
				pUI->PrintMsg("Invalid Point Choose another");
				Cx = 0; Cy = 0;
			}
			else break;

		}

	}
	



	
	pUI->GetPreviousClick(Cx, Cy);
	pUI->ClearStatusBar();	


	//bool conflict = pManager->isConflict(Cx, Cy, compWidth, compHeight);
	//if (conflict) {
	//	
	//	pUI->PrintMsg("Invalid Point!!!");

	//	pUI->GetPointClicked(Cx, Cy);
	//	pUI->ClearStatusBar();

	//	return;
	//}
	// 

	//Print Action Message
	pUI->PrintMsg("Enter a label for it or just press enter");
	string text = pUI->GetSrting();
	pUI->ClearStatusBar();
	
	pUI->PrintMsg("Enter a value for it or just press enter");
	string textV = pUI->GetSrting();

	double V=0;
	try
	{
		V = stod(textV);
	}
	catch (invalid_argument const& e){}
	catch (out_of_range const& e){}







	pUI->ClearStatusBar();
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	


	pGInfo->PointsList[0].x = Cx - compWidth/2;
	pGInfo->PointsList[0].y = Cy - compHeight/2;
	pGInfo->PointsList[1].x = Cx + compWidth/2;
	pGInfo->PointsList[1].y = Cy + compHeight/2;
	 
	Resistor* pR = new Resistor(pGInfo,text,V);
	pManager->AddComponent(pR);

	
	}

void ActionAddRes::Undo()
{}

void ActionAddRes::Redo()
{}

