#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "Connection.h"


//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
	string m_Label;
protected:
	
	string label;
	double value;
	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	//voltage at terminals 1&2

	static int ID;
	int Cx, Cy;


	//Each terminal is connected to set of connections
	Connection *term1_connections[MAX_CONNS]; //list of pointers to connections
	Connection *term2_connections[MAX_CONNS];

	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;


	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component

	

public:
	string Component_type;
	Component(GraphicsInfo *r_GfxInfo);
	//void setTerm1Volt(double v);		//sets the voltage at terminal1
	//void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2


	bool Selected ;
	virtual void Operate() = 0;	//Calculates the output voltage according to the inputs
	virtual void Draw(UI*,bool selected=false) =0;	//for each component to Draw itself
	virtual GraphicsInfo* getC() ;
	virtual void setC(GraphicsInfo* c);
	string getLabel();
	void setLabel(string ll="");
	double getValue();
	void setValue(double v=0);
	string getType();
	bool CheckSelection();

	virtual void Save(ofstream& file) = 0;
	virtual void Load(int ID) = 0;

	virtual Point getCPoint() const =0;

	virtual void Delete() = 0;
	void Select();

	Connection** getTerm1();
	Connection** getTerm2();

	//virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	//virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	//virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	
	Component();
	bool isHere(int x, int y);

	
	//Destructor must be virtual
	virtual ~Component();
	int t1_conn_c();
	int t2_conn_c();
};

#endif
