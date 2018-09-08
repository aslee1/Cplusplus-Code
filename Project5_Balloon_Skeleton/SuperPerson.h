#pragma once
#include "Person.h"
class SuperPerson: 
	public Person
{
public:
	SuperPerson::SuperPerson(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir=NO_DIR);
	~SuperPerson(void);
	bool SuperPerson::draw(std::vector<std::string> &myScreenVector);
private:
	//determines if leg is out or in
	bool bLegChangePosition;
};