// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include <iostream>
#include <string>
#include <vector>

#include "fileio.h"
#include "src/cypher.h"

int main() 
{
	std::string uChoice = "0";
	std::string inFile = "";
	std::string outFile = "";

	// Loop for user input
	do
	{
		// Show menu
		std::cout << "Select an option:" << std::endl;
		std::cout << "\t0. Quit" << std::endl;
		std::cout << "\t1. Decrypt a file" << std::endl;
		std::cout << "\t2. Encrypt a file" << std::endl;
		std::cout << "> ";

		// Get input
		std::getline(std::cin, uChoice);

		if (uChoice == "0")
		{
			std::cout << "Quitting!" << std::endl;
			break;
		}
		else if (uChoice == "1")
		{
			// Get file names
			std::cout << "Enter the name of the encrypted file: ";
			std::getline(std::cin, inFile);
			std::cout << "Enter the name for the decrypted file: ";
			std::getline(std::cin, outFile);

			// Get input data
			std::vector<std::string> inputData;
			if (!getData(inFile, inputData))
			{
				// Wasn't able to open and read the input file
				std::cout << "Error: unable to open the file \"" << inFile << "\"!" << std::endl;
				continue;
			}

			// Get the cypher
			std::string cypher = inputData[0];

			// Prep the output
			std::vector<std::string> output;
			output.push_back(cypher);

			// Do the decryption
			for (int i = 1; i < inputData.size(); i++)
			{
				std::string outString;
				substitutionCypherDecrypt(cypher, inputData[i], outString);
				output.push_back(outString);
			}

			// Write the output to a file
			if (!putData(outFile, output))
			{
				// Wasn't able to open and read the input file
				std::cout << "Error: unable to write to the file \"" << outFile << "\"!" << std::endl;
				continue;
			}

			std::cout << "Done!" << std::endl << std::endl;
		}
		else if (uChoice == "2")
		{
			// Get file names
			std::cout << "Enter the name of the plain-text file: ";
			std::getline(std::cin, inFile);
			std::cout << "Enter the name for the encrypted file: ";
			std::getline(std::cin, outFile);

			// Get input data
			std::vector<std::string> inputData;
			if (!getData(inFile, inputData))
			{
				// Wasn't able to open and read the input file
				std::cout << "Error: unable to open the file \"" << inFile << "\"!" << std::endl;
				continue;
			}

			// Get the cypher
			std::string cypher = inputData[0];

			// Prep the output
			std::vector<std::string> output;
			output.push_back(cypher);

			// Do the encryption
			for (int i = 1; i < inputData.size(); i++)
			{
				std::string outString;
				substitutionCypherEncrypt(cypher, inputData[i], outString);
				output.push_back(outString);
			}

			// Write the output to a file
			if (!putData(outFile, output))
			{
				// Wasn't able to open and read the input file
				std::cout << "Error: unable to write to the file \"" << outFile << "\"!" << std::endl;
				continue;
			}

			std::cout << "Done!" << std::endl << std::endl;
		}

	} while (uChoice != "0");

	return 0;
}
