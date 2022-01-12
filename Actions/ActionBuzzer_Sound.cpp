#include "ActionBuzzer_Sound.h"
#include "..\ApplicationManager.h"



ActionBuzzer_Sound::ActionBuzzer_Sound(ApplicationManager* pApp) :Action(pApp)
{
	this->pApp = pApp;
}

ActionBuzzer_Sound::~ActionBuzzer_Sound(void)
{
}





void ActionBuzzer_Sound::Execute()
{
	//This is the code of the sound but out of no where it created an error
	//PlaySound(TEXT("Buzzer_Sound.wav"), NULL, SND_FILENAME | SND_ASYNC);

	int test = 0;
	cin >> test;

										
			
}

void ActionBuzzer_Sound::Undo()
{}

void ActionBuzzer_Sound::Redo()
{}

