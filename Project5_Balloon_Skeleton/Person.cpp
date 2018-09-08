#include "Person.h"


Person::Person(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir,DIRECTION lastDir ):Moveable(myScreenBufferSize,myLoc, spd, dir),bLegChangePosition(false)
{
	this->myScreenBufferSize=myScreenBufferSize;
	this->myLoc=myLoc;
	this->spd=spd;
	this->dir=dir;
	this->lastDir=lastDir;
}


Person::~Person(void)
{
}

//always return false since person never deleted
bool Person::draw(std::vector<std::string> &myScreenVector){			
//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
//
	if(dir!=NO_DIR_AGGRESSIVE&&dir!=NO_DIR_PASSIVE)
		lastDir=dir;
	if(dir==NO_DIR_AGGRESSIVE||dir==NO_DIR_PASSIVE)
		dir=lastDir;
	bLegChangePosition = !bLegChangePosition;
	switch(dir){
	case LEFT:
		if(myLoc.x-spd>0)
			myLoc.x=myLoc.x-spd;
		myScreenVector[myLoc.y  ].replace(myLoc.x,PERSON_WIDTH,"   \\\\\\\\|//// ");//17
		myScreenVector[myLoc.y+1  ].replace(myLoc.x,PERSON_WIDTH,"    |~ ////  ");
		myScreenVector[myLoc.y+2  ].replace(myLoc.x,PERSON_WIDTH,"    |O  //   ");
		myScreenVector[myLoc.y+3  ].replace(myLoc.x,PERSON_WIDTH,"   <    |    ");
		myScreenVector[myLoc.y+4  ].replace(myLoc.x,PERSON_WIDTH,"    |_/ |    ");
		myScreenVector[myLoc.y+5  ].replace(myLoc.x,PERSON_WIDTH,"--o |__/     ");
		myScreenVector[myLoc.y+6  ].replace(myLoc.x,PERSON_WIDTH,"   \\__|     ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"      |      ");	
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"     /|      ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"   \\/_|     ");

		if(bLegChangePosition){
			myScreenVector[myLoc.y+8  ].replace(myLoc.x,PERSON_WIDTH,"      |      ");
			myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"    \\||     ");
		}
		break;
	case RIGHT:
		if(myLoc.x+spd<66)
			myLoc.x=myLoc.x+spd;
		myScreenVector[myLoc.y   ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\|////   ");//17
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\\\\\ ~|");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\\\  O|  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    |    >   ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH,"    | \\_|   ");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"     \\__| o--");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"      |__/   ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"      |      ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"      |\\    ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"      |_\\/  ");
		if(bLegChangePosition){
			myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"      |     ");
			myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"      ||/    ");
		}
		break;
	case UP:
		myScreenVector[myLoc.y ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\\\|///// ");
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\|\\ /|//  ");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\|O O|/  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    | ^ |    ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH," \\  | - |  /");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"  o |___| o  ");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"   \\__|__/  ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"      |      ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"      |      ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"     _|_     ");
		break;
	case DOWN:
		myScreenVector[myLoc.y  ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\\\|///// ");
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\|~ ~|//");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\|O O|/  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    | ^ |    ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH,"    | v |    ");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"    |___|    ");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"    __|__    ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"    \\ | /   ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"     0|0     ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"     _|_     ");
		break;
	//case NO_DIR_AGGRESSIVE:
	//	dir=lastDir;
	//	break;
	//case NO_DIR_PASSIVE:
	//	dir=lastDir;
	//	break;
	default:
		myScreenVector[myLoc.y ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\\\|///// ");
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\|~ ~|//");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\|O O|/  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    | ^ |    ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH,"    | v |    ");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"    |___|    ");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"    __|__    ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"    \\ | /   ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"     0|0     ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"     _|_     ");
		break;
	}

	return false;
}
