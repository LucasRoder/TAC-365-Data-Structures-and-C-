// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#include <iostream>
#include <vector>

#include "hero.h"

// Name:
//        loadHeroes
// Input:
//        1. A string (passed as constant reference) contining the file name to load
//        2. A vector of Hero pointers to be filled with the new heroes
// Output:
//        A boolean to indicate success or failure
// Side effects:
//        Dynamically creates new heroes and adds their memory addresses to the vector
// Summary:
//        Calls the hero constructor to make all the heros
bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector);

// Name:
//        fight
// Input:
//        1. An file to generate an input stream to pass to the other fight function
//        2. An file to generate an output stream to pass to the other fight function
//          3. An unsigned int to use as the random number generator seed
// Output:
//        An integer with the return code (0 for success)
// Side effects:
//        Calls other fight function that interacts with user
// Summary:
//        Generates input and output streams then calls the other fight function
int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed);


// Name:
//        fight
// Input:
//        1. An input stream to get user input from
//        2. An output stream to put user output to
//          3. An unsigned int to use as the random number generator seed
// Output:
//        An integer with the return code (0 for success)
// Side effects:
//        Interacts with user
// Summary:
//        After setting the std::srand with the seed, the ostream gets the menu
//          Function interacts with user through menu options until quit is selected
//          See the writeup for menu details and functionality
int fight(std::istream& input, std::ostream& output, unsigned seed);

// Name:
//        heroCombat
// Input:
//        1. A pointer to the first hero fighting
//        2. A pointer to the second hero fighting
//        3. An output stream to display the results of the fight
// Output:
//        None
// Summary:
//        Runs a full fight between two heroes round by round printing
//        each round's results until one heros health reaches 0
void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output);

// Name:
//        selectHero
// Input:
//        1. A vector of Hero pointers to choose from
//        2. A string with the prompt to show the user
//        3. An output stream to display the prompt on
//        4. An input stream to read the user's chosen index from
// Output:
//        A pointer to the Hero at the index the user picked
// Side effects:
//        Displays the prompt and any error messages to the output stream
// Summary:
//        Displays the prompt and keeps asking until the user enters a
//        valid in-range index then returns a pointer to that hero
Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in);
