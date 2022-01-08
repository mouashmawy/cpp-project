#include <iostream>
#include "UI.h"
#include <string>
#include<windows.h>
#include <cmath>
#include <cstdio>
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


void UI::GetPointClicked2(int& x, int& y)
{
	pWind->DontWaitMouseClick(x, y);	//Wait for mouse click

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
		Sleep(100);
	}
	/*
	x = round(x / 50) * 50;
	y = round(y / 50) * 50;
	*/

}


void UI::GetPreviousClick(int& x, int& y) {

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
			case ITM_MOD4: return ADD_MODULE;
			case ITM_SIMULATE: return SIMULATE;
			
			case ITM_EXIT:	return EXIT;	
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		
		}
		else if (y > ToolBarHeight && y > StatusBarHeight && x > width - ToolItemWidth - 7 && x < width)
		{
			int ClickedItemOrder = ((y-ToolBarHeight-2) / EditItemHeight);
			switch (ClickedItemOrder)
			{
			case ITM_EDIT_L:	return EDIT_L;
			case ITM_EDIT_V: return EDIT_V;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_DEL: return DEL;
			case ITM_MULTIDEL: return MULTIDEL;

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
UI::Basic UI::gB() 
{
	Basic n;
	return n;
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
	pWind->SetFont(16, BOLD | ITALICIZED, BY_NAME, "Arial");
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
	MenuItemImages[ITM_MOD4] = "images\\Menu\\Module4.jpg";
	MenuItemImages[ITM_SIMULATE] = "images\\Menu\\Menu_Simulate.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++) {
		static int j = 0; //because there is ITM_SIMULATE that taked 3 places so having j instead of i is better
		
		if (i == ITM_SIMULATE) { pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth * 3, ToolBarHeight); j += 2; }
		else pWind->DrawImage(MenuItemImages[i], j * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
		j++;
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

	MenuItem[ITM_EDIT_L] = "images\\Edit\\Menu_Edit_L.jpg";
	MenuItem[ITM_EDIT_V] = "images\\Edit\\Menu_Edit_V.jpg";
	MenuItem[ITM_SAVE] = "images\\Edit\\Menu_Save.jpg";
	MenuItem[ITM_LOAD] = "images\\Edit\\Menu_Load.jpg";
	MenuItem[ITM_COPY] = "images\\Edit\\copy.jpg";
	MenuItem[ITM_CUT] = "images\\Edit\\cut.jpg";
	MenuItem[ITM_PASTE] = "images\\Edit\\paste.jpg";
	MenuItem[ITM_UNDO] = "images\\Edit\\undo.jpg";
	MenuItem[ITM_REDO] = "images\\Edit\\redo.jpg";
	MenuItem[ITM_DEL] = "images\\Edit\\Delete.jpg";
	MenuItem[ITM_MULTIDEL] = "images\\Edit\\Multi_Delete.jpg";
	


	pWind->SetPen(RED,1000000);
	pWind->DrawRectangle(widthTD - EditBarWidth , ToolBarHeight, widthTD, height - StatusBarHeight);
	
		//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT2; i++) {
		int x1 = widthTD - EditBarWidth,
			y1 = ToolBarHeight+ EditItemHeight*i;

		pWind->DrawImage(MenuItem[i], x1, y1, EditBarWidth,EditItemHeight);

		pWind->SetPen(RED, 2);
		pWind->DrawLine(x1,y1,x1,height-StatusBarHeight);
		
	}

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

void UI::DrawResistor(const GraphicsInfo& r_GfxInfo, string my_label,double val, bool selected) const
{	

	string ResImage;
	string valS = to_string(val);

	if (selected)
		ResImage = "Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor


	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;
	
	if(my_label.length()>5)	my_label.resize(5);
	if (valS.length() > 5)	valS.resize(6);
	
	pWind->DrawImage(ResImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	string toPrint = my_label + " : " + valS;
	PrintMsgX(toPrint, xc, yc - COMP_HEIGHT * 2 / 3);
		

}

//TODO: Add similar functions to draw all other components

void UI::DrawLamp(const GraphicsInfo& r_GfxInfo, string my_label,double val,bool Lighted, bool selected) const

{
	string LampImage;
	string valS = to_string(val);

	if (selected && Lighted)
		LampImage = "Images\\Comp\\LampL_HI.jpg";	//use image of highlighted resistor
	else if(Lighted)
		LampImage = "Images\\Comp\\LampL.jpg";	//use image of the normal resistor
	else if (selected)
		LampImage = "Images\\Comp\\Lamp_HI.jpg";
	else
		LampImage = "Images\\Comp\\Lamp.jpg";


	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(LampImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	string toPrint = my_label + " : " + valS;
	PrintMsgX(toPrint, xc, yc - COMP_HEIGHT * 2 / 3);

}

void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, string my_label,double val, bool Closed, bool selected) const
{

	

	string SwitchImage;
	string valS = to_string(val);

	if (selected && Closed)
		SwitchImage = "Images\\Comp\\SwitchC_HI.jpg";	//use image of highlighted resistor
	else if(Closed)
		SwitchImage = "Images\\Comp\\SwitchC.jpg";	//use image of the normal resistor
	else if (selected)
		SwitchImage = "Images\\Comp\\Switch_HI.jpg";
	else
		SwitchImage = "Images\\Comp\\Switch.jpg";

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(SwitchImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	string toPrint = my_label + " : " + valS;
	PrintMsgX(toPrint, xc, yc - COMP_HEIGHT * 2 / 3);
}


void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, string my_label,double val, bool selected) const
{
	string BatteryImage;
	string valS = to_string(val);

	if (selected)
		BatteryImage = "Images\\Comp\\Battery_HI.jpg";	//use image of highlighted resistor
	else
		BatteryImage = "Images\\Comp\\Battery.jpg";	//use image of the normal resistor

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(BatteryImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	string toPrint = my_label + " : " + valS;
	PrintMsgX(toPrint, xc, yc - COMP_HEIGHT * 2 / 3);

}


void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, string my_label,double val, bool selected) const
{
	string BuzzerImage;
	string valS = to_string(val);

	if (selected)
		BuzzerImage = "Images\\Comp\\Buzzer_HI.jpg";	//use image of highlighted resistor
	else
		BuzzerImage = "Images\\Comp\\Buzzer.jpg";	//use image of the normal resistor

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(BuzzerImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	string toPrint = my_label + " : " + valS;
	PrintMsgX(toPrint, xc, yc - COMP_HEIGHT * 2 / 3);

}



void UI::DrawFuse(const GraphicsInfo& r_GfxInfo, string my_label,double val, bool selected) const
{
	string FuseImage;
	string valS = to_string(val);

	if (selected)
		FuseImage = "Images\\Comp\\Fuse_HI.jpg";	//use image of highlighted resistor
	else
		FuseImage = "Images\\Comp\\Fuse.jpg";	//use image of the normal resistor


	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(FuseImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	string toPrint = my_label + " : " + valS;
	PrintMsgX(toPrint, xc, yc - COMP_HEIGHT * 2 / 3);

}


void UI::DrawGround(const GraphicsInfo& r_GfxInfo, string my_label,double val, bool selected) const
{
	string GroundImage;
	string valS = to_string(val);

	if (selected)
		GroundImage = "Images\\Comp\\Gound_HI.jpg";	//use image of highlighted resistor
	else
		GroundImage = "Images\\Comp\\Ground.jpg";	//use image of the normal resistor


	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(GroundImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	string toPrint = my_label + " : " + valS;
	PrintMsgX(toPrint, xc, yc - COMP_HEIGHT * 2 / 3);

}


void UI::DrawModule(const GraphicsInfo& r_GfxInfo, string my_label, double val, bool selected) const
{
	string GroundImage;
	string valS = to_string(val);

	if (selected)
		GroundImage = "Images\\Comp\\Module.jpg";	//use image of highlighted resistor
	else
		GroundImage = "Images\\Comp\\Module_HI.jpg";	//use image of the normal resistor


	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(GroundImage, xc, yc, COMP_WIDTH, COMP_HEIGHT);
	string toPrint = my_label + " : " + valS;
	PrintMsgX(toPrint, xc, yc - COMP_HEIGHT * 2 / 3);

}



void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, string text, bool selected) const
{
	pWind->SetPen(BLACK, 3);


	int x1 = r_GfxInfo.PointsList[0].x,
		y1 = r_GfxInfo.PointsList[0].y,
		x2 = r_GfxInfo.PointsList[1].x,
		y2 = r_GfxInfo.PointsList[1].y,
		midX = x1 + (x2 - x1) / 2;


	if ((lr1 == 0 && lr2 == 1 && x1 > x2) || (lr1 == 1 && lr2 == 0 && x2 > x1))
	//1
	{
		pWind->DrawLine(x1, y1, midX, y1);
		pWind->DrawLine(midX, y1, midX, y2);
		pWind->DrawLine(midX, y2, x2, y2);
		//PrintMsgX("Conn:" + text, x1, y2);
		cout << "conn1" << endl;
	}
	//2
	else if(lr1 == 0 && lr2 == 0 && x1 > x2)
	{
		pWind->DrawLine(x1, y1, x2-10, y1);
		pWind->DrawLine(x2-10, y1, x2 - 10, y2);
		pWind->DrawLine(x2-10, y2, x2 , y2);
		cout << "conn2" << endl;
	}
	//3
	else if (lr1 == 0 && lr2 == 0 && x2 > x1)
	{
		pWind->DrawLine(x1, y1, x1 - 10, y1);
		pWind->DrawLine(x1-10 , y1, x1 - 10, y2);
		pWind->DrawLine(x1 - 10, y2, x2, y2);
		cout << "conn3" << endl;
	}
	
	//4
	else if (lr1 == 1 && lr2 == 1 && x1 < x2)
	{
		pWind->DrawLine(x1, y1, x2 + 10, y1);
		pWind->DrawLine(x2 + 10, y1, x2 + 10, y2);
		pWind->DrawLine(x2 + 10, y2, x2, y2);
		cout << "conn4" << endl;
	}
	//5
	else if (lr1 == 1 && lr2 == 1 && x2 < x1)
	{
		pWind->DrawLine(x1, y1, x1 + 10, y1);
		pWind->DrawLine(x1 + 10, y1, x1 + 10, y2);
		pWind->DrawLine(x1 + 10, y2, x2, y2);
		cout << "conn5" << endl;
	}
	
	
}


void UI::setLRforconnect(int LR1 , int LR2 )
{
	lr1 = (LR1) ? RIGHT:LEFT;
	lr2 = (LR2) ? RIGHT : LEFT;
}



string UI::SwitchImage(int type) const
{
	string Image;
	switch (type)
	{
	case (ITM_RES):
		Image = "Images\\Comp\\Resistor.jpg";
		break;

	case (ITM_BATTERY):
		Image = "Images\\Comp\\Battery.jpg";
		break;

	case (ITM_BUZZER):
		Image = "Images\\Comp\\Buzzer.jpg";
		break;

	case (ITM_LAMP):
		Image = "Images\\Comp\\Lamp.jpg";
		break;

	case (ITM_FUSE):
		Image = "Images\\Comp\\Fuse.jpg";
		break;

	case (ITM_GROUND):
		Image = "Images\\Comp\\Ground.jpg";
		break;

	case (ITM_SWITCH):
		Image = "Images\\Comp\\Switch.jpg";
		break;

	default:
		Image = "Images\\Comp\\Resistor.jpg";
		break;
	}
	return Image;
}



void UI::DrawSpam(const GraphicsInfo& r_GfxInfo, int type) const
{
	string Image = SwitchImage(type);
	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;
	pWind->DrawImage(Image, xc, yc, COMP_WIDTH, COMP_HEIGHT);
}



void UI::DrawTemp(const GraphicsInfo& r_GfxInfo, int type) const
{
	string Image = SwitchImage(type);

	int xc = r_GfxInfo.PointsList[0].x;
	int yc = r_GfxInfo.PointsList[0].y;


	pWind->DrawImage(Image, xc, yc, COMP_WIDTH, COMP_HEIGHT);


}




UI::~UI()
{
	delete pWind;
}


////////////////////////////////////////////////////////////////////////////////////////////
//                                 Deleting Comps                                         //
////////////////////////////////////////////////////////////////////////////////////////////
