#include <iostream>
#include "UI.h"
#include <string>
#include<windows.h>
#include <cmath>
UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colorscd 
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Logic Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateEditToolBar();
	CreateStatusBar();		//Create Status bar
	//CreateGrid();
}


int UI::getCompWidth() const
{
	return COMP_WIDTH;
}

int UI::getCompHeight() const
{
	return COMP_HEIGHT;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click

	/*
	x = round(x / 50) * 50;
	y = round(y / 50) * 50;
	*/

}


void UI::Get(int& x, int& y)
{
	while (1)
	{
		pWind->GetMouseCoord(x, y);	//Wait for mouse click
		cout << x << "  " << y << endl;
		Sleep(100);
	}
	/*
	x = round(x / 50) * 50;
	y = round(y / 50) * 50;
	*/

}


void UI::GetPreviousClick(int& x, int& y) {
	cout << "get me";
	//pWind->GetMouseClick(x, y);
	pWind->GetMouseCoord(x, y);
}


string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:	return ADD_RESISTOR;
			case ITM_LAMP:	return ADD_LAMP;
			case ITM_BATTERY: return ADD_BATTERY;
			case ITM_SWITCH: return ADD_SWITCH;
			case ITM_BUZZER: return ADD_BUZZER;
			case ITM_CONN:	return ADD_CONNECTION;
			case ITM_FUSE: return ADD_FUSE;
			case ITM_GROUND: return ADD_GROUND;
			
			//case ITM_SELECT: return SELECT;
			//case ITM_EDIT: return EDIT;
			case ITM_EXIT:	return EXIT;	
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		
		}
		else if (y > ToolBarHeight && y > StatusBarHeight && x > width - ToolItemWidth - 7 && x < width)
		{
			int ClickedItemOrder = ((y-ToolBarHeight-2) / ToolBarHeight);
			switch (ClickedItemOrder)
			{/*
				case ITM_SELECT: return SELECT;
				case ITM_EDIT: return EDIT;*/
			//case ITM_SELECT:	return SELECT;
			case ITM_EDIT_L:	return EDIT_L;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_EDIT_V: return EDIT_V;
			

			}
		}
		else {
			return SELECT;
		}
	


		/*
		//[2] User clicks on the drawing area
		if ( y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		*/
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
void UI::CreateGrid()
{
	for (int i = 0; i <= width; i += 100) {
		pWind->SetPen(RED, 1);
		pWind->DrawLine(i, ToolBarHeight, i, height - StatusBarHeight);
	}
	for (int i = 0; i <= height; i += 100) {
		pWind->SetPen(RED, 1);
		pWind->DrawLine(0,ToolBarHeight+i,width, ToolBarHeight + i);
	}

}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


void UI::PrintMsgX(string msg, int xx, int yy) const
{
	
	// Print the Message
	pWind->SetFont(15, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->DrawString(xx, yy, msg);
}



//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
// 
// 
// 
// 

void UI::ClearLabel(int xx,int yy)const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor,1000);
	//pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(xx,yy-20 , xx+getCompWidth(), yy);
	
}

void UI::ClearSth(int x1, int y1 , int x2, int y2)
{


	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor, 1000);

	pWind->DrawRectangle(x1, y1, x2,y2);
	cout << "ahhhhhhh";
}



//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_BATTERY] = "images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_LAMP] = "images\\Menu\\Menu_Lamp.jpg";
	MenuItemImages[ITM_BUZZER] = "images\\Menu\\Menu_Buzzer.jpg";
	MenuItemImages[ITM_FUSE] = "images\\Menu\\Menu_Fuse.jpg";
	MenuItemImages[ITM_GROUND] = "images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_CONN] = "images\\Menu\\Menu_Conn.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++) {

		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);

	}

	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	

}
/// <summary>
/// 
/// </summary>

void UI::CreateEditToolBar()
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItem[ITM_DSN_CNT2];

	MenuItem[ITM_EDIT_L] = "images\\Menu\\Menu_Edit_L.jpg";
	MenuItem[ITM_EDIT_V] = "images\\Edit\\Menu_Edit_V.jpg";
	MenuItem[ITM_SAVE] = "images\\Menu\\Menu_Save.jpg";
	MenuItem[ITM_LOAD] = "images\\Menu\\Menu_Load.jpg";
	

	pWind->SetPen(RED,10000);
	pWind->DrawRectangle(width - EditBarWidth - 14, ToolBarHeight, width, height - StatusBarHeight);
	
		//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT2; i++) {
		cout << 1<<endl;
		int x1 = width - EditBarWidth-14,
			y1 = ToolBarHeight+ EditItemHeight*i;

		pWind->DrawImage(MenuItem[i], x1, y1, EditBarWidth,EditItemHeight);

		pWind->SetPen(RED, 2);
		pWind->DrawLine(x1,y1,x1,height-StatusBarHeight);
		
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}





