// Includes
#include "../Helpers/helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 9;
bool bTestData      = false;
bool bDebug         = true;

// Data Variables
vector<string> vData;
vector<string> vTestData;
vector<string> *pData;

// Create knot object
class Knot {
    public:
        int x;
        int y;
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

    // Create the knots
    Knot head;
    Knot tail;
    head.x = 0;
    head.y = 0;
    tail.x = 0;
    tail.y = 0;

    // Need to keep track of all spots visited
    vector<Knot> vLocations;

    // Go through the commands
    for (string cmd : *pData) {

        // Commands are multistep, so create a secondary loop based on them
        vector<string> pair;
        splitStringBy(cmd, " ", pair);

        // Sorted and named and ready
        string dir = pair[0];
        int val = stoi(pair[1]);

        cout << "Will move: " << dir << ", " << val << " steps this round" << endl;

        // Go step by step through the command
        for (int i = 0; i < val; i++) {
            
            // Move H in either of 4 directions
            if (dir == "L") {
                // Left
                head.x--;
            } else if (dir == "U") {
                // Up
                head.y++;
            } else if (dir == "R") {
                // Right
                head.x++;
            } else if (dir == "D") {
                // Down
                head.y--;
            }

            // Head is 2 or greater to the right, but on the same column
            if (head.x - tail.x > 1 && head.y == tail.y) {
                tail.x++;   // Scoot right one

            // Head is 2 or greater to the left, but on the same column
            } else if (head.x - tail.x < -1 && head.y == tail.y) {
                tail.x--;   // scoot left one

            // Head is 2 or greater up, but on the same row
            } else if (head.x == tail.x && head.y - tail.y > 1) {
                tail.y++;

            // Head is 2 or greater down, but on the same row
            } else if (head.x == tail.x && head.y - tail.y < -1) {
                tail.y--;

            // Head is Up-Left of Tail                        // This part is ensuring we're not just diagonal
            } else if (head.x < tail.x && head.y > tail.y && (abs(head.x - tail.x) + abs(head.y - tail.y) > 2) ) {
                tail.x--;
                tail.y++;

            // Head is Up-Right of Tail                        // This part is ensuring we're not just diagonal
            } else if (head.x > tail.x && head.y > tail.y && (abs(head.x - tail.x) + abs(head.y - tail.y) > 2) ) {
                tail.x++;
                tail.y++;

            // Head is Down-Left of Tail                        // This part is ensuring we're not just diagonal
            } else if (head.x < tail.x && head.y < tail.y && (abs(head.x - tail.x) + abs(head.y - tail.y) > 2) ) {
                tail.x--;
                tail.y--;

            // Head is Down-Right of Tail                        // This part is ensuring we're not just diagonal
            } else if (head.x > tail.x && head.y < tail.y && (abs(head.x - tail.x) + abs(head.y - tail.y) > 2) ) {
                tail.x++;
                tail.y--;
            } 

            // Copy the tail's location into the tracer
            vLocations.push_back(tail);

            // Now check on the distance of Tail from Head
            int sum = 0;           
            sum = abs(head.x - tail.x) + abs(head.y - tail.y);
            if (sum > 1) {
                cout << "Head is currently " << sum << " steps away from Tail: ";
                cout << "Head is at: [" << head.x << ", " << head.y << "] ";
                cout << "and Tail is at: [" << tail.x << ", " << tail.y << "]" << endl;
            }
        }
    }

    cout << endl;

    // Start counting steps
    int steps = 0;

    // Examine all the spots visited
    for (Knot loc : vLocations) {
        steps++;
        cout << "Tail visited: [" << loc.x << ", " << loc.y << "]" << endl;
    }
    cout << "For a total of " << steps << " steps" << endl;
    cout << endl;

    // Need to weed out duplicates now
    for (int i = 0; i < vLocations.size(); i++ ) {

        // For each i, start at i+1 and search for duplicates to nuke
        for(int j = i + 1; j < vLocations.size(); j++ ) {
            if (vLocations[i].x == vLocations[j].x && vLocations[i].y == vLocations[j].y ) {

                // Kill the duplicate
                vLocations.erase(vLocations.begin() + j);

                // The index has shifted, so we need to re-examine this spot
                j--;
            }
        }
    }

    // Reset the step counter
    steps = 0;

    // Examine all the UNIQUE spots visited
    for (Knot loc : vLocations) {
        steps++;
        cout << "Tail visited ONCE: [" << loc.x << ", " << loc.y << "]" << endl;
    }
    cout << "For a total of " << steps << " steps" << endl;
    cout << endl;


    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    cout << "/////////////////////////////////////////////////////////" << endl;
    cout << endl;

    // Create the 10 knots
    vector<Knot> vRope;

    // Start the knots at the same spot
    for (int i = 0; i < 10; i++) {
        Knot k;
        k.x = 0;
        k.y = 0;

        vRope.push_back(k);
    }

    // Go line by line to start the motion
    // Need to keep track of all spots visited
    vLocations.clear();

