#pragma once;
#include "moveable.h"

class Anvil : 
	public Moveable
{
public:
	Anvil(sizeofScreenBuffer myScreenBufferSize,int iHowLongBeforeFall, location myLoc, SPEED spd=FAST, DIRECTION dir=DOWN);
	virtual ~Anvil(void);
	//returns true if its time to delete
	//int DecrementHowLongBeforeFall(int howlong);
	virtual bool draw(std::vector<std::string> &myScreenVector);
	
private:
	//waits around a while before it falls 
	int iHowLongBeforeFall;
};
