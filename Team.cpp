//This program provides the structure for the team
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "Team.h"

	Team::Team(int ID, std::string name) {
		teamName = name;
		teamID = ID;

	}

	int Team::getID(){
		return this->teamID;
	}

	std::string Team::getTeamName(){
		return this->teamName;
	}

	void Team::setID(int newID){
		teamID = newID;
	}

	void Team::setTeamName(std::string newName){
		teamName = newName;
	}

	std::string Team::toString(){
		return("\t" + std::to_string(this->getID()) + ", " + (this->getTeamName()));
		}
