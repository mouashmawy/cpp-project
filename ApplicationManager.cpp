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
		if (CompList[i] == pComp)
		{
			for (int j = i; j < CompCount - 1; j++) {
				CompList[j] = CompList[j + 1]; 
			}
			CompCount--;
		}
	}
	pUI->ClearDrawingArea();
	UpdateInterface();
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

	file << CompCount<<endl;
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->Save(file);
	}
	file <<"Connections"<<endl << ConnCount << endl;
	for (int i = 0; i < ConnCount; i++) {
		int Cmpt1 = getCmptid(ConnList[i]->getCmpt(1));
		int Cmpt2 = getCmptid(ConnList[i]->getCmpt(2));
		ConnList[i]->Save(file, Cmpt1, Cmpt2);
	}
}

/////////////////////////////////////////////////////////////////

void ApplicationManager::LoadCircut(ifstream& file, string fileName) {
	cout << "Ayyad";
	file.open(fileName);

	string component_type, label;
	int Count, ID;
	double value, x, y;
	
	file >> Count;
	for (int i = 0; i < Count; i++) {
		
		file >> component_type >> ID >> label >> value >> x >> y;
		GraphicsInfo* pG = new GraphicsInfo(2);
		pG->PointsList[0].x = x;
		pG->PointsList[0].y = y;
		pG->PointsList[1].x = x + pUI->getCompWidth();
		pG->PointsList[1].y = y + pUI->getCompHeight();

		if (component_type == "RES")
		{
			Resistor* pR = new Resistor(pG , label , value);
			AddComponent(pR);
			CompList[i]->Load(ID);
		}
		if (component_type == "LMP")
		{
			Lamp* pL = new Lamp(pG, label , value);
			AddComponent(pL);
			CompList[i]->Load(ID);
		}
		if (component_type == "swt")
		{
			Switch* pS = new Switch(pG, label, value);
			AddComponent(pS);
			CompList[i]->Load(ID);
		}
		if (component_type == "GND")
		{
			Ground* pVG = new Ground(pG, label,value);
			AddComponent(pVG);
			CompList[i]->Load(ID);
		}
		if (component_type == "BAT")
		{
			Battery* pB = new Battery(pG, label, value);
			AddComponent(pB);
			CompList[i]->Load(ID);
		}
		if (component_type == "BUZ")
		{
			Buzzer* pZ = new Buzzer(pG, label, value);
			AddComponent(pZ);
			CompList[i]->Load(ID);
		}
		if (component_type == "FUS")
		{
			Fuse* pF = new Fuse(pG, label, value);
			AddComponent(pF);
			CompList[i]->Load(ID);
		}
		//else if (CompList[i]->Component_type == "LMP") CompList[i]->Draw(pUI);

		//else if (CompList[i]->Component_type == "BAT") CompList[i]->Draw(pUI);

		//else if (CompList[i]->Component_type == "SWT") CompList[i]->Draw(pUI);

		//else if (CompList[i]->Component_type == "BUZ") CompList[i]->Draw(pUI);

		//else if (CompList[i]->Component_type == "FUS") CompList[i]->Draw(pUI);

		//else if (CompList[i]->Component_type == "GND")CompList[i]->Draw(pUI);

		//else if (CompList[i]->Component_type == "CON") CompList[i]->Draw(pUI);
	}
}

//////////////////////////////////////////////////////////////////////////////
/// Getting the ID of the compnents

int ApplicationManager::getCmptid(Component* comp) {
	for (int i = 0; i < CompCount; i++) {
		if (comp == CompList[i])
			return i +1;
	}
}

/////////////////////////////////////////////////////////////////////////////

void ApplicationManager::DeleteAll() {
	
	for (int i = 0; i <= CompCount; i++) {
		cout << "count:" << CompCount << endl;
		cout << "enter: "<<CompList[i]->CheckSelection()<<endl;
		if (CompList[i]->CheckSelection()){
			cout << "Ayyad: " << i<< endl;
			DeleteComponent(CompList[i]);
		}
	}

}

