#include <iostream>
#include "UI.h"
#include <string>
#include<windows.h>
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
	CreateStatusBar();		//Create Status bar
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
			case ITM_EXIT:	return EXIT;	
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
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
	pWind->SetPen(MsgColor);
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
	MenuItemImages[ITM_CONN] = "images\\Menu\\Menu_Conn.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
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

void UI::DrawResistor(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string ResImage;
	if (selected)
		ResImage = "Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	//5555555555555555555555555555555555555555555555555 check the commented code

	static int num=0;

	cout << r_GfxInfo.PointsList[0].y << endl;

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;

	


		pWind->DrawImage(ResImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
		PrintMsgX("Resistor "/* + to_string(++num)*/, xc, yc - COMP_HEIGHT * 2 / 3);
		cout << "fuck!!!!!!!!!!!!" << endl; return;



	/*

	if (
		yc >= 80 + COMP_HEIGHT / 2 &&
		yc < 650 - 50 - COMP_HEIGHT / 2 

		)

	{
		pWind->DrawImage(ResImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
		PrintMsgX("Resistor ", xc, yc - COMP_HEIGHT * 2 / 3);

	}
	else { cout << "55555555555555555555555" << endl; return; }
		*/

		/*else {
			string msggg = "Can't place here. Try Again!!!!!!!!";
			PrintMsg(msggg);// for (int i = 0; i < 5; i++) {Sleep(100); ClearStatusBar(); Sleep(50); PrintMsg(msggg);}
			cout << r_GfxInfo.PointsList[0].y << "555555555555555555555" << endl;
			Sleep(1000); ClearStatusBar();
			return;
		}*/
}
//TODO: Add similar functions to draw all other components

void UI::DrawLamp(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string LampImage;
	if (selected)
		LampImage = "Images\\Comp\\Lamp_HI.jpg";	//use image of highlighted resistor
	else
		LampImage = "Images\\Comp\\Lamp.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(LampImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string SwitchImage;
	if (selected)
		SwitchImage = "Images\\Comp\\Switch_HI.jpg";	//use image of highlighted resistor
	else
		SwitchImage = "Images\\Comp\\Switch.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(SwitchImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}


void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BatteryImage;
	if (selected)
		BatteryImage = "Images\\Comp\\Battery_HI.jpg";	//use image of highlighted resistor
	else
		BatteryImage = "Images\\Comp\\Battery.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(BatteryImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}


void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string SwitchImage;
	if (selected)
		SwitchImage = "Images\\Comp\\Buzzer_HI.jpg";	//use image of highlighted resistor
	else
		SwitchImage = "Images\\Comp\\Buzzer.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(SwitchImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}



void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	pWind->SetPen(BLACK, 5);
	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	//pWind->DrawLine(100, 100, 500, 500);
	
}


UI::~UI()
{
	delete pWind;
}