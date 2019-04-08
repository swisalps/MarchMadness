#ifndef _MARCHMADNESS_TEAM_H_
#define _MARCHMADNESS_TEAM_H_


#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include "Game.h"

class Game;


class Team{

public:
	int teamID;
	std::string teamName;
	std::map<Team, int[]> teamsPlayed;
	double rating;
	int wl;


	Team();

	/**
	* @param ID the team object for the first team
	* @param name the team object for the second team
	*/
	Team(int ID, std::string name);

	/**
	*returns the numerical ID of this team
	*/
	int getID();

	/*
	*gets the literal name of the team, from print purposes mostly
	*/
	std::string getTeamName();

	/*
	* set the team ID to to a new value
	*/
	void setID(int newID);

	/*
	*set the team name to a new string name
	*/
	void setTeamName(std::string newName);
	/**
	* @return the game object as a string.
	*/
	std::string toString();


};
#endif //MARCHMADNESS_TEAM_H