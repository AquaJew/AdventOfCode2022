#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include <cctype>
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
 
	return 0;
}

// searchUnique
// Search a string of variable length to find where the string becomes unique
int searchUnique(string sString, int iBitLength) {

	// We need to start a loop where we grab the first 4 characters and see if they are all unique
	for (int i = iBitLength; i < sString.size(); i++) {
		string s = sString.substr(i - iBitLength, iBitLength);
		cout << s << endl;

		// Sort the four chars and check for uniques
		sort(s.begin(), s.end());
		if (unique(s.begin(), s.end()) == s.end()) {
			return i;
		}
	}

	// If we didn't find anything
	return 0;
} 

/////////////////////////////////////////////////////////////////////////////////
// IMPORTED FUNCTIONS
/////////////////////////////////////////////////////////////////////////////////

// Trim a string front and back of white space
std::string trim(const std::string& str, const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

// Trimp a string front and back, AND trim the middle
std::string reduce(const std::string& str, const std::string& fill = " ", const std::string& whitespace = " \t")
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}
