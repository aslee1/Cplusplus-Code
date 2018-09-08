#include "ScoreKeeper.h"

const char COSMO_SCORE_PREFIX[]		= "COSMO =";
const int  LEN_COSMO_SCORE_PREFIX	= 7;
const char BALLOON_SCORE_PREFIX[]	= "BALLOONS ="; 
const int  LEN_BALLOON_SCORE_PREFIX	= 10;
const int  SPACES_FOR_SCORE			= 6;

ScoreKeeper::ScoreKeeper(void)
{
	int scoreBalloon=0;
	int scoreCosmo=0; 
	resetScores();
	incScoreBalloon(scoreBalloon);
	incScoreCosmo(scoreCosmo);
}

ScoreKeeper::~ScoreKeeper(void)
{
}

bool ScoreKeeper::getDisplayString(std::string &scoreString){
	//Calculate the score that goes in the display string here
	//ScoreKeeper scorekeeper; 
	std::string score = std::to_string(scoreCosmo); 
	std::string ballscore=std::to_string(scoreBalloon);
	scoreString=COSMO_SCORE_PREFIX+score+" "+BALLOON_SCORE_PREFIX+ballscore;
	return true;
}
