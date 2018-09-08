#pragma once
#include "Balloon.h"

class TerribleBalloon :
	public Balloon 
{
	public:
	TerribleBalloon(sizeofScreenBuffer myScreenBufferSize,location myLoc, int iHowLongBeforeFall, SPEED spd=NO_SPD,  DIRECTION dir=DOWN,int timeToFly=80, bool BeaBee=true);
	virtual ~TerribleBalloon(void);

	//returns true if its time to delete
	virtual bool draw(std::vector<std::string> &myScreenVector);	
	bool getBeaBee();
private:
	//waits around a while before it falls 
	int iHowLongBeforeFall;
	int timeToFly; //how long the bee will fly
	bool beaBee;
};