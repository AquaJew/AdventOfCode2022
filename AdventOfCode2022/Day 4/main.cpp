// Includes (Helper has everything included)
#include "../Helpers/helpers.h"

// My Headers
using namespace std;

// AOC Settings and Switches
int iDay            = 4;
bool bTestData      = true;
bool bDebug         = true;

// Data Variables
vector<string> vData;
vector<string> vTestData;
vector<string> *pData;

////////////////////////////////////////////////////////////////
// GUESSES
////////////////////////////////////////////////////////////////
// PART 1 
// ------
// 455 - TOO LOW
// 526 - TOO LOW
// 536 - CORRECT
//
////////////////////////////////////////////////////////////////


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

    // Count number of totally overlapped elves
    int iOverlapped = 0;
    int iEqual = 0;
    vector<string> vSections;
    vector<string> vFirst;
    vector<string> vSecond;


    // Break the lines up into elf pairs
    for (string line: *pData) {
        splitStringBy(line, ",", vSections);

        cout << "Section 1: " << vSections[0] << ", Section 2: " << vSections[1] << endl;

        // Check to see if the elves are duplicated
        // 1. Split the pairs into start/finish
        splitStringBy(vSections[0], "-", vFirst);
        splitStringBy(vSections[1], "-", vSecond);

        cout << "First Elf starts at: " << vFirst[0] << ", and ends at: " << vFirst[1] << endl;
        cout << "Second Elf starts at: " << vSecond[0] << ", and ends at: " << vSecond[1] << endl;

        // 2. Now compare the starts (less/equal) and the ends (more/equal)
        if (stoi(vFirst[0]) < stoi(vSecond[0])) {
            
            // First elf COULD envelop 2nd elf
            if (stoi(vFirst[1]) >= stoi(vSecond[1])) {
            }
            // 

        } else if (stoi(vFirst[0]) > stoi(vSecond[0])) {

            // Second elf COULD envelop 1st elf
            if (stoi(vFirst[1]) <= stoi(vSecond[1])) {
            }

        } else {

            // In the case when they start EQUAL, one will overlap the other
            if (stoi(vFirst[1]) < stoi(vSecond[1])) {
            } else if (stoi(vFirst[1]) > stoi(vSecond[1])) {
            } else {
            }

        }

        // Clear the results and split the next group
        vSections.clear();
        vFirst.clear();
        vSecond.clear();

        // Break the section up
        cout << endl;
    }

    // Now count the total overlaps
    cout << "TOTAL NUMBER OF FULL ENVELOPMENTS: " << iOverlapped << endl;
    cout << "TOTAL NUMBER OF EQUAL ELVES: " << iEqual << endl << endl;

    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    // Zero out Day 1 stuff and resort
    iOverlapped = 0;
    iEqual = 0;
    vSections.clear();
    vFirst.clear();
    vSecond.clear();

    // Break the lines up into elf pairs
    for (string line: *pData) {
        splitStringBy(line, ",", vSections);

        cout << "Section 1: " << vSections[0] << ", Section 2: " << vSections[1] << endl;

        // Check to see if the elves are duplicated
        // 1. Split the pairs into start/finish
        splitStringBy(vSections[0], "-", vFirst);
        splitStringBy(vSections[1], "-", vSecond);

        cout << "First Elf starts at: " << vFirst[0] << ", and ends at: " << vFirst[1] << endl;
        cout << "Second Elf starts at: " << vSecond[0] << ", and ends at: " << vSecond[1] << endl;

        // 2. Run checks to evaluate if the start of the first is anywhere in the second 
        if ((stoi(vFirst[0]) <= stoi(vSecond[0])) && (stoi(vFirst[1]) >= stoi(vSecond[0]))) {

            // There's overlap from the first to the second
            cout << "Elf 1 overlaps into Elf 2" << endl;
            iOverlapped++;

        // Now check if the 2nd elf starts before and runs into the first
        } else if ((stoi(vSecond[0]) <= stoi(vFirst[0])) && (stoi(vSecond[1]) >= stoi(vFirst[0]))) {

            // There's overlap from the second to the first
            cout << "Elf 2 overlaps into Elf 1" << endl;
            iOverlapped++;
        }


        // Clear the results and split the next group
        vSections.clear();
        vFirst.clear();
        vSecond.clear();

        // Break the section up
        cout << endl;
    }

    // Now count the total overlaps
    cout << "TOTAL NUMBER OF PARTIAL ENVELOPMENTS: " << iOverlapped << endl;

    return 0;
}
