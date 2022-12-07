// Includes
#include "../Helpers/helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 6;
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

    // Go through ALL test cases (or the sole case for real data)
    int iBitSize = 4;
    for (string line : *pData) {

        int result = searchUnique(line, iBitSize);

        if (result) {
            cout << "Result is found at: " << result << endl;
        } else {
            cout << "NO UNIQUENESS FOUND!" << endl;
        }

        cout << endl;
    }

    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    // Go through ALL test cases (or the sole case for real data)
    iBitSize = 14;
    for (string line : *pData) {

        int result = searchUnique(line, iBitSize);

        if (result) {
            cout << "Result is found at: " << result << endl;
        } else {
            cout << "NO UNIQUENESS FOUND!" << endl;
        }

        cout << endl;
    }

    return 0;
}
