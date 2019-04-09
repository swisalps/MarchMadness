// This program ranks college basketball teams using the outcomes from past games.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Dense>


#include "Game.h"
#include "Team.h"
#include "MarchMadness.h"
using namespace std;



	

	

	// Constructor
	MarchMadness::MarchMadness(){
		//myfile.open("ncaaD1.txt", ios::in);
		//ifstream inputFile("ncaaD1.txt");
		// while(inputFile >> date >> team1 >> team1Score >> team2 >> team2Score){
		//     cout << date << '\t' << team1 << '\t' << team1Score << '\t' << team2 << '\t' << team2Score << endl;
		// }

		//printFile();
		printFile();
		// outputFile.close();
	}

	// Prints the contents of the file "ncaaD1.txt" in the correct format.
	// Prints based on word presence.
	// NOTE: This function works only for "ncaaD1.txt". Using any other file may result in at least three changes to this function.
	// These changes relate to the number of if-statements for checking the team name length,
	// changing the year, and changing the tab length.
	void MarchMadness::printFile(){
		ifstream inputFile("ncaaD1v2.txt"); // Creates a file to read from and opens it
		ofstream writer("ncaaD1out.txt"); // Created to check if the printFile is working since terminal is too small
		if (inputFile.is_open() && writer.is_open()){ // Check if the file is open
			string word;
			string date, team1, score1, team2, score2, flag, venue, location;
			bool setDate = false;
			while (inputFile >> word){
				// 1) Get the date
				// 2) Get Team1's name (at most 3 words)
				// 3) Get Team1's Score
				// 4) Get Team2's name (at most 3 words)
				// 5) Get Team2's Score
				// 6) Get the Flag (if there is one; can be a number or a string)
				// 7) Check for cities/states and skip them
				// 8) Print

				// ------ Step1 ------
				if (setDate == false){
					date = word;
					inputFile >> word; // go to the next word
				}
				// ------ Step2 & Step3 ------
				team1 = word;
				// Check if one of the next 2 words are NOT integers (part of the team's name)
				inputFile >> word; // Go to the next word
				if (!isNumber(word)){ // If the first word is NOT an int...
					team1.append(" " + word); // append the word to the team name; the team name should now be 2 words long
					inputFile >> word; // Go to the next word to check if the second word is NOT an int
					if (!isNumber(word)){ // If the second word is ALSO NOT an int...
						team1.append(" " + word); // append the word to the team name; the team name should now be 3 words long
						inputFile >> word; // Go to the next word which is the score
						score1 = word; // Set the score of team1; the team has 3 words in its name
						inputFile >> word;
					}
					else { score1 = word; inputFile >> word; } // Else Set the score of team1; the team has 2 words in its name
				}
				else { score1 = word; inputFile >> word; } //Else Set the score of team1; the team has 1 word in its name
				// ------ Step4 & Step5 ------
				team2 = word;
				// Check if one of the next 2 words are NOT integers (part of the team's name)
				inputFile >> word; // Go to the next word
				if (!isNumber(word)){ // If the first word is NOT an int...
					team2.append(" " + word); // append the word to the team name; the team name should now be 2 words long
					inputFile >> word; // Go to the next word to check if the second word is NOT an int
					if (!isNumber(word)){ // If the second word is ALSO NOT an int...
						team2.append(" " + word); // append the word to the team name; the team name should now be 3 words long
						inputFile >> word; // Go to the next word which is the score
						score2 = word; // Set the score of team2; the team has 3 words in its name
						inputFile >> word;
					}
					else { score2 = word; inputFile >> word; } // Else Set the score of team2; the team has 2 words in its name
				}
				else { score2 = word; inputFile >> word; } //Else Set the score of team2; the team has 1 word in its name


				// ------ Step6 & Step7------
				if ((word.substr(0, 4) == "2018" || word.substr(0, 4) == "2019") || (inputFile.eof())){ // If the word is a date...
					flag = "N/A";
					venue = "N/A";
					setDate = true; // the current word you are on is the date of the next line
				}
				else{ // Else the current word is not a date but instead a flag and/or a venue
					// There is a flag...
					if (word.length() <= 3 && (word.substr(0, 1) == "P" || word.substr(0, 1) == "F" || word.substr(0, 1) == "S" || word.substr(0, 1) == "E" || word.substr(0, 1) == "O")){
						flag = word;
						inputFile >> word;
						// AND there is a venue...
						if ((!(word.substr(0, 4) == "2018" || word.substr(0, 4) == "2019")) && (!inputFile.eof())){
							for (int i = 1; i <= 7; i++){
								if (!(word.substr(0, 4) == "2018" || word.substr(0, 4) == "2019")){ // so long as the word is not the date...
									venue += word + " ";
									inputFile >> word;
									if (inputFile.eof()){
										venue += word;
										break;
									}
								}
								else{ break; }
							}
							setDate = true; // the current word is the date; set the date before the while loop ends
						}
						else{ // else there is no venue; you either reached the end of the file or another date; there's only a flag
							venue = "N/A";
							setDate = true; // the current word is the date; set the date before the while loop ends
						}
					}
					else{ // There is no flag; only a venue
						flag = "N/A";
						for (int i = 1; i <= 7; i++){
							if (!(word.substr(0, 4) == "2018" || word.substr(0, 4) == "2019")){ // so long as the word is not the date...
								venue += word + " ";
								inputFile >> word;
								if (inputFile.eof()){ //Check if it is the end of the file
									venue += word;
									break;
								}
							}
							else{ break; }
						}
						setDate = true; // the current word is the date; set the date before the while loop ends
					}
				}


				// ------ Step8 ------
				// adjust the tab length so the printed format looks more readable
				string teamTab1 = "\t\t";
				if (team1.length() <= 4) { teamTab1 += "\t"; }
				if (team1.length() <= 8) { teamTab1 += "\t"; }
				if (team1.length() <= 12) { teamTab1 += "\t"; }
				//@UC Santa Barbara is 17 characters long which is the only longest name in the list of Team1
				if (team1.length() >= 17) { teamTab1 = "\t"; }

				string teamTab2 = "\t\t";
				if (team2.length() <= 4) { teamTab2 += "\t"; }
				if (team2.length() <= 8) { teamTab2 += "\t"; }
				if (team2.length() <= 12) { teamTab2 += "\t"; }

				string flagTab = "\t";
				if (flag.length() == 1){ flagTab += "\t"; }
				//@Houston-Victoria is 17 characters long which is the only longest name in the list of Team2
				if (team2.length() >= 17) { teamTab2 = "\t"; }
				// Write to output file
				writer << "Date: " << date << '\t'
					<< "Team1: " << team1 << teamTab1
					<< "Score1: " << score1 << '\t'
					<< "Team2: " << team2 << teamTab2
					<< "Score2: " << score2 << '\t'
					<< "Flag: " << flag << flagTab
					<< "Venue: " << venue << endl;

				// Generate a Game object and put it into the game vector
				if (team1.substr(0, 1) == "@"){ // If the game is at team1's location
					location = team1.substr(1, team1.length());
					team1 = location;
				}
				else if (team2.substr(0, 1) == "@"){ // If the game is at team2's location
					location = team2.substr(1, team2.length());
					team2 = location;
				}
				else{ location = venue; } // If the game is at neither team's location but instead a venue
				// Create a stringstream object to convert a string into an int for the scores
				stringstream convertScore1(score1);
				stringstream convertScore2(score2);
				int s1 = 0;
				int s2 = 0;
				convertScore1 >> s1;
				convertScore2 >> s2;
				// Make the Game Object and insert it
				//gameVector.emplace_back(new Game(team1, team2, location, s1, s2));
				// *** End of Generating Game object & inserting into vector

				// Insert the team names into the team vector
				// Make sure there are no repeats

				// for(int i=0; i<teamVector.size(); i++){
				// 	if(){//if the id's do not match, add it
				// 		teamVector.emplace_back();
				// 	}
				// }

				if (setDate == true){ // The word you are currently on is the date of the next line.
					date = word;     // When you repeat the while loop, you will be on the name of team1, not the date
				}
				venue = ""; // reset the venue
			}
			inputFile.close(); // Close the file
			writer.close(); // Close the output file
		}
		else{
			cout << "Error: Problem with opening the file" << endl;
		}
	}


	bool MarchMadness::isNumber(string word){
		for (int i = 0; i < word.length(); i++)
			if (isdigit(word[i]) == false)
				return false;

		return true;
	}


// Main
int main(){
	MarchMadness* test = new MarchMadness();
	delete test;
	return 0;
}