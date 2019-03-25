// This program ranks college basketball teams using the outcomes from past games.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class MarchMadness{
    public:
ofstream myfile;
string line;
string date;
int team1, team1Score, team2, team2Score;

MarchMadness(){
    //myfile.open("ncaaD1.txt", ios::in);
    ifstream inputFile("marks.txt");
    cout << "test" << endl;
    inputFile >> team1;
    inputFile >> line;
    cout << date << endl;
    cout << team1 << endl;
    while(inputFile >> date >> team1 >> team1Score >> team2 >> team2Score){
        cout << "test2" << endl;
        cout << date << team1 << team1Score << team2 << team2Score << endl;
    }

    myfile.close();
}
};

int main(){
 MarchMadness* test = new MarchMadness();
 delete test;
 return 0;
}