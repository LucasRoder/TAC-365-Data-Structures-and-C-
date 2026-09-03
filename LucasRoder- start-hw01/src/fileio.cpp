#include "fileio.h"

#include <fstream>

// Read in a file and return a vector of strings (requires input location of read file and vector that will store text)
bool getData(const std::string& inputLocation, std::vector<std::string>& data)
{
    std::ifstream inFile(inputLocation); // lets you read from a file

    if (!inFile.is_open()){ // if cant open file
        return false;
    }

    std::string line;
    while (std::getline(inFile, line)){
        data.push_back(line); // puts into data vector
    }

    inFile.close(); // closes file
    return true;

}

// Output the vector of strings to the file needs (print file location and string of data that will be printed)
bool putData(const std::string& outputLocation, const std::vector<std::string>& data)
{
    std::ofstream outFile(outputLocation); // lets you write too a file / create file

    if (!outFile.is_open()){ // checks if file could be opened/ created
        return false;
    }

    for (const std::string& line : data){ // loops over each string line in vector
        outFile << line << "\n"; //writes line then new line in file
    }

    outFile.close();
    return true;
}
