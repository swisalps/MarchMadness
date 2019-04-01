//This program provides the structure for the team
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Team {
	string location, teamName;
	map<Team, int[]> teamsPlayed;
	double rating;
	int wl;
	Team(string name, string loc) {
		teamName = name;
		location = loc;
	}

};