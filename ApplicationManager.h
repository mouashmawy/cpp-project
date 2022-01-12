#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components\Connection.h"

//Main class that manages everything in the application.
class ApplicationManager
{
public:
	enum { MaxCompCount = 200, MaxConnCount = 200 , MaxStaffCount = 200};	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	int ConnCount;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount];
	Component* pCpdComp;

	UI* pUI; //pointer to the UI



public:	
	ApplicationManager(); //constructor

	bool isConflict(int xx, int yy, int ww, int hh, Component* c=nullptr) const;

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window



	//Gets a pointer to UI Object
	UI* GetUI();
	/////////////////////////////////////////////

	void SaveCircut(ofstream& file);
	void LoadCircut(ifstream& file, string fileName);
	///////////////////////////////////////
	void DeleteComponent(Component* pComp);
	void DeleteAll();
	void multiDeleteComp();

	bool CheckifGround();

	bool checkifFullyConnected();

	bool checkifNoParallelBranches();

	//////////////////////////////////////

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);


	void AddConnection(Connection* pConn);
	bool chkOneGrd();
	///////////////////////////////////// 
	int ApplicationManager::getCmptid(Component* comp);
	////////////////////////////////////
	Component** getCompList();

	void setCpdComp(Component* c);
	Component* getCpdComp();
	Component* getId( int number);

	int getCompCount() const;
	//destructor
	~ApplicationManager();
};

#endif