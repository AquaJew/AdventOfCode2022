// Includes
#include "../Helpers/helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 10;
bool bTestData      = false;
bool bDebug         = true;

// Data Variables
vector<string> vData;
vector<string> vTestData;
vector<string> *pData;

// Create Tick object per register
class Tick {
    public:
        int start;
        int end;
};

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

    // Initialize the register
    vector<Tick> vRegister;
    Tick t;
    t.start = 1;
    t.end = 1;
    vRegister.push_back(t);

    // Go line by line, break into components, and decide what to do with the register
    for (string line : *pData) {

        // First break into pieces of command and value
        vector<string> order;
        splitStringBy(line, " ", order);

        // Associate with easier terms
        string cmd = order[0];
        int val = 0;
        if (order.size() > 1) {
            val = stoi(order[1]);
        }

        // Now process the command
        cout << "Command: " << cmd << " - " << val << endl;

        // Get the current register value
        int iCurVal = vRegister[vRegister.size()-1].end;

        if (cmd == "noop") {

            // Command just delays the register by one
            Tick t;
            t.start = iCurVal;
            t.end   = iCurVal;
            vRegister.push_back(t);
        } else if (cmd == "addx") {

            // Command adds a value but only after the first tick
            Tick t;
            t.start = iCurVal;
            t.end   = iCurVal;
            vRegister.push_back(t);

            // Now the tick that changes
            t.start = iCurVal;
            t.end   = iCurVal + val;
            vRegister.push_back(t);

        }
    }

    // Inspect the register
    int i = 0;
    cout << endl;
    for (Tick t : vRegister) {
        cout << "Register clock [" << i << "] start: " << t.start << ", end: " << t.end << endl;
        i++;
    }
    cout << endl;

    // Calculate the signal strength
    int iSigStr = 0;

    // Need 20, 60, 100, 140, 180, 220
    for (int i = 20; i <= 220; i+= 40) {
        int sum = i * vRegister[i].start;
        cout << "Signal at [" << i << "]: " << vRegister[i].start << " for a total of " << sum << endl;
        iSigStr += sum;
    }

    cout << "Signal Strength: " << iSigStr << endl << endl;

    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    
    // Fill up a draw buffer with art
    vector<string> vBuffer;

    // Populate with empty strings
    for (int s = 0; s < 7; s++) {
        vBuffer.push_back("");
    }

    // Go through the register and check if the elements match up
    for (int t = 1; t < vRegister.size(); t++) {

        cout << "T = " << t << ", buffer: " << (t/40) << ", MOD: " << t%40 << ", Reg: " << vRegister[t].start << endl;

        if( abs(vRegister[t].start - ((t-1)%40)) <= 1 ) {
            vBuffer[((t-1)/40)] += "#";
        } else {
            vBuffer[((t-1)/40)] += ".";
        }
    }

    cout << endl;

    // Print out the buffer
    for (string line : vBuffer) {
        cout << line << endl;
    }


    return 0;
}
