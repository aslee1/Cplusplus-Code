#pragma once
#include <vector>
#include <string>
#include "constants.h"

class Moveable
{
public:
	Moveable(sizeofScreenBuffer myScreenBufferSize, location myLoc, SPEED spd, DIRECTION dir);
	void setDirection(DIRECTION dir);
	void setSpeed(SPEED spd); 

	inline int getX(){return myLoc.x;};
	inline int getY(){return myLoc.y;};
	inline DIRECTION getDir(){return dir;};
	inline void setCollidedState(COLLISION col){this->col = col;};
	inline void setLocation(location myLoc){this->myLoc = myLoc;};

	//returns true if its time to delete
	virtual	bool draw(std::vector<std::string> &myScreenVector)=0;			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES
	virtual ~Moveable(void);
protected:
	location myLoc; 
	sizeofScreenBuffer myScreenBufferSize;
	DIRECTION dir;
	SPEED spd;
	int iTimeBetweenMovements;	
	COLLISION col;
};

