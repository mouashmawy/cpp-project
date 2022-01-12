#pragma once
#include "Component.h"

class Resistor:public Component
{
	int Cx, Cy;


public:
	Resistor(GraphicsInfo *r_GfxInfo,string name,double value);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*,bool selected=false);	//Draws the resistor
	GraphicsInfo* getC();
	virtual void Save(ofstream& file);
	virtual void Load(int ID);
	virtual void Delete();
	Point getCPoint() const;


};
