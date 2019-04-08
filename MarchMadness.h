#ifndef _MARCHMADNESS_GAME_H_
#define _MARCHMADNESS_GAME_H_


#include <string>
#include <sstream>
#include <iostream>
//#include "Team.h"

class MarchMadness{

    public:
    std::vector<Team> teamVector, gameVector

    /**
    *main contructor for the MarchMadness class. takes the file names of
    *two files. One with the names of ever team with no repeats and another
    *with all the games played
    */
    MarchMadness(std::string teamsOnlyFileName, std::string gamesFileName);



    /**
    *function that fills an initalized matrix with the values from the
    *input files. One row and its corresponding column represent 1 team
    */
    createMainMatrix();

    /**
    *reads the inital ncaaD1.txt file and enters in only unique
    *team names into an array to be used to construct the matrix
    *
    */
    void readAllTeams(std::string teamFileName);


    /**
    *reads the ncaaD1.txt file and uses the generateGame method
    *to create a game object for each game than enters them
    *into a local vector to be used to contruct the matrix
    */

    void readAllGames(std::string gameFileName);
    /**
     * @return the game object as a string.
     */
    std::string toString();

};
#endif //MARCHMADNESS_GAME_H