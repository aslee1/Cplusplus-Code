#include "TerribleBalloon.h"

//I had to use a constant in the x-boundary checker because it had to be the exact size of my screen or else weird things would
//happen. This might break the code if your screen isn't the same size. Many appologies.
TerribleBalloon::TerribleBalloon(sizeofScreenBuffer myScreenBufferSize,location myLoc,int iHowLongBeforeFall, SPEED spd,  DIRECTION dir, int timeToFly, bool BeaBee):Balloon(myScreenBufferSize,myLoc, iHowLongBeforeFall, spd, dir)
{
	this->myScreenBufferSize=myScreenBufferSize;
	this->myLoc=myLoc;
	this->iHowLongBeforeFall=iHowLongBeforeFall;
	this->spd=spd;
	this->dir=dir;
	this->timeToFly=timeToFly;
	this->beaBee=BeaBee;
}
bool TerribleBalloon::getBeaBee(void){
	return beaBee;
}

TerribleBalloon::~TerribleBalloon(void)
{
}

//returns true if its time to delete this balloon
bool TerribleBalloon::draw(std::vector<std::string> &myScreenVector){			
	//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;
	iHowLongBeforeFall--;
	int movex=rand()%4;
	int movey=rand()%4;
	int neg=rand()%4;

	switch(col){
		case COSMO_POPPED:
		case BALLOON_CLOBBERED:
			beaBee=false;
			timeToFly--;
			if(neg==1){
				movex=-movex;
			}
			if(neg==2){
				movey=-movey;
			}
			if(neg==3){
				movex=-movex;
				movey=-movey;
			}
			if((myLoc.y+movey)>0&&(myLoc.y+movey)<(DEFAULT_HEIGHT-4)&&(myLoc.x+movex)>0&&(myLoc.x+movex)<(70)){//sorry for constant but had to be exact size of screen. This may break the code.
				myLoc.y=myLoc.y+movey;
				myLoc.x=myLoc.x+movex;
			}
			else{
				if((myLoc.y-movey)>0&&(myLoc.y-movey)<(DEFAULT_HEIGHT-4)&&(myLoc.x-movex)>0&&(myLoc.x-movex)<(70)){
					myLoc.y=myLoc.y-movey;
					myLoc.x=myLoc.x-movex;
				}
			}
			if(timeToFly<=0){
				bDeleteMe=true;

			}
			//if((myLoc.y+movey)>0&&(myLoc.y+movey)<(DEFAULT_HEIGHT-4)&&(myLoc.x+movex)>0&&(myLoc.x+movex)<(66)){//width of screen, this worked for Cosmo
				myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH,"  _  _ ");
				myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH," {_}{_}");
				myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH,"-(_||_)");
				myScreenVector[myLoc.y+4  ].replace(myLoc.x,BALLOON_WIDTH," / \\ \\ ");
			//}
			//bDeleteMe = true;
			break;
	/*
	LEFT:
//Old version with flapping but uglier bee
" ()) "     //flapping
" ()  "     //not flapping
"%000-"
"     "
RIGHT:
"  (()"
"  (()"
"-000%"
"     "
UP:
"  %  "
" =0= "
"  |  "
DOWN:
"  |  "
" =0= "
"  %  "
	case BALLOON_CLOBBERED:
			beaBee=false;
			timeToFly--;
			if(neg==1){
				movex=-movex;
			}
			if(neg==2){
				movey=-movey;
			}
			if(neg==3){
				movex=-movex;
				movey=-movey;
			}
			if((myLoc.y+movey)>0&&(myLoc.y+movey)<(DEFAULT_HEIGHT-4)&&(myLoc.x+movex)>0&&(myLoc.x+movex)<(66)){
				myLoc.y=myLoc.y+movey;
				myLoc.x=myLoc.x+movex;
			}
			if(timeToFly<=0){
				bDeleteMe=true;
			}
				myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH,"  _  _ ");
				myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH," {_}{_}");
				myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH,"-(_||_)");
				myScreenVector[myLoc.y+4  ].replace(myLoc.x,BALLOON_WIDTH," / \\ \\ ");

				//bDeleteMe=true;
			break;*/
		case NO:
			if(iHowLongBeforeFall<=0){
				if(myLoc.y+spd<(DEFAULT_HEIGHT-6)){
					myLoc.y=myLoc.y+spd;
				}
				else{
					bDeleteMe=true;
				}
			}
			myScreenVector[myLoc.y	  ].replace(myLoc.x,BALLOON_WIDTH,"  ___  ");
			myScreenVector[myLoc.y+1  ].replace(myLoc.x,BALLOON_WIDTH," //\\ \\");
			myScreenVector[myLoc.y+2  ].replace(myLoc.x,BALLOON_WIDTH,"| \\/  |");
			myScreenVector[myLoc.y+3  ].replace(myLoc.x,BALLOON_WIDTH," \\   /");
			myScreenVector[myLoc.y+4  ].replace(myLoc.x,BALLOON_WIDTH,"  \\ / ");
			myScreenVector[myLoc.y+5  ].replace(myLoc.x,BALLOON_WIDTH,"   |   ");
			myScreenVector[myLoc.y+6  ].replace(myLoc.x,BALLOON_WIDTH,"   B   ");
	}
	return bDeleteMe;
}