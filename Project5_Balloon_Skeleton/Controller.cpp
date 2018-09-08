#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include "Controller.h"
#include "balloon.h"
#include "ScoreKeeper.h"
#include "Anvil.h"

Controller::Controller(int width, int height, SPEED speed):myScreenBufferSize(width,height),mSpeed(speed),iTimeBetweenBalloonCreation(QUANTUM_WAIT_TIME +2*speed),cosmo(myScreenBufferSize,location(myScreenBufferSize.x/2, myScreenBufferSize.y-PERSON_HEIGHT),speed),myInstructions(myScreenBufferSize,location(myScreenBufferSize.x/2, myScreenBufferSize.y-PERSON_HEIGHT),speed),mControllerState(SHOW_INTRO),superCosmo(myScreenBufferSize,location(myScreenBufferSize.x/2, myScreenBufferSize.y-PERSON_HEIGHT),speed),sCos(false),tBall(false)
{	
	makeCosmoSuper();
	if(sCos)
		superInitialize();
	else
	{
		initialize();
	}
	

	//max distance between center of squares for a collision to have occured
	//corner of one object bounding box touching corner of another
	double distPersonSquare	 = sqrt(PERSON_WIDTH/2*PERSON_WIDTH/2 + PERSON_HEIGHT/2*PERSON_HEIGHT/2);
	double distBalloonSquare = sqrt(BALLOON_WIDTH/2*BALLOON_WIDTH/2 + BALLOON_HEIGHT/2*BALLOON_HEIGHT/2);
	mCollisionDistance		 = distPersonSquare + distBalloonSquare - REQUIRED_OVERLAP;

	/* initialize random seed: */
	srand ((unsigned int)time(NULL));
	
	//let's set up the screen buffer with blanks
	std::string myString;
	myString.resize(width-SPACE_FOR_CRLF,' ');
	for (int i = 0; i < height; i ++) {
		myScreenVector.push_back(myString);
	}
}							 


void Controller::clearScreen(){
	std::string myString;
	myString.resize(myScreenBufferSize.x-SPACE_FOR_CRLF,' ');
	for (int i = 0; i < myScreenBufferSize.y; i ++) {
		myScreenVector[i]=myString;
	}
}

void Controller::initialize(){
	//reset scores
	scorekeeper.resetScores();

	//no balloons
	myBalloons.clear();
	myterribleBalloons.clear();
	myAnvils.clear();
	//reset cosmo
	cosmo.setLocation(location(myScreenBufferSize.x/2, myScreenBufferSize.y-PERSON_HEIGHT));
	cosmo.setDirection(NO_DIR);
	//}
}
void Controller::superInitialize(){
	scorekeeper.resetScores();
	myBalloons.clear();
	myAnvils.clear();
	superCosmo.setLocation(location(myScreenBufferSize.x/2, myScreenBufferSize.y-PERSON_HEIGHT));
	superCosmo.setDirection(NO_DIR);
	
}
void Controller::makeCosmoSuper(bool Cosset){
	sCos=Cosset; 
}
void Controller::makeBalloonsTerrible(bool tesset){
	tBall=tesset;
}
void Controller::draw(){
	clearScreen();

	switch(mControllerState){
	case RESET:
		initialize();
		mControllerState=RUN;
		break;

	case SHOW_INTRO:
		myInstructions.draw(myScreenVector);
		break;
	case RUN:
		//see if it's time
		createBalloon();
		createAnvil();

		//render cosmo to screenbuffer
		if(sCos){
			superCosmo.draw(myScreenVector);
			superCosmo.setDirection(cosmo.getDir());
			
		}
		else{
			cosmo.draw(myScreenVector);
		}
		//render balloons to screenbuffer
		if(tBall){
			std::vector<TerribleBalloon>::iterator myIter = myterribleBalloons.begin();
			while ( myIter != myterribleBalloons.end()){
				//collisions
				COLLISION col;
				//getBeaBee evaluates to false if the item is a bee. There are reasons for this.
				if(myIter->getBeaBee()){
					col= hasCollidedWithCosmo((*myIter));
				}
				else{
					hasCollidedWithBee((*myIter));
				}
				//if(myIter->getBeaBee()==false){
					//col=BALLOON_CLOBBERED;
				//}
				if (myIter->getBeaBee()&&(col==COSMO_POPPED || col==BALLOON_CLOBBERED))
					myIter->setCollidedState(col);		

				if ( myIter->draw(myScreenVector))
					myIter = myterribleBalloons.erase(myIter);
				else
					++myIter;
			}
		}
		else{
			std::vector<Balloon>::iterator myIter = myBalloons.begin();
			while ( myIter != myBalloons.end()){
				//collisions
				COLLISION col = hasCollidedWithCosmo((*myIter));
				if (col==COSMO_POPPED || col==BALLOON_CLOBBERED)
					myIter->setCollidedState(col);		

				if ( myIter->draw(myScreenVector))
					myIter = myBalloons.erase(myIter);
				else
					++myIter;
			}
		}
		if(!myAnvils.empty()){
			std::vector<Anvil>::iterator myAnIt = myAnvils.begin(); 
			COLLISION anv=hasCollidedWithCosmoAnvil((*myAnIt));
			if(anv==ANVIL_HIT){
				myAnIt->setCollidedState(anv); 
				//myAnIt=myAnvils.erase(myAnIt); 
			}
			if(myAnIt-> draw(myScreenVector))
				myAnIt=myAnvils.erase(myAnIt);
		}
		//show score if keeping
		renderScoresToScreenbuffer();
		break;
	}

	//output the screen buffer
	for (int i = 0; i < myScreenBufferSize.y; i ++) {
		std::cout << myScreenVector[i]<<std::endl;
	}
}

