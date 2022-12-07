// Includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// My Headers
#include "helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 1;
bool bTestData      = false;
bool bDebug         = true;
int iPart1Answer    = 0;
int iPart2Answer    = 0;

// Data Variables
vector<string> vData;
vector<string> vTestData;
vector<string> *pCurData;

// Main() function: where the execution of program begins
int main()
{

    // **************************************************************************************************************
    // INITIALIZATION STEP 
    // PREPARE DAY, INIT DATA, FILL VARIABLES, CHECK DEBUG STATUS  
    // **************************************************************************************************************

    // Initialize the day, grab all data
    aoc_init(iDay, vTestData, vData);

    // Mark the Day
    cout << "DAY " << iDay << endl;

    (bTestData) ? cout << "TEST DATA IS: ON" << endl : cout << "TEST DATA IS: OFF" << endl;
    (bDebug) ? cout << "DEBUG OUTPUT IS: ON" << endl : cout << "DEBUG OUTPUT IS: OFF";
    cout << endl;

    // point data based on debug
    pCurData = (bTestData) ? &vTestData : pCurData = &vData;

    // **************************************************************************************************************
    // PREPARATION STEP 
    // DUMP RAW DATA AT THE TOP, RUN ADDITIONAL DEBUG/TEST DATA REVIEWS 
    // **************************************************************************************************************

    // Belch out Data
    cout << "DATA DUMP" << endl;
    for (string line : *pCurData) {
        cout << line << endl;
    }

    // End of data dump
    cout << "END OF DATA DUMP" << endl << endl;

    // **************************************************************************************************************
    // BEGINNING DAY / OPENING 
    // RUN DAY 1.1 CALCULATIONS
    // **************************************************************************************************************

    cout << "STARTING DAY " << iDay << ".1 CALCULATIONS..." << endl;

    // Make a pack of elves
    vector<int> viElves;

    // First elf starts with 0
    int iCurInventory = 0;

    // Go through the packs
    for (string line : *pCurData) {

        // Found an item in the pack
		if(line.size() > 0) {
            iCurInventory += stoi(line);
        }

        // No more items
        else {
            viElves.push_back(iCurInventory);
            iCurInventory = 0;
        }
    }
    // Catch the last Elf
    viElves.push_back(iCurInventory);

    // Print out the results
    // And find the biggest carry
    int iElfMax     = 0;
    int iElfTotal   = 0;

    for (int i = 0; i < viElves.size(); i++ ) {
        cout << "ELF #" << i << " has a pack total of: " << viElves[i] << endl;
        if (viElves[i] > iElfTotal) {
            iElfMax = i;
            iElfTotal = viElves[i];
        }
    }
    cout << endl;

    cout << "The elf with the most calories is: " << iElfMax << " with a total calorie count of: " << iElfTotal << endl << endl;

    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;

    // Sort the elves by value
    sort(viElves.begin(), viElves.end());

    // Display the sorted packs
    for (int i = 0; i < viElves.size(); i++ ) {
        cout << "ELF #" << i << " has a pack total of: " << viElves[i] << endl;
    }

    // Grab the total of 3 elves
    int iMaxTotal = 0;
    for (int i = 0; i < 3; i++) {
        iMaxTotal += viElves.back();
        viElves.pop_back();
    }

    cout << "The 3 biggest packs have a total of: " << iMaxTotal << endl;

    return 0;
}