    // Go through the commands
    for (string cmd : *pData) {

        // Commands are multistep, so create a secondary loop based on them
        vector<string> pair;
        splitStringBy(cmd, " ", pair);

        // Sorted and named and ready
        string dir = pair[0];
        int val = stoi(pair[1]);

        cout << "Will move: " << dir << ", " << val << " steps this round" << endl;

        // Go through the command step by step
        for (int i = 0; i < val; i++) {

            // Move HEAD vRope[0] in either of 4 directions
            if (dir == "L") {
                // Left
                vRope[0].x--;
            } else if (dir == "U") {
                // Up
                vRope[0].y++;
            } else if (dir == "R") {
                // Right
                vRope[0].x++;
            } else if (dir == "D") {
                // Down
                vRope[0].y--;
            }

            // Now, we need to cycle through the knots and carry out the effect
            for (int j = 1; j < vRope.size(); j++) {

                // Higher Knot is 2 or greater to the right, but on the same column
                if (vRope[j-1].x - vRope[j].x > 1 && vRope[j-1].y == vRope[j].y) {
                    vRope[j].x++;   // Scoot right one

                // Higher Knot is 2 or greater to the left, but on the same column
                } else if (vRope[j-1].x - vRope[j].x < -1 && vRope[j-1].y == vRope[j].y) {
                    vRope[j].x--;   // scoot left one

                // Higher Knot is 2 or greater up, but on the same row
                } else if (vRope[j-1].x == vRope[j].x && vRope[j-1].y - vRope[j].y > 1) {
                    vRope[j].y++;

                // Higher Knot is 2 or greater down, but on the same row
                } else if (vRope[j-1].x == vRope[j].x && vRope[j-1].y - vRope[j].y < -1) {
                    vRope[j].y--;

                // Higher Knot is Up-Left of Tail                        // This part is ensuring we're not just diagonal
                } else if (vRope[j-1].x < vRope[j].x && vRope[j-1].y > vRope[j].y && (abs(vRope[j-1].x - vRope[j].x) + abs(vRope[j-1].y - vRope[j].y) > 2) ) {
                    vRope[j].x--;
                    vRope[j].y++;

                // Head is Up-Right of Tail                        // This part is ensuring we're not just diagonal
                } else if (vRope[j-1].x > vRope[j].x && vRope[j-1].y > vRope[j].y && (abs(vRope[j-1].x - vRope[j].x) + abs(vRope[j-1].y - vRope[j].y) > 2) ) {
                    vRope[j].x++;
                    vRope[j].y++;

                // Head is Down-Left of Tail                        // This part is ensuring we're not just diagonal
                } else if (vRope[j-1].x < vRope[j].x && vRope[j-1].y < vRope[j].y && (abs(vRope[j-1].x - vRope[j].x) + abs(vRope[j-1].y - vRope[j].y) > 2) ) {
                    vRope[j].x--;
                    vRope[j].y--;

                // Head is Down-Right of Tail                        // This part is ensuring we're not just diagonal
                } else if (vRope[j-1].x > vRope[j].x && vRope[j-1].y < vRope[j].y && (abs(vRope[j-1].x - vRope[j].x) + abs(vRope[j-1].y - vRope[j].y) > 2) ) {
                    vRope[j].x++;
                    vRope[j].y--;
                } 

            } 

            // Copy the tail's location into the tracer
            vLocations.push_back(vRope[9]);

            // Now check on the distance of Tail from Head
            int sum = 0;           
            sum = abs(vRope[0].x - vRope[9].x) + abs(vRope[0].y - vRope[9].y);
            if (sum > 1) {
                cout << "Head is currently " << sum << " steps away from Tail: ";
                cout << "Head is at: [" << vRope[0].x << ", " << vRope[0].y << "] ";
                cout << "and Tail is at: [" << vRope[9].x << ", " << vRope[9].y << "]" << endl;
            }

        }

        cout << endl;

        // Showcase the position of the whole string
        for (int i = 0; i < vRope.size(); i++) {
            cout << "Knot " << i << " is at: [" << vRope[i].x << ", " << vRope[i].y << "]" << endl;
        }

        cout << endl;
    }

    // Start counting steps
    steps = 0;

    // Examine all the spots visited
    for (Knot loc : vLocations) {
        steps++;
        cout << "Tail visited: [" << loc.x << ", " << loc.y << "]" << endl;
    }
    cout << "For a total of " << steps << " steps" << endl;
    cout << endl;

    // Need to weed out duplicates now
    for (int i = 0; i < vLocations.size(); i++ ) {

        // For each i, start at i+1 and search for duplicates to nuke
        for(int j = i + 1; j < vLocations.size(); j++ ) {
            if (vLocations[i].x == vLocations[j].x && vLocations[i].y == vLocations[j].y ) {

                // Kill the duplicate
                vLocations.erase(vLocations.begin() + j);

                // The index has shifted, so we need to re-examine this spot
                j--;
            }
        }
    }

    // Reset the step counter
    steps = 0;

    // Examine all the UNIQUE spots visited
    for (Knot loc : vLocations) {
        steps++;
        cout << "Tail visited ONCE: [" << loc.x << ", " << loc.y << "]" << endl;
    }
    cout << "For a total of " << steps << " steps" << endl;
    cout << endl;



    return 0;
}
