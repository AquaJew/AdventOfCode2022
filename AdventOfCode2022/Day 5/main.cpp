// Includes
#include "../Helpers/helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 5;
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

    // First we need to sort the data so it's useable. 
    // Stacks are separated by 4, starting at 1: 1, 5, 9, 13, etc.
    // Need to push data to the FRONT when we build the list, to have the top element the furthest out.
    // Stacks start numbered at 1 NOT 0.
    int iRow = 0;
    int iCol = 0;
    bool bStacking = false;
    vector<string> vStacks;
    vector<string> vInstructions;

    // Initialize the vector
    for (int i = 0; i < 10; i++) {
        vStacks.push_back("");
    }

    // Iterate through the stacks (but break when the stacks are empty)
    for (string row : *pData ) {

        // If we're stacked, let's start to fill the instructions
        if (bStacking) {

            if (row.size()) {
                vInstructions.push_back(row);
            }
            continue;
        }
    
        // Go through the stacks
        for (int i = 1; i <= row.size(); i+= 4) {

            iCol++; // Make sure we're on the right stack
            cout << "Crate " << row[i] << " on Stack: " << iCol << endl;

            // Shut down the stack collection when we find the 1
            if (row[1] == '1') {
                cout << "Reached the floor!" << endl;
                bStacking = true;
                break;
            }

            // Still moving, so we can stick the crate on the stack
            if (row[i] != ' ') {
                vStacks[iCol].insert(vStacks[iCol].begin(), row[i]);
                cout << "Stack: " << iCol << " has: " << vStacks[iCol] << endl;
            }

        }

        // Move to the next Row
        iRow++;
        iCol = 0;
    }

    cout << endl;

    // Show the stacks!
    for (string stack : vStacks) {

        if (stack.size()) {
            cout << "Stack contains: " << stack << endl;
        }
    }

    cout << endl;

    // Show the instructions!
    vector<string> vStep;
    for (string row : vInstructions) {
        vStep.clear();
        cout << "Instruction: " << row << endl; 

        // Go through the instructions one by one
        splitStringBy(row, " ", vStep);

        cout << "Just the numbers: " << vStep[1] << ", " << vStep[3] << ", " << vStep[5] << endl;

        // Clean the data a bit to be easier to follow logic
        int iReps = stoi(vStep[1]);
        int iFrom = stoi(vStep[3]);
        int iTo = stoi(vStep[5]);

        // Process the order
        for (int i = 0; i < iReps; i++) {
            vStacks[iTo].push_back( vStacks[iFrom].back() );
            vStacks[iFrom].pop_back();
        }

        for (string stack : vStacks) {

            if (stack.size()) {
                cout << "Stack contains: " << stack << endl;
            }
        }

        cout << endl;

    }

    // Get the final strign
    string sTopCrates;

    for (string stack : vStacks) {

        if (stack.size() > 0) {
            sTopCrates += stack.back();
        }
    }
    cout << "Final topline: " << sTopCrates << endl;


    cout << endl;

    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    // Need to reinitialize the stacks and instructions

    // First we need to sort the data so it's useable. 
    // Stacks are separated by 4, starting at 1: 1, 5, 9, 13, etc.
    // Need to push data to the FRONT when we build the list, to have the top element the furthest out.
    // Stacks start numbered at 1 NOT 0.
    iRow = 0;
    iCol = 0;
    bStacking = false;
    vStacks.clear();
    vInstructions.clear();

    // Initialize the vector
    for (int i = 0; i < 10; i++) {
        vStacks.push_back("");
    }

    // Iterate through the stacks (but break when the stacks are empty)
    for (string row : *pData ) {

        // If we're stacked, let's start to fill the instructions
        if (bStacking) {

            if (row.size()) {
                vInstructions.push_back(row);
            }
            continue;
        }
    
        // Go through the stacks
        for (int i = 1; i <= row.size(); i+= 4) {

            iCol++; // Make sure we're on the right stack
            cout << "Crate " << row[i] << " on Stack: " << iCol << endl;

            // Shut down the stack collection when we find the 1
            if (row[1] == '1') {
                cout << "Reached the floor!" << endl;
                bStacking = true;
                break;
            }

            // Still moving, so we can stick the crate on the stack
            if (row[i] != ' ') {
                vStacks[iCol].insert(vStacks[iCol].begin(), row[i]);
                cout << "Stack: " << iCol << " has: " << vStacks[iCol] << endl;
            }

        }

        // Move to the next Row
        iRow++;
        iCol = 0;
    }

    cout << endl;

    // Show Stacks
    cout << "Current Stacks:" << endl;
    for (string str : vStacks) {
        if (str.size()) {
            cout << str << endl;
        }
    }

    // Show Instructions
    cout << "Current Instructions:" << endl;
    for (string str : vInstructions) {
        cout << str << endl;
    }

    // Show the instructions!
    vStep.clear();
    for (string row : vInstructions) {
        vStep.clear();
        cout << "Instruction: " << row << endl; 

        // Go through the instructions one by one
        splitStringBy(row, " ", vStep);

        cout << "Just the numbers: " << vStep[1] << ", " << vStep[3] << ", " << vStep[5] << endl;

        // Clean the data a bit to be easier to follow logic
        int iCrates = stoi(vStep[1]);
        int iFrom = stoi(vStep[3]);
        int iTo = stoi(vStep[5]);

        // Process the order
        /*
        for (int i = 0; i < iReps; i++) {
            vStacks[iTo].push_back( vStacks[iFrom].back() );
            vStacks[iFrom].pop_back();
        }
        */

        // Grab the crates in the correct order
        string s = vStacks[iFrom].substr(vStacks[iFrom].size() - iCrates, iCrates);

        // Remove them from the From stack
        for (int i = 0; i < iCrates; i++) {
            vStacks[iFrom].pop_back();
        }

        // Append them to the To stack
        vStacks[iTo] += s;

        for (string stack : vStacks) {
            if (stack.size()) {
                cout << "Stack contains: " << stack << endl;
            }
        }

        cout << endl;

    }

    // Get the final string
    sTopCrates.clear();

    for (string stack : vStacks) {

        if (stack.size() > 0) {
            sTopCrates += stack.back();
        }
    }
    cout << "Final topline: " << sTopCrates << endl;


    return 0;
}