//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

















//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo& r_GfxInfo, string my_label, bool selected) const
{
	string ResImage;
	if (selected)
		ResImage = "Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor

	cout << r_GfxInfo.PointsList[0].y << endl;

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


		pWind->DrawImage(ResImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
		PrintMsgX("RES: " + my_label, xc, yc - COMP_HEIGHT * 2 / 3); 
		

}
//TODO: Add similar functions to draw all other components

void UI::DrawLamp(const GraphicsInfo& r_GfxInfo, string my_label, bool selected) const
{
	string LampImage;
	if (selected)
		LampImage = "Images\\Comp\\Lamp_HI.jpg";	//use image of highlighted resistor
	else
		LampImage = "Images\\Comp\\Lamp.jpg";	//use image of the normal resistor

	cout << r_GfxInfo.PointsList[0].y << endl;

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(LampImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	PrintMsgX("Lamp : " + my_label, xc, yc - COMP_HEIGHT * 2 / 3);

}

void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, string my_label, bool selected) const
{
	string SwitchImage;
	if (selected)
		SwitchImage = "Images\\Comp\\Switch_HI.jpg";	//use image of highlighted resistor
	else
		SwitchImage = "Images\\Comp\\Switch.jpg";	//use image of the normal resistor


	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(SwitchImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	PrintMsgX("Switch : " + my_label, xc, yc - COMP_HEIGHT * 2 / 3);

}


void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, string my_label, bool selected) const
{
	string BatteryImage;
	if (selected)
		BatteryImage = "Images\\Comp\\Battery_HI.jpg";	//use image of highlighted resistor
	else
		BatteryImage = "Images\\Comp\\Battery.jpg";	//use image of the normal resistor

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(BatteryImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	PrintMsgX("Battery : " + my_label, xc, yc - COMP_HEIGHT * 2 / 3);

}


void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, string my_label, bool selected) const
{
	string BuzzerImage;
	if (selected)
		BuzzerImage = "Images\\Comp\\Buzzer_HI.jpg";	//use image of highlighted resistor
	else
		BuzzerImage = "Images\\Comp\\Buzzer.jpg";	//use image of the normal resistor

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(BuzzerImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	PrintMsgX("Buzzer : " + my_label, xc, yc - COMP_HEIGHT * 2 / 3);

}



void UI::DrawFuse(const GraphicsInfo& r_GfxInfo, string my_label, bool selected) const
{
	string FuseImage;
	if (selected)
		FuseImage = "Images\\Comp\\Lamp_HI.jpg";	//use image of highlighted resistor
	else
		FuseImage = "Images\\Comp\\Lamp.jpg";	//use image of the normal resistor


	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(FuseImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	PrintMsgX("Fuse : " + my_label, xc, yc - COMP_HEIGHT * 2 / 3);

}


void UI::DrawGround(const GraphicsInfo& r_GfxInfo, string my_label, bool selected) const
{
	string GroundImage;
	if (selected)
		GroundImage = "Images\\Comp\\Lamp_HI.jpg";	//use image of highlighted resistor
	else
		GroundImage = "Images\\Comp\\Lamp.jpg";	//use image of the normal resistor


	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(GroundImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	PrintMsgX("Ground : " + my_label, xc, yc - COMP_HEIGHT * 2 / 3);

}



void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	pWind->SetPen(BLACK, 4);


	int x1 = r_GfxInfo.PointsList[0].x,
		y1 = r_GfxInfo.PointsList[0].y,
		x2 = r_GfxInfo.PointsList[1].x,
		y2 = r_GfxInfo.PointsList[1].y,
		mid = x1 + (x2 - x1) / 2;


	pWind->DrawLine(x1,y1,mid,y1);
	pWind->DrawLine(mid,y1,mid,y2);
	pWind->DrawLine(mid,y2,x2,y2);
	
}




void UI::DrawSpam(const GraphicsInfo& r_GfxInfo) const
{
	string LampImage = "Images\\Comp\\Lamp.jpg";	//use image of the normal resistor

	cout << r_GfxInfo.PointsList[0].y << endl;

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(LampImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	

}











UI::~UI()
{
	delete pWind;
}