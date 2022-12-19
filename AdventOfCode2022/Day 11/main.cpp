// Includes
#include "../Helpers/helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 11;
bool bTestData      = true;
bool bDebug         = true;

// Data Variables
vector<string> vData;
vector<string> vTestData;
vector<string> *pData;

class Monkey {
    public:
        int num;
        vector<int> items;
        string op;
        string opVal;
        int inspections = 0;
        int testVal;
        int testPass;
        int testFail;

    // Do the monkey operation
    void runOp(int item) {
        int val;
        int origin = this->items[item];

        // Set the value to the correct term
        if (this->opVal == "old") {
            val = this->items[item];
        } else {
            val = stoi(this->opVal);
        }

        // Run the operation
        if (this->op == "+") {
            this->items[item] += val; 
        } else if (this->op == "-") {
            this->items[item] -= val; 
        } else if (this->op == "*") {
            this->items[item] *= val;
        } else if (this->op == "/") {
            this->items[item] /= val;
        } 

        // Show what we did
        std::cout << "Just did " << this->items[item] << " = " << val << " " << this->op << " " << origin << endl;

    }

    // Display monkey info
    void display() {
        std::cout << "I am Monkey " << this->num << " and I have " << items.size() << " items." << endl;
        std::cout << "My operation function will " << op << opVal << " when I inspect the item." << endl;
    }
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

    // Fill the monkeys
    vector<Monkey> vMonkeys;
    Monkey m;

    for (string line : *pData) {

        // Trim excess space
        line = trim(line, " \t");

        // Start to break the list line by line
        vector<string> vLineData;
        splitStringBy(line, " ", vLineData);

        if (vLineData.size()) {
            for (int i = 0; i < vLineData.size(); i++) {

                // Clear out the extra junk
                vLineData[i] = trim(vLineData[i], ":");
                vLineData[i] = trim(vLineData[i], ",");

                cout << "Element " << i << ": " << vLineData[i] << endl;

                // Sort through the monkey operations
                // Assign the Monkey ID value
                if (vLineData[0] == "Monkey") {
                    m.num = stoi(vLineData[1]);

                // Set up starting items
                } else if (vLineData[0] == "Starting") {
                    for (i = 2; i < vLineData.size(); i++) {
                        m.items.push_back( stoi(vLineData[i]) );
                    }

                // Set the operations
                } else if (vLineData[0] == "Operation") {
                    m.op = vLineData[4];
                    m.opVal = vLineData[5];

                // Set the test
                } else if (vLineData[0] == "Test") {
                    m.testVal = stoi(vLineData[3]);

                // Set Test True Target
                } else if (vLineData[0] == "If" && vLineData[1] == "true") {
                    m.testPass = stoi(vLineData[5]);

                // Set Test False Target
                } else if (vLineData[0] == "If" && vLineData[1] == "false") {
                    m.testFail = stoi(vLineData[5]);
                } 
            }

        // We've finished the Monkey
        } else {
            // Send the monkey to the list
            cout << "Finishing Monkey!" << endl;
            vMonkeys.push_back(m);

            // Clean the monkey up
            m.items.clear();
        }

        cout << endl;
    }

    // Add that last Monkey into the chain
    vMonkeys.push_back(m);

    // Do I have monkeys?
    for (int i = 0; i < vMonkeys.size(); i++) {
        vMonkeys[i].display();

        // Each monkey goes through each of their items
        for (int j = 0; j < vMonkeys[i].items.size(); j++) {
            vMonkeys[i].runOp(j);
        }
    }

    cout << endl;

    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;





    return 0;
}
