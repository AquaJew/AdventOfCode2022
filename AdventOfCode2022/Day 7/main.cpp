// Includes
#include "../Helpers/helpers.h"
using namespace std;

// AOC Settings and Switches
int iDay            = 7;
bool bTestData      = true;
bool bDebug         = true;

// Data Variables
vector<string> vData;
vector<string> vTestData;
vector<string> *pData;

// Create a FileObject that we can use throughout the program
class fileObject {
    public:
        fileObject *parent;
        vector<fileObject *> children;
        string type;
        string name;
        int size;

        // Return a pointer to the correct object
        fileObject * findFolder(string folder) {
            for (fileObject *child : children) {
                if (child->name == folder && child->type == "dir") {
                    return child;
                }
            }

            // Didn't find the directory
            return NULL;
        }

        // Calculate my total size
        int getSize() {

            // We're going to run this every time, just in case files get added later
            int iSize = 0;

            // Go through all children
            for (fileObject *child : children) {

                // Recursively call get size
                if (child->type == "dir") {
                    iSize += child->getSize();
                
                // If the child is a file, add the amount
                } else {
                    iSize += child->size;
                }
            }

            // Set the file size for this directory and return it back out
            this->size = iSize;
            return iSize;
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
    std::cout << "/////////////////////////////////////////////////////////" << endl;
    std::cout << "// DAY " << iDay << endl;
    std::cout << "// ";
    (bTestData) ? std::cout << "TEST DATA IS: ON" << endl : std::cout << "TEST DATA IS: OFF" << endl;
    std::cout << "// ";
    (bDebug) ? std::cout << "DEBUG OUTPUT IS: ON" << endl : std::cout << "DEBUG OUTPUT IS: OFF" << endl;
    std::cout << "/////////////////////////////////////////////////////////" << endl;
    std::cout << endl;

    // point data based on debug
    pData = (bTestData) ? &vTestData : &vData;

    // **************************************************************************************************************
    // PREPARATION STEP 
    // DUMP RAW DATA AT THE TOP, RUN ADDITIONAL DEBUG/TEST DATA REVIEWS 
    // **************************************************************************************************************

    // Belch out Data
    if (bDebug) {
        std::cout << "--- DATA DUMP ---" << endl;
        for (string line : *pData) {
            std::cout << line << endl;
        }
        std::cout << "--- END OF DATA DUMP ---" << endl << endl;
    }

    // **************************************************************************************************************
    // BEGINNING DAY / OPENING 
    // RUN DAY 1.1 CALCULATIONS
    // **************************************************************************************************************

    std::cout << "/////////////////////////////////////////////////////////" << endl;
    std::cout << "// STARTING DAY " << iDay << ".1 CALCULATIONS..." << endl;
    std::cout << "/////////////////////////////////////////////////////////" << endl;
    std::cout << endl;

    // First, build the hierarchy into some form of array
    // Then, assign values to each direectory recursively
    // We should probably keep track of files to size
    // We probably need objects here with properties
    vector<string> vCommands;
    fileObject *pCurFolder = NULL;

    // Create a fileObject to hold everything
    fileObject root;

    // Go line by line to understand what's happening
    for (string line : *pData ) {

        // Explode the line into pieces to evaluate
        splitStringBy(line, " ", vCommands);

        // Check to see what was fired
        // If we found a command
        if (vCommands[0] == "$") {
            std::cout << "COMMAND was found!" << endl;

            // If we're going into a directory
            if (vCommands[1] == "cd") {
                std::cout << "We're changing directory to: " << vCommands[2] << endl;

                // Check if we're creating root
                if (pCurFolder == NULL) {
                    root.name = vCommands[2];
                    root.parent = NULL;
                    root.size = 0;
                    root.type = "dir";
                    pCurFolder = &root;
                    std::cout << "Creating ROOT" << endl;

                // Otherwise, check to see if the directory exists in THIS folder
                } else {
                    if (fileObject *p = pCurFolder->findFolder(vCommands[2])) {
                        pCurFolder = p;
                        std::cout << "WE WENT IN" << endl;
                    }
                }

            // If we're going into a directory
            } else if (vCommands[1] == "ls") {
                std::cout << "We need to look at the current directory" << endl;

            // Unknown command
            } else {
                std::cout << "ERROR: UNKNOWN COMMAND!" << endl;
            }


        // If we found a directory listing
        } else if (vCommands[0] == "dir") {
            std::cout << "DIRECTORY was found! - " << line << endl;

            // Create the directory and assign to the current directory

        // If it wasn't a command or directory, it was a file with a size
        } else {
            std::cout << "FILE was found! - " << line << endl;
        } 


        // Clear the command list to prepare for the next input
        vCommands.clear();
       std::cout << endl;

    }


    // **************************************************************************************************************
    // PART 2 DAY 
    // RUN DAY 1.2 CALCULATIONS
    // **************************************************************************************************************

    std::cout << "/////////////////////////////////////////////////////////" << endl;
    std::cout << "// STARTING DAY " << iDay << ".2 CALCULATIONS..." << endl;
    std::cout << "/////////////////////////////////////////////////////////" << endl;
    std::cout << endl;

    return 0;
}
