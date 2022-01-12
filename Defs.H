#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_RESISTOR,		//Add a resistor
	ADD_SWITCH,			//Add Switch
	ADD_LAMP,			//Add LAMP
	ADD_BATTERY,
	ADD_BUZZER,
	ADD_FUSE,
	ADD_GROUND,
	ADD_MODULE,
	ADD_CONNECTION,		//Add Wire Connection
	SIMULATE,


	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_L,			//Edit Label of a Component, a Connection

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	EDIT_V,
	DEL,		//Delete a Component, a Connection
	MULTIDEL,
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	COPY,
	CUT,
	PASTE,


	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	FROM_DES_MODE,
	MOD_DES_MODE,
	SAVE_MODULE,
	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar



	

};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION,
	MODULE_DESIGN
};

//Maximum number of connections that can be connected to any output components
#define MAX_CONNS 20




#endif