// Includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// My Headers
#include "helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 3;
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

    // Go through each pack
    int iPriority = 0;
    for (string line : *pData ) {

        // First split the pack into two halves
        string sFront = line.substr(0, line.length()/2);
        string sBack = line.substr(line.length()/2);

        cout << "Front: " << sFront << " and Back: " << sBack << endl;

        // Now find the shared item
        for (int i = 0; i < sFront.size(); i++) {
            if (sBack.find(sFront[i]) != std::string::npos) {
                cout << "Found the shared piece: " << sFront[i] << endl;

                // Now calculate the value
                if (isupper(sFront[i])) {
                    cout << "With a value of: " << (int)sFront[i] - 38 << endl;
                    iPriority += (int)sFront[i] - 38;
                } else {
                    cout << "With a value of: " << (int)sFront[i] - 96 << endl;
                    iPriority += (int)sFront[i] - 96;
                }

                // Prevent looping
                break;
            }
        }

        cout << endl; 
    }

    // Print the priority total
    cout << "Total priority count is: " << iPriority << endl;

    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    // Grab 3 packs at a time
    int iNewPriority = 0;
    int iElfPack = 0;
    string cBadge = "";
    vector<string> vElfGroup;

    // Go pack by pack, assigning 3 packs into a group
    for (string line : *pData) {
        iElfPack++;
        cout << line << endl;
        vElfGroup.push_back(line);

        // Group is full, do bagunças
        if (iElfPack == 3) {
            cout << "FULL TEAM! Size of: " << vElfGroup.size() << endl;

            // Search all 3 packs for the common item
            for (int i = 0; i < vElfGroup[0].size(); i++) {
                if (vElfGroup[1].find(vElfGroup[0][i]) != std::string::npos && 
                    vElfGroup[2].find(vElfGroup[0][i]) != std::string::npos ) {

                    // Found the shared item!
                    cBadge = vElfGroup[0][i];
                    cout << "FOUND the badge! " << cBadge << endl;

                    // Now calculate the value
                    if (isupper(cBadge[0])) {
                        cout << "With a value of: " << (int)cBadge[0] - 38 << endl;
                        iNewPriority += (int)cBadge[0] - 38;
                    } else {
                        cout << "With a value of: " << (int)cBadge[0] - 96 << endl;
                        iNewPriority += (int)cBadge[0] - 96;
                    }

                    break;
                }
            }

            // Clear the group and prepare for the next one
            iElfPack = 0;
            vElfGroup.clear();
            cout << endl;
        }
    }

    // Output the total count
    cout << "Total priority of the badges is: " << iNewPriority << endl;

    return 0;
}
