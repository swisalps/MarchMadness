#ifndef _MARCHMADNESS_GAME_H_
#define _MARCHMADNESS_GAME_H_

#include <string>
#include <sstream>
#include <iostream>
#include "Team.h"

class Team;


class Game{

public:
    string team1, team2, location
    int team1Score, team2Score


    Game();

    /**
     * @param t1 the team object for the first team
     * @param t2 the team object for the second team
     * @param loc the location of the game
     * @param score1 the score of the first game
     * @param score2 the score of the second game
     */
    Game(std::string t1, std::string t2, std::string loc, int score1, int score2);

    /**
    *gets the location of the current game. home or away for team1
    *@return home or away for team1
    */
    std::string getLocation();

    /**
     * sets team1 to the provided parameter value
     * @param team1 the new team
     */
    void setTeam1(int team1);

    /**
     * gets this games team1
     * @return the current game's team1
     */
    std::string getTeam1();

    /**
     * sets the score1 to a parameter value
     * @param score1 the new score
     */
    void setScore1(int score1);

    /**
     * gets the current score1
     * @return the current score1
     */
    int getScore1();

    /**
     * sets the team2 to a parameter value
     * @param team2 the new team2
     */
    void setTeam2(int team2);


    /**
     * gets the current team2
     * @return the current team2
     */
    std::string getTeam2();

    /**
     * sets the score2 to a parameter value
     * @param score2 the new score2
     */
    void setScore2(int score2);

    /**
     * gets the current score2
     * @return the current score2
     */
    int getScore2();

    /**
     * @return the game object as a string.
     */
    std::string toString();

};
#endif //MARCHMADNESS_GAME_H