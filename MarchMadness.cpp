// This program ranks college basketball teams using the outcomes from past games.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class MarchMadness{

    // Global Variables
    public:
    // ofstream outputFile;
    // string line;
    // string date;
    // string team1, team1Score, team2, team2Score;

    // Constructor
    MarchMadness(){
        //myfile.open("ncaaD1.txt", ios::in);
        //ifstream inputFile("ncaaD1.txt");
        // while(inputFile >> date >> team1 >> team1Score >> team2 >> team2Score){
        //     cout << date << '\t' << team1 << '\t' << team1Score << '\t' << team2 << '\t' << team2Score << endl;
        // }

        //printFile();
        printFile2();
        // outputFile.close();
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
        ifstream inputFile("ncaaD1.txt"); // Creates a file to read from and opens it
        if(inputFile.is_open()){ // Check if the file is open
            string word;
            string date, team1, score1, team2, score2, flag;
            bool setDate = false;
            while(inputFile >> word){
                // 1) Get the date
                // 2) Get Team1's name (at most 3 words)
                // 3) Get Team1's Score
                // 4) Get Team2's name (at most 3 words)
                // 5) Get Team2's Score
                // 6) Get the Flag (if there is one; can be a number or a string)
                // 7) Print

                // ------ Step1 ------
                if(setDate == false){
                    date = word;
                    inputFile >> word; // go to the next word
                }
                // ------ Step2 & Step3 ------
                team1 = word;
                // Check if one of the next 2 words are NOT integers (part of the team's name)
                inputFile >> word; // Go to the next word
                if(!isNumber(word)){ // If the first word is NOT an int...
                    team1.append(" " + word); // append the word to the team name; the team name should now be 2 words long
                    inputFile >> word; // Go to the next word to check if the second word is NOT an int
                    if(!isNumber(word)){ // If the second word is ALSO NOT an int...
                        team1.append("" + word); // append the word to the team name; the team name should now be 3 words long
                        inputFile >> word; // Go to the next word which is the score
                        score1 = word; // Set the score of team1; the team has 3 words in its name
                        inputFile >> word;
                    } else {score1 = word; inputFile >> word;} // Else Set the score of team1; the team has 2 words in its name
                } else {score1 = word; inputFile >> word;} //Else Set the score of team1; the team has 1 word in its name
                // ------ Step4 & Step5 ------
                team2 = word;
                // Check if one of the next 2 words are NOT integers (part of the team's name)
                inputFile >> word; // Go to the next word
                if(!isNumber(word)){ // If the first word is NOT an int...
                    team2.append(" " + word); // append the word to the team name; the team name should now be 2 words long
                    inputFile >> word; // Go to the next word to check if the second word is NOT an int
                    if(!isNumber(word)){ // If the second word is ALSO NOT an int...
                        team2.append("" + word); // append the word to the team name; the team name should now be 3 words long
                        inputFile >> word; // Go to the next word which is the score
                        score2 = word; // Set the score of team1; the team has 3 words in its name
                        inputFile >> word;
                    } else {score2 = word; inputFile >> word;} // Else Set the score of team1; the team has 2 words in its name
                } else {score2 = word; inputFile >> word;} //Else Set the score of team1; the team has 1 word in its name
                // ------ Step6 ------
                if(word.substr(0,4) == "2019"){ // If the length of the word is equal to 10...
                    flag = "N/A";
                    setDate = true; // the current word you are on is the date of the next line
                }
                else{flag = word; setDate = false;} // Else the word is a flag
                //inputFile.putback(-(word.length()+flag.length()));
                // ------ Step7 ------
                cout << "Date: " << date << '\t'
                     << "Team1: " << team1 << '\t' << '\t'
                     << "Score1: " << score1 << '\t'
                     << "Team2: " << team2 << '\t' << '\t'
                     << "Score2: " << score2 << '\t'
                     << "Flag: " << flag << endl;

                if(setDate == true){
                    date = word;
                }
            }
            inputFile.close(); // Close the file
        }
        else{
            cout << "Error: Problem with opening the file" << endl;
        }
    }

    bool isNumber(string word){
        for (int i = 0; i < word.length(); i++)
            if (isdigit(word[i]) == false)
                return false;

        return true;
    }
};

// Main
int main(){
    MarchMadness* test = new MarchMadness();
    delete test;
    return 0;
}