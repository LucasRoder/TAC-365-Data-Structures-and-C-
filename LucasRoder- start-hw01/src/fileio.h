// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#pragma once

#include <string>
#include <vector>

// Name: 
//		getData
// Input:
//		1. A string (passed as constant reference) contining the input file name
//		2. A string vector (passed by reference) that will eventually contain the file contents
// Output: 
//		Boolean -- true indicating success
// Side effects: 
//		Reads the input file
// Summary:
//		Reads in a text file and copies data into string vector
//		Each line of text becomes 1 item in the vector
bool getData(const std::string& inputLocation, std::vector<std::string>& data);


// Name: 
//		putData
// Input:
//		1. A string (passed as constant reference) contining the output file name
//		2. A string vector (passed as constant reference) with the data to write
// Output: 
//		Boolean -- true indicating success
// Side effects: 
//		Creates (or overwrites) the output file with the vector's contents
// Summary:
//		Using the vector of strings creates a new file with the vector's contents
//		Each item in the vector becomes a line of text
bool putData(const std::string& outputLocation, const std::vector<std::string>& data);

