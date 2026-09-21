#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "strlib.h"

#include "catch.hpp"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string &fileNameA,
							   const std::string &fileNameB);
extern std::string printStringVector(const std::vector<std::string> &input);

// Your tests -- only add sections
TEST_CASE("Student Tests", "[student]")
{
	SECTION("strSplit -- Bars|3")
	{
		std::string input = "Test1|Test2|Test3|Test4|Test5";
		std::vector<std::string> expectedOutput = {"Test1", "Test2", "Test3", "Test4", "Test5"};
		std::vector<std::string> studentOutput = strSplit(input, '|');

		if (expectedOutput != studentOutput)
		{
			std::stringstream ss;
			ss << "Splitting this \"" << input << "\" on '|' was incorrect" << std::endl;
			ss << "Should be\t" << printStringVector(expectedOutput) << std::endl;
			ss << "You gave\t" << printStringVector(studentOutput) << std::endl;
			FAIL(ss.str());
		}
	}
}
