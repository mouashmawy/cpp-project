#include "ActionCheckVolt.h"
#include "..\ApplicationManager.h"
#include <iostream>

ActionCheckVolt::ActionCheckVolt(ApplicationManager *pApp):Action(pApp)
{
}

ActionCheckVolt::~ActionCheckVolt(void)
{
}
/// <summary>
/// ///////
/// </summary>
void ActionCheckVolt::Execute()
{
	
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	//pUI->Get();
	//Print Action Message
	pUI->PrintMsg("measuring....");

	int i = 0;

	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	GraphicsInfo* pGInfo = new GraphicsInfo(2);
	while (1) { //you can ignore this now!!!!!!!!!!!!!!!!!!!!!!!
		int Sx=0, Sy=0;

		
	
		pUI->GetPreviousClick(Sx, Sy);




		x1 = Sx - compWidth / 2;
		y1 = Sy - compHeight / 2;
		x2 = Sx + compWidth / 2;
		y2 = Sy + compHeight / 2;
		pGInfo->PointsList[0].x = x1;
		pGInfo->PointsList[0].y = y1;
		pGInfo->PointsList[1].x = x2;
		pGInfo->PointsList[1].y = y2;



			pUI->DrawSpam(*pGInfo, A);

			
			Sleep(10);
			pUI->ClearSth(x1,y1,x2,y2);
		
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
	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;
	pUI->DrawTemp(*pGInfo,ITM_RES);
	pUI->ClearStatusBar();	


	//Print Action Message
	pUI->PrintMsg("Enter a LABEL (max 5 chars) OR just press enter");
	string text = pUI->GetSrting();
	pUI->ClearStatusBar();
	
	pUI->PrintMsg("Enter a VALUE (max 9999.9) OR just press enter");
	string textV = pUI->GetSrting();

	double V;
	try
	{
		V = stod(textV);
		/*
		if (V <= 9999.9);
		else V = 9999.9;
		*/
	}
	catch (invalid_argument const& e) { V = 0; }
	catch (out_of_range const& e) { V = 9999.9; }



	pUI->ClearStatusBar();
	


	 
	Resistor* pR = new Resistor(pGInfo,text,V);
	pManager->AddComponent(pR);

	
	}

void ActionCheckVolt::Undo()
{}

void ActionCheckVolt::Redo()
{}

