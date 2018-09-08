#include "SuperPerson.h"

SuperPerson::SuperPerson(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir ):Person(myScreenBufferSize,myLoc, spd, dir)
{
}
SuperPerson::~SuperPerson(void){
}
bool SuperPerson::draw(std::vector<std::string> &myScreenVector){
//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
//
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
		myScreenVector[myLoc.y+7  ].replace(myLoc.x,PERSON_WIDTH,"      S      ");	
		myScreenVector[myLoc.y+8  ].replace(myLoc.x,PERSON_WIDTH,"     /|      ");
		myScreenVector[myLoc.y+9  ].replace(myLoc.x,PERSON_WIDTH,"   \\/_|     ");

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
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"      S      ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"      |\\    ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"      |_\\/  ");
		if(bLegChangePosition){
			myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"      |     ");
			myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"      ||/    ");
		}
		break;
	case UP:
		if(myLoc.y-spd>0)
			myLoc.y=myLoc.y-spd;
		myScreenVector[myLoc.y ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\\\|///// ");
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\|\\ /|//  ");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\|O O|/  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    | ^ |    ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH," \\  | - |  /");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"  o |___| o  ");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"   \\__|__/  ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"      S      ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"      |      ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"     _|_     ");
		break;
	case NO_DIR:
		if(myLoc.y+spd<DEFAULT_HEIGHT-9)
			myLoc.y=myLoc.y+spd;
		myScreenVector[myLoc.y ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\\\|///// ");
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\|~ ~|//");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\|O O|/  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    | ^ |    ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH,"    | v |    ");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"    |___|    ");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"    __|__    ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"    \\ S /   ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"     0|0     ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"     _|_     ");
		break;
	case NO_DIR_AGGRESSIVE:
		myScreenVector[myLoc.y ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\\\|///// ");
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\|\\ /|//  ");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\|O O|/  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    | ^ |    ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH," \\  | - |  /");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"  o |___| o  ");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"   \\__|__/  ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"      S      ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"      |      ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"     _|_     ");
		break;
	case NO_DIR_PASSIVE:
		myScreenVector[myLoc.y ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\\\|///// ");
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\|~ ~|//");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\|O O|/  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    | ^ |    ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH,"    | v |    ");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"    |___|    ");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"    __|__    ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"    \\ S /   ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"     0|0     ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"     _|_     ");
		break;
	default:
	
		myScreenVector[myLoc.y ].replace(myLoc.x,PERSON_WIDTH," \\\\\\\\\\|///// ");
		myScreenVector[myLoc.y+1 ].replace(myLoc.x,PERSON_WIDTH,"  \\\\|~ ~|//");
		myScreenVector[myLoc.y+2 ].replace(myLoc.x,PERSON_WIDTH,"   \\|O O|/  ");
		myScreenVector[myLoc.y+3 ].replace(myLoc.x,PERSON_WIDTH,"    | ^ |    ");
		myScreenVector[myLoc.y+4 ].replace(myLoc.x,PERSON_WIDTH,"    | v |    ");
		myScreenVector[myLoc.y+5 ].replace(myLoc.x,PERSON_WIDTH,"    |___|    ");
		myScreenVector[myLoc.y+6 ].replace(myLoc.x,PERSON_WIDTH,"    __|__    ");
		myScreenVector[myLoc.y+7 ].replace(myLoc.x,PERSON_WIDTH,"    \\ S /   ");
		myScreenVector[myLoc.y+8 ].replace(myLoc.x,PERSON_WIDTH,"     0|0     ");
		myScreenVector[myLoc.y+9 ].replace(myLoc.x,PERSON_WIDTH,"     _|_     ");
		break;

	}
	
	return false;
}