void Controller::renderScoresToScreenbuffer(){
	scorekeeper.getDisplayString(myScreenVector[0]);
}
void Controller::createAnvil(){
	
	if(--iTimeBetweenBalloonCreation!=0)
		return;
	iTimeBetweenBalloonCreation = QUANTUM_WAIT_TIME + QUANTUM_WAIT_TIME*(FAST-mSpeed);
	int xCoo = rand()%(myScreenBufferSize.x -(BALLOON_WIDTH+2));
	int yCoo = 1;
	location anvilLoc(xCoo, yCoo);
	Anvil myanvil(myScreenBufferSize, 2, anvilLoc);
	//return myanvil;
	myAnvils.push_back(myanvil);
	//myanvil.draw();
}
void Controller::createBalloon(){
	//BALLOON CREATION RATE based on difficulty
	if (--iTimeBetweenBalloonCreation !=0)
		return;
	iTimeBetweenBalloonCreation = QUANTUM_WAIT_TIME + QUANTUM_WAIT_TIME*(FAST-mSpeed);		//if set to fast last term drops to 0 then balloons are created quickly

	//LOCATION  number between 0 and max balloon size for location
	int ilocx = rand()%(myScreenBufferSize.x -(BALLOON_WIDTH+2));
	int ilocy = rand()%BALLOON_APPEAR_BAND_SIZE;	//anywhere withen first 5 lines
	location myLoc(ilocx, ilocy);

	//How long before it falls
	//(always evaluates to 70 for some reason)
	int iHowLongBeforeFall = MIN_BALLOON_HOVER_TIME + ((FAST-mSpeed)*QUANTUM_WAIT_TIME);//I don't know why this is so complicated

	//SPEED OF FALL
	SPEED iBalloonSpeed = (SPEED)((rand()%mSpeed) +1);	//make sure this falls between SLOW=1 and FAST=4
	if(tBall){
			TerribleBalloon aBalloon(myScreenBufferSize,myLoc,iHowLongBeforeFall,iBalloonSpeed);
			myterribleBalloons.push_back(aBalloon);
	}
	else{
		Balloon aBalloon(myScreenBufferSize,myLoc,iHowLongBeforeFall,iBalloonSpeed);
		myBalloons.push_back(aBalloon);
	}
}
COLLISION Controller::hasCollidedWithCosmoAnvil(Anvil aAnvil){
	//Check to see if Cosmo was hit by an anvil
	int x=0;
	int y=0;
	if(sCos){
		x=superCosmo.getX()-aAnvil.getX();
		y=superCosmo.getY()-aAnvil.getY();
	}
	else{
		x = cosmo.getX() - aAnvil.getX();
		y = cosmo.getY() - aAnvil.getY();
	}
		double distance = sqrt(x*x + y*y);
	if (distance <= mCollisionDistance){
		//anvil always hits
		scorekeeper.incScoreBalloon(5);
		return ANVIL_HIT;
	}
	else
		return NO;
}
void Controller::hasCollidedWithBee(TerribleBalloon tBalloon){
	//Check to see if Cosmo has been hit by a bee
	int x=0;
	int y=0;
	if(sCos){
		x = superCosmo.getX() - tBalloon.getX();
		y = superCosmo.getY() - tBalloon.getY();
	}
	else{
		x = cosmo.getX() - tBalloon.getX();
		y = cosmo.getY() - tBalloon.getY();
	}
		double distance = sqrt(x*x + y*y);
	if (distance <= mCollisionDistance){
		scorekeeper.incScoreBalloon();
	}
}
COLLISION Controller::hasCollidedWithCosmo(Balloon pBalloon){
	//get the x separation
	int x=0;
	int y=0;
	if(sCos){
		x = superCosmo.getX() - pBalloon.getX();
		y = superCosmo.getY() - pBalloon.getY();
	}
	else{
		x = cosmo.getX() - pBalloon.getX();
		y = cosmo.getY() - pBalloon.getY();
	}

	double distance = sqrt(x*x + y*y);
	if (distance <= mCollisionDistance){
		//now is the time to see where cosmo was hit
		//-on head the balloon wins
		//-on side with needle(s) cosmo wins
		DIRECTION dir = cosmo.getDir();

		if (dir == UP || (x>0 && dir==LEFT) || (x<0 && dir==RIGHT)){
			scorekeeper.incScoreCosmo();
			return COSMO_POPPED;
		}

		//balloon hit cosmo on head or back or cosmo was standing with arms on hips 
		scorekeeper.incScoreBalloon();
		return BALLOON_CLOBBERED;
	}
	else
		return NO;
}

Controller::~Controller(void)
{
}
