// This program ranks college basketball teams using the outcomes from past games.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class MarchMadness{

    // Global Variables
    public:
    ofstream outputFile;
    string line;
    string date;
    string team1, team1Score, team2, team2Score;

    // Constructor
    MarchMadness(){
        //myfile.open("ncaaD1.txt", ios::in);
        //ifstream inputFile("ncaaD1.txt");
        // while(inputFile >> date >> team1 >> team1Score >> team2 >> team2Score){
        //     cout << date << '\t' << team1 << '\t' << team1Score << '\t' << team2 << '\t' << team2Score << endl;
        // }

        //printFile();
        printFile2();
        outputFile.close();
    }

    // Prints the contents of the file "ncaaD1.txt" in the correct format.
    // Prints based on line presence.
    void printFile(){
        ifstream inputFile("ncaaD1.txt"); // Creates a file to read from and opens it

        if(inputFile.is_open()){ // Check if the file is open
            string line;
            while(getline(inputFile,line)){ // While there is a line of text/strings...
                cout << line << endl;
            }
            inputFile.close(); // Close the file
        }
        else{
            cout << "Error: Problem with opening the file" << endl;
        }
    }

    // Prints the contents of the file "ncaaD1.txt" in the correct format.
    // Prints based on word presence.
    void printFile2(){
        ifstream inputFile("ncaaD1.txt");

    }
};

// Main
int main(){
    MarchMadness* test = new MarchMadness();
    delete test;
    return 0;
}