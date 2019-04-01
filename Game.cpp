#include <string>

using namespace std;
class Game{

    // Global Variables
    public:
    string team1, team2, location;
    int team1Score, team2Score;


    // Constructor
    Game(string t1, string t2, string loc, int score1, int score2){
        team1 = t1;
        team2 = t2;
        location = loc;
        team1Score = score1;
        team2Score = score2;
    }
};