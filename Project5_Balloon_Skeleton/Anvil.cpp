#include "Anvil.h"
Anvil::Anvil(sizeofScreenBuffer myScreenBufferSize,int iHowLongBeforeFall, location myLoc, SPEED spd, DIRECTION dir):Moveable(myScreenBufferSize,myLoc,spd, dir)
{
	this->myScreenBufferSize=myScreenBufferSize;
	this->myLoc=myLoc;
	this->iHowLongBeforeFall=iHowLongBeforeFall;
	this->spd=spd;
	this->dir=dir;
}


Anvil::~Anvil(void)
{
}
//int Anvil::DecrementHowLongBeforeFall(int howlong){
//	return howlong--;
//}
bool Anvil::draw(std::vector<std::string> &myScreenVector){
	iHowLongBeforeFall--;
	if(iHowLongBeforeFall<=0){
		if(myLoc.y+spd<(DEFAULT_HEIGHT-3)){
			myLoc.y=myLoc.y+spd;
			
		}
		else{
			return true; //anvil has fallen off screen
		}
	}
	if(col==ANVIL_HIT){
		return true;
	}
	myScreenVector[myLoc.y    ].replace(myLoc.x,BALLOON_WIDTH,"_______");
	myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH,"|     |");
	myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH," )   ( ");
	myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH,"|_____|");
	return false;
}
