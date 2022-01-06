
#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point
{
	int x,y;
};
enum side { LEFT, RIGHT };


//A structure to contain drawing parameters for each component/connection
//Each component stores its drawing points in this struct 
//For example, a resistor can store points of the rectangluar area it occupies
//The Connection can store the points of its line segments
//this structure can be extended if desired
struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	}

};


class UI
{

	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_RES,		//Resistor item in menu
		ITM_LAMP,		//Lamp
		ITM_BATTERY,
		ITM_FUSE,
		ITM_GROUND,
		ITM_SWITCH,
		ITM_BUZZER,
		ITM_MOD4,
		ITM_CONN,		
		ITM_SIMULATE,
		ITM_EXIT,
		
	


		ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
	};


	enum DsgnMenuItem2 {
		ITM_EDIT_L,
		ITM_EDIT_V,
		ITM_SAVE,
		ITM_LOAD,

		ITM_COPY,
		ITM_CUT,
		ITM_PASTE,
		
		ITM_UNDO,
		ITM_REDO,

		ITM_DEL,
		ITM_MULTIDEL,


		ITM_DSN_CNT2


	};






	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		ITM_CIRC_SIM,	//Circuit Simulate menu item
	
		//TODO:Add more items names here
	
		ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
	};

	enum ConnectCases {

		SameSide,
		Interir,
		Exterior


	};



	MODE AppMode;		//Application Mode (design or simulation)
	


	 static const int	width = 1200, height = 600,	//Window width and height
						widthTD= width-14,
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 60,		//Width of each item in toolbar menu

						EditBarWidth = 50,
						EditItemHeight=44,


						//Arbitrary values, you can change as you wish
						COMP_WIDTH = 100,		//Component Image width
						COMP_HEIGHT = 34;		//Component Image height





	 side lr1, lr2; //left or right for the comps to make connections


	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color



	window *pWind;
	
protected:




public:
	



	struct Basic {

		const int	width = UI::width,
			widthTD = UI::width - 14,
			height = UI::height,	//Window width and height
			
			wx = UI::wx, wy = UI::wy,			//Window starting coordinates
			StatusBarHeight = UI::StatusBarHeight,	//Status Bar Height
			ToolBarHeight = UI::ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
			ToolItemWidth = UI::ToolItemWidth,		//Width of each item in toolbar menu

			EditBarWidth = UI::EditBarWidth,
			EditItemHeight = UI::EditItemHeight,


			//Arbitrary values, you can change as you wish
			COMP_WIDTH = UI::COMP_WIDTH,		//Component Image width
			COMP_HEIGHT = UI::COMP_HEIGHT;		//Component Image height
	};

  

	UI();
	int getCompWidth() const;	//returns Component width
	int getCompHeight() const;	//returns Component height
	
	
	// Input Functions  ---------------------------
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	void GetPointClicked2(int& x, int& y);
	void Get(int& x, int& y);
	void GetPreviousClick(int& x, int& y);
	string GetSrting();		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	
	// Output Functions  ---------------------------
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateEditToolBar();
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar
	void CreateGrid();

	Basic gB();

	

	void PrintMsgX(string msg, int xx, int yy) const;

	void ClearStatusBar() const;
	void ClearLabel(int xx, int yy) const;
	void ClearSth(int x1, int y1, int x2, int y2) ;
	//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

		
	// Draws a resistor
	void DrawResistor(const GraphicsInfo &r_GfxInfo, string my_label, double val, bool selected = false) ;
	void DrawLamp(const GraphicsInfo &r_GfxInfo, string my_label, double val, bool Lighted, bool selected = false) const;
	void DrawSwitch(const GraphicsInfo &r_GfxInfo, string my_label, double val, bool Closed, bool selected = false) const;

	void DrawBattery(const GraphicsInfo &r_GfxInfo, string my_label, double val, bool selected = false) const;
	void DrawFuse(const GraphicsInfo &r_GfxInfo, string my_label, double val, bool selected = false) const;
	void DrawGround(const GraphicsInfo &r_GfxInfo, string my_label, double val, bool selected = false) const;
	void DrawModule(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected) const;
	void DrawBuzzer(const GraphicsInfo &r_GfxInfo, string my_label, double val, bool selected = false) const;

	//Delete Comp
	void DeleteResistor(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected = false)const;
	void DeleteLamp(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected = false) const;
	void DeleteSwitch(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected = false) const;
	void DeleteBattery(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected = false) const;
	void DeleteFuse(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected = false) const;
	void DeleteGround(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected = false) const;
	void DeleteModule(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected) const;
	void DeleteBuzzer(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected = false) const;

	///TODO: Make similar functions for drawing all other components, connections, .. etc

	// Draws Connection
	void DrawConnection(const GraphicsInfo &r_GfxInfo, string text, bool selected = false) const;

	void setLRforconnect(int LR1, int LR2);

	string SwitchImage(int type) const;

	void DrawSpam(const GraphicsInfo& r_GfxInfo, int type) const;
	
	void PrintMsg(string msgbool) const;	//Print a message on Status bar

	

	void DrawTemp(const GraphicsInfo& r_GfxInfo, int type) const;

	~UI();
};

#endif