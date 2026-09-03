// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "catch.hpp"
#include "fileio.h"
#include "../src/cypher.h"

// Helper function declarations (don't change these)
extern bool CheckTextFilesSame(const std::string& fileNameA,
    const std::string& fileNameB);

// Input file names
static std::vector<std::string> inFileNames = { "input/simple-clear.txt",
"input/simple-enc.txt" , "input/letter1-clear.txt" , "input/letter1-enc.txt" ,
"input/letter2-clear.txt" , "input/letter2-enc.txt" , "input/letter3-clear.txt" ,
"input/letter3-enc.txt" };

// Output file names
static std::vector<std::string> outFileNames = { "output/simple-clear.txt",
    "output/simple-enc.txt" , "output/letter1-clear.txt" , "output/letter1-enc.txt" ,
    "output/letter2-clear.txt" , "output/letter2-enc.txt" , "output/letter3-clear.txt" ,
    "output/letter3-enc.txt" };

TEST_CASE("Checking file functions (fileio.cpp)", "[graded]")
{
    // Test readData function
    SECTION("Checking file reading. getData() |16")
    {

        for (std::string fileName : inFileNames)
        {
            // A place to store the data
            std::vector<std::string> myData;

            // Open the file
            std::ifstream inputFile(fileName);

            // Check that the file opened successfully
            if (!inputFile.is_open())
            {
                WARN("Couldn't open the file \"" << fileName << "\"!");
            }

            // Put the data into the vector
            while (!inputFile.eof())
            {
                std::string line;
                std::getline(inputFile, line);
                myData.push_back(line);
            }

            // Close the file
            inputFile.close();

            // Student data
            std::vector<std::string> studData;
            getData(fileName, studData);

            // Check that vectors are the same length
            if (myData.size() != studData.size())
            {
                WARN("For file \"" << fileName << "\", number of lines is incorrect!");
            }
            REQUIRE(myData.size() == studData.size());

            // Check the lines in the two vectors
            for (unsigned i = 0; i < myData.size(); i++)
            {
                if (myData[i] != studData[i])
                {
                    WARN("For file \"" << fileName << "\", a line did not match!");
                    WARN("Got \"" << studData[i] << "\"!");
                    WARN("Expected \"" << myData[i] << "\"!");
                }
                REQUIRE(myData[i] == studData[i]);
            }
        }
    }

    // Test putData function
    SECTION("Checking file writing. putData() |16")
    {
        for (unsigned i = 0; i < inFileNames.size(); i++)
        {
            // A place to store the data
            std::vector<std::string> readData;

            // Open the file
            std::ifstream inputFile(inFileNames[i]);

            // Check that the file opened successfully
            if (!inputFile.is_open())
            {
                WARN("Couldn't open the file \"" << inFileNames[i] << "\"!");
            }

            // Put the data into the vector
            while (!inputFile.eof())
            {
                std::string line;
                std::getline(inputFile, line);
                readData.push_back(line);
            }

            // Close the file
            inputFile.close();

            // Write file
            bool result = putData(outFileNames[i], readData);
            if (!result)
            {
                WARN("putData returned false for file \"" << outFileNames[i] << "\"!");
            }
            REQUIRE(result);

            result = CheckTextFilesSame(inFileNames[i], outFileNames[i]);
            if (!result)
            {
                WARN("Output for file \"" << inFileNames[i] << "\" is incorrect!");
            }
            REQUIRE(result);
        }
    }
}


