#ifndef _MARCHMADNESS_H_
#define _MARCHMADNESS_H_


#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

#include "Game.h"
#include "Team.h"

class MarchMadness{

public:
	std::vector<Team*> teamVector;
	std::vector<Game*> gameVector;
	std::vector<int> scoreDiff; //Vector representing the marging of vicory for a game
	Eigen::MatrixXi teamMatrix;


		/**
		*main contructor for the MarchMadness class. takes the file names of
		*two files. One with the names of ever team with no repeats and another
		*with all the games played
		*/
	MarchMadness();

	int getIdByName(std::string teamName);
    /**
    *large method, this method reads the file ncaaD1.txt and populates the teamList variable
    *with every unique team name in the file, it also populates the GamesList with every
    *game played during the regular season. It will also write the entire contents of the file
    *into an output file in a more usable format.
    *
    */
    void printFile();
	/**
	*function that fills an initalized matrix with the values from the
	*input files. One row and its corresponding column represent 1 team
	*/
	void createMainMatrix();

	

	

    bool isNumber(std::string word);

	/**
	* @return the game object as a string.
	*/
	std::string toString();

};
#endif //MARCHMADNESS_H