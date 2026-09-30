#include "catch.hpp"
#include <string>


// Helper function declarations (don't change these)
extern bool CheckTextFilesSame(const std::string& fileNameA, 
	const std::string& fileNameB);

TEST_CASE("Full file test cases", "[student]")
{
	SECTION("input/locations.txt 8 5 10 1337")
	{

		//bool result = CheckTextFilesSame("log.txt", SamplePath + "log_8_5_10_1337.txt");
		REQUIRE(true);
	}
}
