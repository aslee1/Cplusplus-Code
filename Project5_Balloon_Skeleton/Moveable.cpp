#include "Moveable.h"


Moveable::Moveable(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir ):myScreenBufferSize(myScreenBufferSize),myLoc(myLoc),spd(spd),dir(dir),iTimeBetweenMovements(spd),col(NO)
{
}

void Moveable::setDirection(DIRECTION dir){
	this->dir = dir;
}
void Moveable::setSpeed(SPEED spd){
	this->spd = spd;
}
Moveable::~Moveable(void){

}

//void Moveable::updateLocation(){
//	if (dir == DOWN)
//		myLoc.y =myLoc.y-1;
//}



