#include "Action.h"
#include "..\ApplicationManager.h"


bool Action::isConflict(int xx, int yy, int ww, int hh) const
{
	Component** ListOfComp = pManager->getCompList();
	int CompCount = pManager->getCompCount();

	UI* pUI = pManager->GetUI();

	if (yy > 600 - hh / 2 || yy < 80 + hh) return true;
 


	for (int i = 0; i < CompCount; i++) {
		if (
			(xx >= ListOfComp[i]->getC()->PointsList[0].x - ww / 2 &&
				yy >= ListOfComp[i]->getC()->PointsList[0].y - hh &&
				xx <= ListOfComp[i]->getC()->PointsList[1].x + ww / 2 &&
				yy <= ListOfComp[i]->getC()->PointsList[1].y + hh)
			)	return true;

		
		

	}
	return false;
}



