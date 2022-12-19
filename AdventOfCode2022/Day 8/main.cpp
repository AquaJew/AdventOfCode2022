// Includes
#include "../Helpers/helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 8;
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

    // Put the trees into a 2d vector
    vector<vector <int> > vTrees;
    int iCurRow = 0;

    // Run through each row
    for (string row : *pData) {

        vector<int> curRow;

        // Run through each column 
        for (int i = 0; i < row.size(); i++) {
            int v = row.at(i) - '0';
            curRow.push_back(v);
        }
        
        // Add the row to the tree
        vTrees.push_back(curRow);

        // Prepare data for the next row
        iCurRow++;
        curRow.clear();
    }

    // Make a blank duplicate of the vector
    vector<vector <int> > vVisibleTrees = vTrees;
    for(int iRow = 0; iRow < vVisibleTrees.size(); iRow++) {
        for (int iCol = 0; iCol < vVisibleTrees[iRow].size(); iCol++) {
            vVisibleTrees[iRow][iCol] = -1;
        }
    }

    //////////////////////////////////////////
    // 1 OF 4
    // GOING LEFT TO RIGHT, TOP TO BOTTOM
    //////////////////////////////////////////
    int iCurHeight = -1;
    int iTreeCount = 0;

    // Need to loop through the array by value
    for(int iRow = 0; iRow < vTrees.size(); iRow++) {
        for (int iCol = 0; iCol < vTrees[iRow].size(); iCol++) {
            int tree = vTrees[iRow][iCol];

            // Check if the tree is visible, and mark on the blank map
            if (tree > iCurHeight) {
                iTreeCount++;
                iCurHeight = tree;
                vVisibleTrees[iRow][iCol] = tree;
            }
        }
        // Clear data for the next row
        iTreeCount = 0;
        iCurHeight = -1;
    }

    //////////////////////////////////////////
    // 2 OF 4
    // GOING RIGHT TO LEFT, TOP TO BOTTOM
    //////////////////////////////////////////
    iCurHeight = -1;
    iTreeCount = 0;

    // Need to loop through the array by value
    for(int iRow = 0; iRow < vTrees.size(); iRow++) {
        for (int iCol = vTrees[iRow].size()-1; iCol >= 0; iCol--) {
            int tree = vTrees[iRow][iCol];

            // Check if the tree is visible, and mark on the blank map
            if (tree > iCurHeight) {
                iTreeCount++;
                iCurHeight = tree;
                vVisibleTrees[iRow][iCol] = tree;
            }
        }
        // Clear data for the next row
        iTreeCount = 0;
        iCurHeight = -1;
    }    

    //////////////////////////////////////////
    // 3 OF 4
    // GOING TOP TO BOTTOM, LEFT TO RIGHT
    //////////////////////////////////////////
    iCurHeight = -1;
    iTreeCount = 0;

    // Need to loop through the array by value
    for(int iCol = 0; iCol < vTrees[0].size(); iCol++) {
        for (int iRow = 0; iRow < vTrees.size(); iRow++) {
             int tree = vTrees[iRow][iCol];

            // Check if the tree is visible, and mark on the blank map
            if (tree > iCurHeight) {
                iTreeCount++;
                iCurHeight = tree;
                vVisibleTrees[iRow][iCol] = tree;
            }
        }
        // Clear data for the next row
        iTreeCount = 0;
        iCurHeight = -1;
    }    


    //////////////////////////////////////////
    // 4 OF 4
    // GOING BOTTOM TO TOP, LEFT TO RIGHT
    //////////////////////////////////////////
    iCurHeight = -1;
    iTreeCount = 0;

    // Need to loop through the array by value
    for(int iCol = 0; iCol < vTrees[0].size(); iCol++) {
        for (int iRow = vTrees.size()-1; iRow >= 0; iRow--) {
             int tree = vTrees[iRow][iCol];

            // Check if the tree is visible, and mark on the blank map
            if (tree > iCurHeight) {
                iTreeCount++;
                iCurHeight = tree;
                vVisibleTrees[iRow][iCol] = tree;
            }
        }
        // Clear data for the next row
        iTreeCount = 0;
        iCurHeight = -1;
    }    

    //////////////////////////////////////////

    // Print the found trees map
    for(int iRow = 0; iRow < vVisibleTrees.size(); iRow++) {
        for (int iCol = 0; iCol < vVisibleTrees[iRow].size(); iCol++) {
            int tree = vVisibleTrees[iRow][iCol];
            if (tree >= 0) {
                cout << tree;
            } else {
                cout << "_";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Count number of visible trees
    int iNumVisible = 0;
    for(int iRow = 0; iRow < vVisibleTrees.size(); iRow++) {
        for (int iCol = 0; iCol < vVisibleTrees[iRow].size(); iCol++) {
            int tree = vVisibleTrees[iRow][iCol];
            if (tree >= 0) {
                iNumVisible++;
            }
        }
    }

    cout << "Number of visible trees: " << iNumVisible << endl << endl;

    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;


    // Put the trees into a 2d vector
    vTrees.clear();
    iCurRow = 0;

    // Run through each row
    for (string row : *pData) {

        vector<int> curRow;

        // Run through each column 
        for (int i = 0; i < row.size(); i++) {
            int v = row.at(i) - '0';
            curRow.push_back(v);
        }
        
        // Add the row to the tree
        vTrees.push_back(curRow);

        // Prepare data for the next row
        iCurRow++;
        curRow.clear();
    }

    // Print the map
    for(int iRow = 0; iRow < vTrees.size(); iRow++) {
        for (int iCol = 0; iCol < vTrees[iRow].size(); iCol++) {
            int tree = vTrees[iRow][iCol];
            if (tree >= 0) {
                cout << tree;
            } else {
                cout << "_";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Cycle through every tree and calculate it's potential 
    int iMaxScore = 0;

    for(int iRow = 0; iRow < vTrees.size(); iRow++) {
        for (int iCol = 0; iCol < vTrees[iRow].size(); iCol++) {

            // Skip borders, as their value will be 0
            if (!iRow || !iCol || iRow == vTrees.size()-1 || iCol == vTrees[iRow].size()-1 ) {
                continue;
            }

            // Grab the tree we're checking
            int tree = vTrees[iRow][iCol];

            // Calculate potential score
            int l = 0;
            int u = 0;
            int r = 0;
            int d = 0;
            int total = 0;
            
            // Part 1: Go left
            for (int i = iCol-1; i >= 0; i--) {
                l++;

                // Our tree is smaller, so we're stopped
                if (tree <= vTrees[iRow][i]) {
                    break;
                }
            }

            //cout << "Tree at: [" << iRow << ", " << iCol << "] - Value of: " << tree << " -  Left Visibility is: " << l << endl;

            // Part 2: Go up
            for (int i = iRow-1; i >= 0; i--) {
                u++;

                // Our tree is smaller, so we're stopped
                if (tree <= vTrees[i][iCol]) {
                    break;
                }
            }

            //cout << "Tree at: [" << iRow << ", " << iCol << "] - Value of: " << tree << " -  Up Visibility is: " << u << endl;

            // Part 3: Go right
            for (int i = iCol+1; i < vTrees[iRow].size(); i++) {
                r++;

                // Our tree is smaller, so we're stopped
                if (tree <= vTrees[iRow][i]) {
                    break;
                }
            }

            //cout << "Tree at: [" << iRow << ", " << iCol << "] - Value of: " << tree << " -  Right Visibility is: " << r << endl;

            // Part 4: Go down
            for (int i = iRow+1; i < vTrees.size(); i++) {
                d++;

                // Our tree is smaller, so we're stopped
                if (tree <= vTrees[i][iCol]) {
                    break;
                }
            }

            //cout << "Tree at: [" << iRow << ", " << iCol << "] - Value of: " << tree << " -  Down Visibility is: " << d << endl;

            // Part 5: CALCULATE result!
            total = l * u * r * d;

            // If we somehow got a zero
            if (!total) {
                continue;
            }

            cout << "Tree at: [" << iRow << ", " << iCol << "] - Value of: " << tree << " -  TOTAL Visibility is: " << total << endl;

            if (total > iMaxScore) {
                cout << "NEW HIGH SCORE: " << total << endl;
                iMaxScore = total;
            }
        }
    }

    cout << endl;
    cout << "MAX HIGH SCORE FOUND: " << iMaxScore;

    return 0;
}