TEST_CASE("Checking cipher functions (cypher.cpp)", "[graded]")
{
    SECTION("Decrypt -- check all files|20")
    {
        for (unsigned i = 0; i < inFileNames.size(); i += 2)
        {
            // Get file names
            std::string clearFileName = inFileNames[i];
            std::string encFileName = inFileNames[i + 1];

            // Setup data
            std::vector<std::string> clearFileData, encFileData;

            // Read in clear-text file
            bool result = getData(clearFileName, clearFileData);
            if (!result)
            {
                WARN("Problem reading the file \"" << clearFileName << "\"!");
            }
            REQUIRE(result);

            // Read in encrypted data
            result = getData(encFileName, encFileData);
            if (!result)
            {
                WARN("Problem reading the file \"" << encFileName << "\"!");
            }
            REQUIRE(result);

            result = encFileData.size() > 0;
            if (!result)
            {
                WARN("File read 0 lines \"" << encFileName << "\"!");
            }
            REQUIRE(result);

            // Check for successful decrypt
            for (unsigned j = 1; j < encFileData.size(); j++)
            {
                // Do student decrypt
                std::string studOutput;
                substitutionCypherDecrypt(encFileData[0], encFileData[j], studOutput);

                result = clearFileData[j] == studOutput;
                if (!result)
                {
                    WARN("Decryption was incorrect for line \"" << encFileData[j] << "\"!");
                    WARN("File \"" << clearFileName << "/");
                    WARN("Got \"" << studOutput << "\"!");
                    WARN("Expected \"" << clearFileData[j] << "\"!");
                }
                REQUIRE(result);
            }
        }
    }


    SECTION("Encrypt -- check all files|20")
    {
        for (unsigned i = 0; i < inFileNames.size(); i += 2)
        {
            // Get file names
            std::string clearFileName = inFileNames[i];
            std::string encFileName = inFileNames[i + 1];

            // Setup data
            std::vector<std::string> clearFileData, encFileData;

            // Read in clear-text file
            bool result = getData(clearFileName, clearFileData);
            if (!result)
            {
                WARN("Problem reading the file \"" << clearFileName << "\"!");
            }
            REQUIRE(result);

            // Read in encrypted data
            result = getData(encFileName, encFileData);
            if (!result)
            {
                WARN("Problem reading the file \"" << encFileName << "\"!");
            }
            REQUIRE(result);

            result = clearFileData.size() > 0;
            if (!result)
            {
                WARN("File read 0 lines \"" << clearFileName << "\"!");
            }
            REQUIRE(result);

            // Check for successful encrypt
            for (unsigned j = 1; j < clearFileData.size(); j++)
            {
                // Do student encrypt
                std::string studOutput;
                substitutionCypherEncrypt(clearFileData[0], clearFileData[j], studOutput);

                result = encFileData[j] == studOutput;
                if (!result)
                {
                    WARN("Encryption was incorrect for line \"" << clearFileData[j] << "\"!");
                }
                REQUIRE(result);
            }
        }
    }
}

TEST_CASE("End to end tests", "[graded]")
{
    SECTION("Encrypt -- end to end|9")
    {
        for (unsigned i = 0; i < inFileNames.size(); i += 2)
        {
            // Get file names
            std::string clearFileName = inFileNames[i];
            std::string outFileName = outFileNames[i + 1];
            std::string correctFileName = inFileNames[i + 1];

            // Get input data
            std::vector<std::string> inputData;
            bool result = getData(clearFileName, inputData);
            if (!result)
            {
                WARN("getData(): Problem reading the file \"" << clearFileName << "\"!");
            }
            REQUIRE(result);

            // Get the cypher
            std::string cypher = inputData[0];

            // Prep the output
            std::vector<std::string> output;
            output.push_back(cypher);

            // Do the encryption
            for (int j = 1; j < inputData.size(); j++)
            {
                std::string outString;
                substitutionCypherEncrypt(cypher, inputData[j], outString);
                output.push_back(outString);
            }

            // Write file
            result = putData(outFileName, output);
            if (!result)
            {
                WARN("putData returned false for file \"" << outFileName << "\"!");
            }
            REQUIRE(result);

            result = CheckTextFilesSame(outFileName, correctFileName);
            if (!result)
            {
                WARN("Output for file \"" << outFileName << "\" is incorrect!");
            }
            REQUIRE(result);
        }
    }

    SECTION("Decrypt -- end to end|9")
    {
        for (unsigned i = 0; i < inFileNames.size(); i += 2)
        {
            // Get file names
            std::string encFileName = inFileNames[i + 1];
            std::string outFileName = outFileNames[i];
            std::string correctFileName = inFileNames[i];

            // Get input data
            std::vector<std::string> inputData;
            bool result = getData(encFileName, inputData);
            if (!result)
            {
                WARN("getData(): Problem reading the file \"" << encFileName << "\"!");
            }
            REQUIRE(result);

            // Get the cypher
            std::string cypher = inputData[0];

            // Prep the output
            std::vector<std::string> output;
            output.push_back(cypher);

            // Do the decryption
            for (int j = 1; j < inputData.size(); j++)
            {
                std::string outString;
                substitutionCypherDecrypt(cypher, inputData[j], outString);
                output.push_back(outString);
            }

            // Write file
            result = putData(outFileName, output);
            if (!result)
            {
                WARN("putData returned false for file \"" << outFileName << "\"!");
            }
            REQUIRE(result);

            result = CheckTextFilesSame(outFileName, correctFileName);
            if (!result)
            {
                WARN("Output for file \"" << outFileName << "\" is incorrect!");
            }
            REQUIRE(result);

        }
    }
}





