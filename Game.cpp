#include <string>
#include <sstream>
#include "Game.h"

using namespace std;

	// Global Variables
	//string team1, team2, location;
	//int team1Score, team2Score;

	// Constructor
	Game::Game(string t1, string t2, string loc, int score1, int score2){
		team1 = t1;
		team2 = t2;
		location = loc;
		team1Score = score1;
		team2Score = score2;
	}

	/**
	*gets the location current game
	*@return the game location
	*/
	string Game::getLocation(){
		return location;
	}

	/**
	* sets the team to a parameter value
	* @param team1 the new team
	*/
	void Game::setTeam1(int team1){
		this->team1 = team1;
	}

	/**
	* gets the current team1
	* @return the current team1
	*/
	std::string Game::getTeam1(){
		return this->team1;
	}

	/**
	* sets the score1 to a parameter value
	* @param score1 the new score
	*/
	void Game::setScore1(int score1){
		team1Score = score1;
	}

	/**
	* gets the current score1
	* @return the current score1
	*/
	int Game::getScore1(){
		return team1Score;
	}

	/**
	* sets the team2 to a parameter value
	* @param team2 the new team2
	*/
	void Game::setTeam2(int team2){
		team2Score = team2;
	}


	/**
	* gets the current team2
	* @return the current team2
	*/
	std::string Game::getTeam2(){
		return team2;
	}

	/**
	* sets the score2 to a parameter value
	* @param score2 the new score2
	*/
	void Game::setScore2(int score2){
		team2Score = score2;
	}

	/**
	* gets the current score2
	* @return the current score2
	*/
	int Game::getScore2(){
		return team2Score;
	}


	std::string Game::toString(){
		return  ("\t" + this->getLocation() + ", " + (this->getTeam1()) + ", " + std::to_string(this->getScore1()) +
			", " + (this->getTeam2()) + ", " + std::to_string(this->getScore2()) + ", ");
	}