#pragma once
#include "Component.h"

class Module:public Component
{
	int Cx, Cy;
	double r1, r2, r3, r4, r5;
	double Req;

public:
	Module(GraphicsInfo *r_GfxInfo,string name,double val=0);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*,bool selected=false);	//Draws the Module
	GraphicsInfo* getC();
	void Save(ofstream& file);
	void Load(int ID);
	void Delete();
	Point getCPoint() const;


};
