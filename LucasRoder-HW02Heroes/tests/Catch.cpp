// Copyright �2023 Nathan Greenfield. All rights reserved

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
// #include "catch_reporter_github.hpp"

#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

// Name:
//		printStringVector
// Input:
//		1. input: The vector of strings to print
// Output:
//		a string in the format { item1, item2 }
// Side effects:
// 		None
// Summary:
//		Converts a vector of strings to a
//      single formatted string for debug output.
//		Note: This implementation is not most effcient,
//		but very readable vs alternatives.
std::string printStringVector(const std::vector<std::string> &input)
{
	std::ostringstream ss; // only outputting to this string
	bool firstRun = true;  // init first run per input vector
	ss << "{ ";			   // add this for formatting to denote a vector start
	// For each string s in vector of strings input
	for (std::string s : input) 
	{
		// To avoid a trailing comma delimiter,
		// prepend it to all but first
		if (!firstRun)
		{
			ss << ", "; // prepend comma delimiter
		}
		firstRun = false; // not efficient but very readable vs alts
		ss << s;		  // write item as string to output
	}
	ss << " }";		 // add this for formatting to denote a vector end
	return ss.str(); // return ss as a str value, rely on RVO
}

// Name:
//		CheckTextFilesSame
// Input:
//		1. The first file name to check
//		2. The second file name to check
// Output:
//		Boolean -- true indicates files are the same
// Side effects:
//		Creates system command (based on host OS) and runs system command to check files
// Summary:
//		Uses system native command to check for differences between 2 files
//		Uses C++ #defines to determine host OS
bool CheckTextFilesSame(const std::string &fileNameA, const std::string &fileNameB)
{
	// This is super unfortunate that I'm using std::system, but...
	std::string command;

#ifdef _MSC_VER
	// Windows version needs to fix separators on 1st input (so forward slash becomes backslash)
	std::string temp = fileNameA;
	std::replace(temp.begin(), temp.end(), '/', '\\');
	command = "FC /W /LB5 " + temp + " " + fileNameB;

#elif __APPLE__
	// Mac version needs no change
	command = "diff -sBbu " + fileNameA + " " + fileNameB + " > diff.txt";

#else
	// Linux version, just in case the Mac one becomes different
	command = "diff -sBbu " + fileNameA + " " + fileNameB + " > diff.txt";
#endif

	// Run the command we just constructed
	int retVal = std::system(command.c_str());

#if !defined(_MSC_VER)
	// Non Windows needs to add up to 50 lines of diff output, so we know the difference
	std::system("head -50 diff.txt");
#endif

	// If there were 0 differences, indicate true
	return retVal == 0;
}
