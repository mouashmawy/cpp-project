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
#include "Actions\ActionMove.h"
#include "Actions\ActionEditL.h"
#include "Actions\ActionEditV.h"
#include "Actions\ActionSaveCircut.h"
#include "Actions\ActionLoadCircut.h"
#include "Actions\ActionCopy.h"
#include "Actions\ActionCut.h"
#include "Actions\ActionPaste.h"
#include "Actions\ActionDelete.h"
#include "Actions\ActionSimulate.h"
#include "Actions\ActionDesign.h"
#include "Actions\ActionModDes.h"
#include "Actions\ActionAddModS.h"
#include "Actions\ActionExit.h"


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
bool ApplicationManager::isConflict(int xx, int yy, int ww, int hh, Component* c) const
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

			) {
			if (CompList[i] == c) return false;
			else return true;
		}
			

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

Connection** ApplicationManager::getConnList()
{
	return ConnList;
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

int ApplicationManager::getConnCount() const
{
	return ConnCount;
}


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

		case MOVE:
			pAct = new ActionMove(this);
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
			pAct = new ActionCut(this);
			break;

		case PASTE:
			pAct = new ActionPaste(this);
			break;

		
		case DEL:
			pAct = new ActionDelete(this);
			break;


		case SIM_MODE:
			pAct = new ActionSimulate(this);
			break;

		case DSN_MODE:
			pAct = new ActionDesign(this);
			break;

		case MOD_DES_MODE:
			pAct = new ActionModDes(this);
			break;

		case FROM_DES_MODE:
			pAct = new ActionAddModS(this);
			break;

		case EXIT:
			pAct = new ActionExit(this);
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
		if (component_type == "SWT")
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
	}
	int connCount , ID1, ID2;
	file >> connCount;
	for (int i = 0; i < connCount; i++) {
		file >> ID1 >> ID2;
		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		Component* Comp1 = getIdCmpt(ID1);
		Component* Comp2 = getIdCmpt(ID2);
		Connection* pc = new Connection(pGInfo," ", Comp1, Comp2);
		pc->Load(pUI, Comp1, Comp2);
		AddConnection(pc);
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
/// it returns the components which has the same ID

Component* ApplicationManager::getIdCmpt(int number) {
	
	for (int i = 0; i < CompCount; i++) {
		Component* pC = CompList[i];
		if (getCmptid(pC) == number) {
			return CompList[i];
		}
		delete pC;
	}
}

////////////////////////////////////////////////////////////////////////////

void ApplicationManager::DeleteComponent(Component* pComp)
{
	for (int i = 0; i < CompCount; i++) { 
		if (pComp == CompList[i]){
			CompList[i] = CompList[i + 1];
			CompCount--;
		}
			
	}
	pUI->ClearDrawingArea();

}

/////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteConnection(Connection* pConn) {
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] == pConn) {
			ConnList[i] = ConnList[i + 1];
			ConnCount--;
		}
	}
	pUI->ClearDrawingArea();
}
////////////////////////////////////////////////////////////////////
/// Deleting and rearranging the CompList///

void ApplicationManager::DeleteAll() {
	
	Component* ComptempList[MaxCompCount];
	Connection* ConntempList[MaxCompCount];
	int compCounter = 0;

	for (int i = 0; i <= CompCount;i++ ) {
		if (CompList[i]->CheckSelection()){
			Connection** Conn1 = CompList[i]->getTerm1();
			Connection** Conn2 = CompList[i]->getTerm2();
			for (int i = 0; i < CompList[i]->t1_conn_c(); i++) {
				DeleteConnection(Conn1[i]);
			}
			for (int i = 0; i < CompList[i]->t2_conn_c(); i++) {
				DeleteConnection(Conn2[i]);
			}
			DeleteComponent(CompList[i]);
		}	
	}

	for (int i = 0; i < CompCount; i++)
		if (CompList[i] != nullptr) {
			ComptempList[compCounter] = CompList[i];
			compCounter++;
		}
	for (int i = 0; i < CompCount; i++) {
		CompList[i] = ComptempList[i];
		ComptempList[i] = nullptr;

	}
	CompCount = compCounter;
	int connCounter = 0;

	for (int i = 0; i < ConnCount; i++)
		if (CompList[i] != nullptr) {
			ConntempList[connCounter] = ConnList[i];
			connCounter++;
		}
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i] = ConntempList[i];
		ConntempList[i] = nullptr;
	}
	ConnCount = connCounter;
}


bool ApplicationManager::CheckifGround()
{
	int groundC = 1;

	for (int i = 0; i < CompCount; i++)
	{
		Component* p = dynamic_cast<Ground*>(CompList[i]);
		if (!p) 
			groundC++;
	}

	if (groundC > 1)
		return false;
	else
		return true;
}

//////////////////////////////////////////////////////////////////


bool ApplicationManager::checkifFullyConnected()
{
	int c = 0;
	for (int i = 0; i < CompCount; i++)     //loop on complist.
	{
		if (CompList[i]->t1_conn_c() >0 && CompList[i]->t2_conn_c() > 0)
			c++;

	}

	if (c == CompCount)return true;
	else return false;
}






//check circuit has no parallel branches.
bool ApplicationManager::checkifNoParallelBranches()
{
	int c = 0;
	for (int i = 0; i < CompCount; i++)     //loop on complist.
	{
		if (CompList[i]->t1_conn_c() < 2 && CompList[i]->t2_conn_c() < 2)
			c++;
			
	}
	if (c == CompCount)return true;
	else return false;

}

