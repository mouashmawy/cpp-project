#include "ActionExit.h"
#include "../ApplicationManager.h"
#include<windows.h>
#include <fstream>

ActionExit::ActionExit(ApplicationManager* pApp) : Action(pApp)
{
	
}


ActionExit::~ActionExit(void)
{

}

void ActionExit::Execute() {
	UI* pUI = pManager->GetUI();
	ofstream Save;
	Save.open("Saved\\Exited.txt");
	pManager->SaveCircut(Save);
	Sleep(400);
	pUI->PrintMsg("Application is closing");
	Sleep(200);
	


}

void ActionExit::Undo()
{}

void ActionExit::Redo()
{}
