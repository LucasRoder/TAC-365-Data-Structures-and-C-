// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#pragma once

#include <string>

// Name: 
//		substitutionCypherEncrypt
// Input:
//		1. A string (passed as constant reference) contining the cipher
//		2. A string (passed as constant reference) containing the text to encrypt
//		3. A string (passed by reference) that will eventually contain the encrypted text
// Output: 
//		None
// Side effects: 
//		None
// Summary:
//		Uses the inputted cipher to encrypt the inputted clear-text
//		Results go into 3rd argument
void substitutionCypherEncrypt(const std::string& cypher, const std::string& input, std::string& output);

// Name: 
//		substitutionCypherDecrypt
// Input:
//		1. A string (passed as constant reference) contining the cipher
//		2. A string (passed as constant reference) containing the text to decrypt
//		3. A string (passed by reference) that will eventually contain the decrypt text
// Output: 
//		None
// Side effects: 
//		None
// Summary:
//		Uses the inputted cipher to decrypted the inputted cipher-text
//		Results go into 3rd argument
void substitutionCypherDecrypt(const std::string& cypher, const std::string& input, std::string& output);

// Name: 
//		getLetterIndex
// Input:
//		1. A string containing a mixed-up alphabet
//		2. A character indicating the item to find in the alphabet
// Output: 
//		Integer -- indicating the index the character was found at
//				   Or -1 to indicate the item wasn't found
// Side effects: 
//		None
// Summary:
//		Searches through inputted string for the index of the inputted character
//		Returns either the index or -1 to indicate failure
int getLetterIndex(const std::string& input, const char letter);

