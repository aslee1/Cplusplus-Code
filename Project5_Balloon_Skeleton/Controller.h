#pragma once
#include <vector>
#include "constants.h"
#include "person.h"
#include "balloon.h"
#include "scorekeeper.h"
#include "instructions.h"
#include "Anvil.h"
#include "SuperPerson.h"
#include "TerribleBalloon.h"

class Controller
{
public:
	Controller(int width, int height, SPEED speed=MEDIUM);
	~Controller(void);

	//render the scene
	void draw();
	void createBalloon();
	void createAnvil();
	//how fast is the game?
	inline void setSpeed(SPEED speed){mSpeed = speed;};

	//current state intro or run
	inline void setControllerState(CONTROLLER_STATE state){mControllerState = state;};

	void makeCosmoSuper(bool sCos=false); 
	void makeBalloonsTerrible(bool tBall=false);

	void hasCollidedWithBee(TerribleBalloon Tballon);
	COLLISION hasCollidedWithCosmo(Balloon pBalloon);
	COLLISION hasCollidedWithCosmoAnvil(Anvil aAnvil);
	inline void changeCosmoDirection(DIRECTION dir){cosmo.setDirection(dir);};
private:
	//reset it all
	void initialize();
	void superInitialize();
	//fills screen buffer with blanks
	void clearScreen();
	bool sCos;
	bool tBall;
	//draw scores if needed
	void renderScoresToScreenbuffer();
	
	SPEED mSpeed;		//game speed
	int iTimeBetweenBalloonCreation;
	int iTimeBetweenAnvilCreation;
	sizeofScreenBuffer myScreenBufferSize;	//width and height of consolewindow

	//holds entire consolewindow screen, 
	//usually 80 chars wide by 24 lines long
	std::vector<std::string> myScreenVector;

	//all of our balloons
	std::vector <TerribleBalloon> myterribleBalloons;
	std::vector<Balloon> myBalloons;
	std::vector<Anvil> myAnvils;
	//cosmo the person

	Person cosmo;
	SuperPerson superCosmo; 

	//for writing instructions
	Instructions myInstructions;

	//max distance between center of squares for a collision to have occured
	//its corner of one object bounding box touching corner of another
	double mCollisionDistance;

	ScoreKeeper scorekeeper;
	CONTROLLER_STATE mControllerState;
};

