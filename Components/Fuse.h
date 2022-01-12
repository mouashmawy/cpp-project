#pragma once
#include "Component.h"

class Fuse :public Component
{
	int Cx, Cy;


public:
	Fuse(GraphicsInfo* r_GfxInfo, string name, double value);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*, bool selected = false);	//Draws the resistor
	GraphicsInfo* getC();
	void Save(ofstream& file);
	void Load(int ID);
	void Delete();
	Point getCPoint() const;

};
