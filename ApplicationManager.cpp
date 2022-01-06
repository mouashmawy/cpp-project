#include <fstream>
#include <iostream>
#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddLamp.h"
#include "Actions\ActionAddBattery.h"
#include "Actions\ActionAddSwitch.h"
#include "Actions\ActionAddBuzzer.h"
#include "Actions\ActionAddFuse.h"
#include "Actions\ActionAddGround.h"
#include "Actions\ActionAddModule.h"
#include "Actions\ActionConnect.h"
#include "Actions\ActionSelect.h"
#include "Actions\ActionEditL.h"
#include "Actions\ActionEditV.h"
#include "Actions\ActionSaveCircut.h"
#include "Actions\ActionLoadCircut.h"
#include "Actions\ActionCopy.h"
#include "Actions\ActionPaste.h"
#include "Actions\ActionDelete.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;

	ConnCount = 0;
	for (int i = 0; i < MaxConnCount; i++)
		ConnList[i] = nullptr;


	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
/////////////////////////////////////////////////////////////////////
bool ApplicationManager::isConflict(int xx, int yy, int ww, int hh) const
{


	if (yy > pUI->gB().height - pUI->gB().StatusBarHeight - hh / 2 -1 ||
		yy < pUI->gB().ToolBarHeight + hh ||
		xx > pUI->gB().widthTD - pUI->gB().EditBarWidth - ww/2
		
		) return true;


	for (int i = 0; i < CompCount; i++) {
		if (
			(xx >= CompList[i]->getC()->PointsList[0].x - ww / 2 &&
				yy >= CompList[i]->getC()->PointsList[0].y - hh &&
				xx <= CompList[i]->getC()->PointsList[1].x + ww / 2 &&
				yy <= CompList[i]->getC()->PointsList[1].y + hh)
			)	return true;

	}

	return false;
}





////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
void ApplicationManager::AddConnection(Connection* pConn)
{
	ConnList[ConnCount++] = pConn;

}
Component** ApplicationManager::getCompList()
{
	return CompList;
}
void ApplicationManager::setCpdComp(Component* c)
{
	pCpdComp = c;
}
Component* ApplicationManager::getCpdComp()
{
	return pCpdComp;
}
int ApplicationManager::getCompCount() const
{
	return CompCount;
}
void ApplicationManager::DeleteComponent(Component* pComp)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] == pComp) {
			CompList[i] = CompList[i + 1];
		}
		else CompList[i] = CompList[i];
	}
}
////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////
ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;

		case ADD_LAMP:
			pAct = new ActionAddLamp(this);
			break;

		case ADD_BATTERY:
			pAct = new ActionAddBat(this);
			break;

		case ADD_SWITCH:
			pAct = new ActionAddSwitch(this);
			break;
			///////////////////555555555555555555555555555555555555555
		case ADD_BUZZER:
			pAct = new ActionAddBuzzer(this);
			break;
		case ADD_FUSE:
			pAct = new ActionAddFuse(this);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGround(this);
			break;
		case ADD_MODULE:
			pAct = new ActionAddModule(this);
			break;

		case ADD_CONNECTION:
			pAct = new ActionConnect(this);
			break;
	
		case SELECT:
			pAct = new ActionSelect(this);
			break;

		case EDIT_L:
			pAct = new ActionEditL(this);
			break;

		case EDIT_V:
			pAct = new ActionEditV(this);
			break;

		case SAVE:
			pAct = new ActionSaveCircut(this);
			break;

		case LOAD:
			pAct = new ActionLoadCircut(this);
			break;

		case COPY:
			pAct = new ActionCopy(this);
			break;

		case CUT:
			pAct = new ActionCopy(this);
			break;

		case PASTE:
			pAct = new ActionPaste(this);
			break;

		
		case DEL:
			pAct = new ActionDelete(this);
			break;


		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);
		for (int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}
//////////////////////////////////////////////////////////

void ApplicationManager::SaveCircut(ofstream& file) {

	for (int i = 0; i < CompCount; i++) {
		file << i + 1 << "  ";
		CompList[i]->Save(file);
	}
}

/////////////////////////////////////////////////////////////////

void ApplicationManager::LoadCircut(ifstream& file) {
	for (int i = 0; i < getCompCount(); i++) {
		CompList[i]->Load(file);
		

		Action* pAct = nullptr;
		if (CompList[i]->Component_type == "RES") CompList[i]->Draw(pUI);

		else if (CompList[i]->Component_type == "LMP") CompList[i]->Draw(pUI);

		else if (CompList[i]->Component_type == "BAT") CompList[i]->Draw(pUI);

		else if (CompList[i]->Component_type == "SWT") CompList[i]->Draw(pUI);

		else if (CompList[i]->Component_type == "BUZ") CompList[i]->Draw(pUI);

		else if (CompList[i]->Component_type == "FUS") CompList[i]->Draw(pUI);

		else if (CompList[i]->Component_type == "GND")CompList[i]->Draw(pUI);

		else if (CompList[i]->Component_type == "CON") CompList[i]->Draw(pUI);
	}
}

//////////////////////////////////////////////////////////////////////////////


void ApplicationManager::multiDeleteComp() {
	ActionType ActType;
	ApplicationManager AppManager;
	do
	{
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(DEL);

		//Update the drawing window
		AppManager.UpdateInterface();


	} while (ActType != DEL);
}