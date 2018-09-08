#pragma once
#include "moveable.h"
class Person :
	public Moveable
{
public:
	Person(sizeofScreenBuffer myScreenBufferSize,location myLoc,SPEED spd=NO_SPD, DIRECTION dir=NO_DIR, DIRECTION lastDir=NO_DIR );
	~Person(void);

	//returns true always
	virtual bool draw(std::vector<std::string> &myScreenVector);	

private:
	//determines if leg is out or in
	bool bLegChangePosition;
	DIRECTION lastDir;
};

