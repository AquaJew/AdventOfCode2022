// Includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// My Headers
#include "helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 2;
bool bTestData      = false;
bool bDebug         = true;

// Data Variables
vector<string> vData;
vector<string> vTestData;
vector<string> *pData;

// Main() function: where the execution of program begins
int main()
{

    // **************************************************************************************************************
    // INITIALIZATION STEP 
    // PREPARE DAY, INIT DATA, FILL VARIABLES, CHECK DEBUG STATUS  
    // **************************************************************************************************************

    // Initialize the day, grab all data
    getDayData(vTestData, vData);

    // Mark the Day
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// DAY " << iDay << endl;
    cout << "// ";
    (bTestData) ? cout << "TEST DATA IS: ON" << endl : cout << "TEST DATA IS: OFF" << endl;
    cout << "// ";
    (bDebug) ? cout << "DEBUG OUTPUT IS: ON" << endl : cout << "DEBUG OUTPUT IS: OFF" << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    // point data based on debug
    pData = (bTestData) ? &vTestData : &vData;

    // **************************************************************************************************************
    // PREPARATION STEP 
    // DUMP RAW DATA AT THE TOP, RUN ADDITIONAL DEBUG/TEST DATA REVIEWS 
    // **************************************************************************************************************

    // Belch out Data
    if (bDebug) {
        cout << "--- DATA DUMP ---" << endl;
        for (string line : *pData) {
            cout << line << endl;
        }
        cout << "--- END OF DATA DUMP ---" << endl << endl;
    }

    // **************************************************************************************************************
    // BEGINNING DAY / OPENING 
    // RUN DAY 1.1 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".1 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    // Go through the contests and set points
    int iPoints = 0;
    for (string line : *pData) {

        // Opponent chooses ROCK
        if (line[0] == 'A') {
            cout << "Opponent: Rock [A]!" << endl;

            // Player chooses ROCK
            if (line[2] == 'X') {
                cout << "Player: Rock [X], DRAW" << endl;
                iPoints += 1; // For Rock
                iPoints += 3; // For Draw
            }

            // Player chooses PAPER
            else if (line[2] == 'Y') {
                cout << "Player: Paper [Y], WIN" << endl;
                iPoints += 2; // For Paper
                iPoints += 6; // For Win
            }

            // Player chooses SCISSORS
            else if (line[2] == 'Z') {
                cout << "Player: Scissors [Z], LOSS" << endl;
                iPoints += 3; // For Scissors
                iPoints += 0; // For Loss
            }
        }

        // Opponent chooses PAPER
        else if (line[0] == 'B') {
            cout << "Opponent: Paper [B]!" << endl;

            // Player chooses ROCK
            if (line[2] == 'X') {
                cout << "Player: Rock [X], LOSS" << endl;
                iPoints += 1; // For Rock
                iPoints += 0; // For Loss
            }

            // Player chooses PAPER
            else if (line[2] == 'Y') {
                cout << "Player: Paper [Y], DRAW" << endl;
                iPoints += 2; // For Paper
                iPoints += 3; // For Draw
            }

            // Player chooses SCISSORS
            else if (line[2] == 'Z') {
                cout << "Player: Scissors [Z], WIN" << endl;
                iPoints += 3; // For Scissors
                iPoints += 6; // For Win
            }
        }

        // Opponent chooses SCISSORS
        else if (line[0] == 'C') {
            cout << "Opponent Scissors [C]!" << endl;

            // Player chooses ROCK
            if (line[2] == 'X') {
                cout << "Player: Rock [X], WIN" << endl;
                iPoints += 1; // For Rock
                iPoints += 6; // For Win
            }

            // Player chooses PAPER
            else if (line[2] == 'Y') {
                cout << "Player: Paper [Y], LOSS" << endl;
                iPoints += 2; // For Paper
                iPoints += 0; // For Loss
            }

            // Player chooses SCISSORS
            else if (line[2] == 'Z') {
                cout << "Player: Scissors [Z], DRAW" << endl;
                iPoints += 3; // For Scissors
                iPoints += 3; // For Draw
            }
        }

        // Space out the rounds
        cout << endl;
    }

    // Total points earned
    cout << "TOTAL POINTS: " << iPoints << endl;

    // Finish up
    cout << endl;


    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    // Set the new point strategy
    int iNewPoints = 0;
    for (string line : *pData) {

        // Opponent chooses ROCK
        if (line[0] == 'A') {
            cout << "Opponent chose: ROCK" << endl;

            // Player needs to LOSE
            if (line[2] == 'X') {
                cout << "Player must: LOSE" << endl;
                cout << "Player chooses: SCISSORS" << endl;

                // Point Calc
                iNewPoints += 3; // Picking Scissors
                iNewPoints += 0; // For the LOSS
            }

            // Player needs to DRAW
            if (line[2] == 'Y') {
                cout << "Player must: DRAW" << endl;
                cout << "Player chooses: ROCK" << endl;

                // Point Calc
                iNewPoints += 1; // Picking Rock
                iNewPoints += 3; // For the DRAW
            }

            // Player needs to WIN
            if (line[2] == 'Z') {
                cout << "Player must: WIN" << endl;
                cout << "Player chooses: PAPER" << endl;

                // Point Calc
                iNewPoints += 2; // Picking Paper
                iNewPoints += 6; // For the WIN
            }

        }

        // Opponent chooses PAPER
        else if (line[0] == 'B') {
            cout << "Opponent chose: PAPER" << endl;

            // Player needs to LOSE
            if (line[2] == 'X') {
                cout << "Player must: LOSE" << endl;
                cout << "Player chooses: ROCK" << endl;

                // Point Calc
                iNewPoints += 1; // Picking Rock
                iNewPoints += 0; // For the LOSS
            }

            // Player needs to DRAW
            if (line[2] == 'Y') {
                cout << "Player must: DRAW" << endl;
                cout << "Player chooses: PAPER" << endl;

                // Point Calc
                iNewPoints += 2; // Picking Paper
                iNewPoints += 3; // For the DRAW
            }

            // Player needs to WIN
            if (line[2] == 'Z') {
                cout << "Player must: WIN" << endl;
                cout << "Player chooses: SCISSORS" << endl;

                // Point Calc
                iNewPoints += 3; // Picking Scissors
                iNewPoints += 6; // For the WIN
            }
        }

        // Opponent chooses SCISSORS
        else if (line[0] == 'C') {
            cout << "Opponent chose: SCISSORS" << endl;

            // Player needs to LOSE
            if (line[2] == 'X') {
                cout << "Player must: LOSE" << endl;
                cout << "Player chooses: PAPER" << endl;

                // Point Calc
                iNewPoints += 2; // Picking Paper
                iNewPoints += 0; // For the LOSS
            }

            // Player needs to DRAW
            if (line[2] == 'Y') {
                cout << "Player must: DRAW" << endl;
                cout << "Player chooses: SCISSORS" << endl;

                // Point Calc
                iNewPoints += 3; // Picking Scissosrs
                iNewPoints += 3; // For the DRAW
            }

            // Player needs to WIN
            if (line[2] == 'Z') {
                cout << "Player must: WIN" << endl;
                cout << "Player chooses: ROCK" << endl;

                // Point Calc
                iNewPoints += 1; // Picking Rock
                iNewPoints += 6; // For the WIN
            }
        }

        cout << endl;
    } 

    cout << "Total new score: " << iNewPoints << endl;
    return 0;
}
