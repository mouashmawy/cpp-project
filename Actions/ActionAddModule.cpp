#include "ActionAddModule.h"
#include "..\ApplicationManager.h"
#include <iostream>

ActionAddModule::ActionAddModule(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddModule::~ActionAddModule(void)
{
}

void ActionAddModule::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	//pUI->Get();
	//Print Action Message
	pUI->PrintMsg("Adding a new Module: Click anywhere to add");

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



		if (! pManager->isConflict(Sx, Sy, compWidth, compHeight)) {
			pUI->DrawSpam(*pGInfo, ITM_MOD4);

			
			Sleep(30);
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
	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;
	pUI->DrawTemp(*pGInfo, ITM_MOD4);
	pUI->ClearStatusBar();	


	//Print Action Message
	pUI->PrintMsg("Enter a LABEL (max 5 chars) OR just press enter");
	string text = pUI->GetSrting();
	pUI->ClearStatusBar();
	
	string Arry_R[4];
	double V[4];
	for (int i = 0; i < 4; i++)
	{


		pUI->PrintMsg("Enter VALUE of RES " + to_string(i + 1) + " (max 9999.9) OR just press enter");

	 Arry_R[i] = pUI->GetSrting();

		
		try
		{
			V[i] = stod(Arry_R[i]);
			/*
			if (V <= 9999.9);
			else V = 9999.9;
			*/
		}
		catch (invalid_argument const& e) { V[i] = 0; }
		catch (out_of_range const& e) { V[i] = 9999.9; }



		pUI->ClearStatusBar();

	}
	double Eqe_V;
	double R1, R2, R3, R4, R5;
	R1 = V[0], R2 = V[1], R3 = V[2], R4 = V[3], R5 = V[4];
	Eqe_V = 1 / ((1 / R1) + (1 / R2)) + 1 / R3 + 1 / ((1 / R4) + (1 / R5));
	 
	Module* pR = new Module(pGInfo,text,Eqe_V);
	pManager->AddComponent(pR);

	
	}

void ActionAddModule::Undo()
{}

void ActionAddModule::Redo()
{}

