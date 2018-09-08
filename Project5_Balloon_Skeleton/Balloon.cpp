#include "Balloon.h"
//Balloon myballoon; 
//Every time a balloon is created to the left of an existing balloon the ballons all shift towards the left
//nothing can halt their inexorable advance
//they travel leftward, weary souls with nowhere right to call home
Balloon::Balloon(sizeofScreenBuffer myScreenBufferSize,location myLoc,int iHowLongBeforeFall, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc,spd, dir)
{
	this->myScreenBufferSize=myScreenBufferSize;
	this->myLoc=myLoc;
	this->iHowLongBeforeFall=iHowLongBeforeFall;
	this->spd=spd;
	this->dir=dir;
}


Balloon::~Balloon(void)
{
}

//returns true if it's time to delete this balloon
bool Balloon::draw(std::vector<std::string> &myScreenVector){			
	//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;
	iHowLongBeforeFall--;//decrement time until balloon falls
	if(iHowLongBeforeFall<=0){
		if(myLoc.y+spd<(DEFAULT_HEIGHT-6)){
			myLoc.y=myLoc.y+spd;
		}
		else{
			bDeleteMe=true;
		}
	}
	switch(col){
		case COSMO_POPPED: 
			myScreenVector[myLoc.y    ].replace(myLoc.x,BALLOON_WIDTH,"       ");
			myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH,"    |  ");
			myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH,"  \\   /");
			myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH," - pop-");
			myScreenVector[myLoc.y+4  ].replace(myLoc.x,BALLOON_WIDTH,"  /   \\");
			myScreenVector[myLoc.y+5  ].replace(myLoc.x,BALLOON_WIDTH,"    |  ");
			myScreenVector[myLoc.y+6  ].replace(myLoc.x,BALLOON_WIDTH,"       ");
			bDeleteMe = true;
			break;
		case BALLOON_CLOBBERED:
			myScreenVector[myLoc.y   ].replace(myLoc.x,BALLOON_WIDTH,"   *   ");
			myScreenVector[myLoc.y+1 ].replace(myLoc.x,BALLOON_WIDTH," *   * ");
			myScreenVector[myLoc.y+2 ].replace(myLoc.x,BALLOON_WIDTH,"* * * *");
			myScreenVector[myLoc.y+3 ].replace(myLoc.x,BALLOON_WIDTH,"*BOOM *");
			myScreenVector[myLoc.y+4 ].replace(myLoc.x,BALLOON_WIDTH,"* * * *");
			myScreenVector[myLoc.y+5 ].replace(myLoc.x,BALLOON_WIDTH," *   * ");
			myScreenVector[myLoc.y+6 ].replace(myLoc.x,BALLOON_WIDTH,"   *   ");
			bDeleteMe=true;
			break;
		case NO: 
			myScreenVector[myLoc.y	  ].replace(myLoc.x,BALLOON_WIDTH,"  ___  ");
			myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH," //\\ \\");
			myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH,"| \\/  |");
			myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH," \\   /");
			myScreenVector[myLoc.y+4  ].replace(myLoc.x,BALLOON_WIDTH,"  \\ / ");
			myScreenVector[myLoc.y+5  ].replace(myLoc.x,BALLOON_WIDTH,"   |   ");
			myScreenVector[myLoc.y+6  ].replace(myLoc.x,BALLOON_WIDTH,"   |   ");
	}
	/*

		
		"   *   ");
		" *   * ");
		"* * * *");
		"*BOOM *");
		"* * * *");
		" *   * ");
		"   *   ");
		
		

		
		"  ___  ");
		" //\\ \\ ");
		"| \\/  |");
		" \\   / ");
		"  \\ /  ");
		"   |   ");
		"   |   ");
		
	}*/

	return bDeleteMe;
}