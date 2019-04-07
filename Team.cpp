//This program provides the structure for the team
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Team {
	string teamName; //note: the team's name is for all intents and purposes equal to the location
	map<Team, int[]> teamsPlayed;
	double rating;
	int wl;
	Team(string name) {
		teamName = name;
        rating = 0.0;
        wl = 0;
	}

    double getRating()
    {
        return rating;
    }

    void setRating(double rate)
    {
		rating = rate;
    }

};