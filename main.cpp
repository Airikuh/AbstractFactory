// Main program to run Program
#include "factory.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// Initializing the counter variable for each Generation for singleton checks
// This has to be initalized here or program runs into errors
int Word00::instanceCounter = 0;
int Word10::instanceCounter = 0;
int Word21::instanceCounter = 0;
int Word90::instanceCounter = 0;

// Global File Variable
const char* configFile = "Word.txt";


int main() {



	// Open the Word File, loop through Word Generations until reach end of file
	ifstream genFile(configFile);
	if (genFile.is_open()) {
		string generation;
		while (getline(genFile, generation)) {
			// Create an instance of the Abstract Word Factory Class
			Word* word;
			// If checks for each Generation to keep track of the Counter Variable
			if (generation == "Word00") {
				word = Word00::getInstance();
			}
			else if (generation == "Word10") {
				word = Word10::getInstance();
			}
			else if (generation == "Word21") {
				word = Word21::getInstance();
			}
			else if (generation == "Word90") {
				word = Word90::getInstance();
			}
			// Else we encountered something other than the specified Word generations
			else {
				cout << "INVALID INPUT. Not a Generation of Word." << endl;
				continue;
			}
			// If there are more than 2 instances of that generation, print warning to screen.
			if (word == nullptr) {
				cout << "WARNING: The same generation has alrady run 2 times." << endl;
				continue;
			}

			// Run ApControl and print information to screen.
			ApControl* controller = new ApControl(word);
			controller->printToScreen();
			cout << endl;

		}

		// Ensure the file is closed upon completion.
		genFile.close();

	}
	// Else the file could not be found or had issues
	else {
		cout << "Error Opening File. Check Extension" << endl;
		return 1;
	}



	return 0;


}


