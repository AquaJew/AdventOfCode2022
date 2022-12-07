#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

// HELPER FUNCTIONS

// getFileContent
// Get data from a file and put it into a dynamic vector, line by line
bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{

	// Open the File
	std::ifstream in(fileName.c_str());

	// Check if object is valid
	if(!in)
	{
		std::cerr << "Cannot open the File : "<<fileName<<std::endl;
		return false;
	}

	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(in, str))
	{
		// Pull everything, line by line, regardless of size and store as a string
		vecOfStrs.push_back(str);
	}
	//Close The File
	in.close();
	return true;
}

// getDayData
// Start the Day by setting the day variable, 
bool getDayData(vector<string> & vTestData, vector<string> & vData) {

	// Grab test data from file and fill test data vector
    bool result = getFileContent("testdata.txt", vTestData);
    if (!result) {
        cout << "EVERYTHING WENT WRONG WITH TESTDATA" << endl;
        return 1;
    }

	// Grab real data from file and fill real data vector
    bool result2 = getFileContent("data.txt", vData);

    if (!result2) {
        cout << "EVERYTHING WENT WRONG WITH DATA" << endl;
        return 1;
    }

    return 1;
}

// splitStringBy
// Split a string into parts and return the string result
bool splitStringBy(string sToSplit, string sDelimiter, vector<string> & vResult) {

    std::string token;
    std::stringstream ss(sToSplit);
    while (getline(ss, token, sDelimiter[0])){
        vResult.push_back(token);
    }

	return 1;
 
}



