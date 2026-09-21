#include <sstream>
#include <fstream>

#include "catch.hpp"

#include "fight.h"
#include "strlib.h"
#include "hero.h"
#include "powers.h"

// Helper function declarations (don't change these)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

extern std::string printStringVector(const std::vector<std::string>& input);


TEST_CASE("strlib.h/cpp tests", "[graded]")
{
    SECTION("strSplit -- Bars|2")
    {
        std::string input = "Test1|Test2|Test3|Test4|Test5";
        std::vector<std::string> output = { "Test1", "Test2", "Test3", "Test4", "Test5" };
		std::vector<std::string> studOutput = strSplit(input, '|');
        
        if (output != studOutput)
        {
            std::ostringstream ss;
            ss << "Splitting this \"" << input << "\" on '|' was incorrect." << std::endl;
			ss << "Should be\t" << printStringVector(output) << std::endl;
			ss << "You gave\t" << printStringVector(studOutput) << std::endl;
            FAIL(ss.str());
        }
    }

	SECTION("strSplit -- Commas|2")
	{
		std::string input = "Test1,Test2|Test3|Test4,Test5";
		std::vector<std::string> output = { "Test1", "Test2|Test3|Test4", "Test5" };
		std::vector<std::string> studOutput = strSplit(input, ',');

        if (output != studOutput)
        {
			std::ostringstream ss;
			ss << "Splitting this \"" << input << "\" on ',' was incorrect." << std::endl;
			ss << "Should be\t" << printStringVector(output) << std::endl;
			ss << "You gave\t" << printStringVector(studOutput) << std::endl;
			FAIL(ss.str());
        }
	}
	SECTION("strSplit -- Whitespace|2")
	{
		std::string input = "Test1 Test2    Test3   Test4 Test5";
		std::vector<std::string> output = { "Test1", "Test2", "", "", "", "Test3", "", "", "Test4", "Test5" };
		std::vector<std::string> studOutput = strSplit(input, ' ');

        if (output != studOutput)
        {
			std::ostringstream ss;
			ss << "Splitting this \"" << input << "\" on ' ' was incorrect." << std::endl;
			ss << "Should be\t" << printStringVector(output) << std::endl;
			ss << "You gave\t" << printStringVector(studOutput) << std::endl;
			FAIL(ss.str());
        }
	}
	SECTION("strSplit -- New Line, delim as last char|2")
	{
		std::string input = "Test1\nTest2\nTest3\n";
		// Last output item should be empty string when delim is last input char
        std::vector<std::string> output = { "Test1", "Test2", "Test3", "" };
		std::vector<std::string> studOutput = strSplit(input, '\n');

        if (output != studOutput)
        {
			std::ostringstream ss;
			ss << "Splitting this \"" << input << "\" on ' ' was incorrect." << std::endl;
			ss << "Should be\t" << printStringVector(output) << std::endl;
			ss << "You gave\t" << printStringVector(studOutput) << std::endl;
			FAIL(ss.str());
        }
	}
}

TEST_CASE("powers.h/cpp tests", "[graded]") 
{
	SECTION("Power factory and getting PowerIDs|13")
	{
		std::vector<std::string> input = { "laser", "national", "strength", "intel", "gadget", "flight"};
        std::vector<POWER_ID> output = { POWER_LASER, POWER_NATIONAL, POWER_STRENGTH, POWER_INTEL, POWER_GADGETS, POWER_FLIGHT };
        
        for (int i = 0; i < input.size(); i++)
        {
            Power* tempPower = powerFactory(input[i]);
			auto tempPowID = tempPower->getID();
            if (output[i] != tempPowID)
            {
				std::stringstream ss;
				ss << "Power \"" << input[i] << "\" does not give the right POWER_ID from powerFactory ";
				ss << "calling powerFactory(\"" << input[i] << "\")->getID()";
				ss << " should be " << output[i] << " you gave " << tempPowID;
				ss << " but as a POWER_ID enum.";
				auto sss = ss.str();
				FAIL(ss.str());
            }
            
			// We'll cover destructors later
            delete tempPower;
        }
	}

	SECTION("Power factory and Power/Power fight results|36")
	{
		std::vector<std::string> input = { "flight", "gadget", "intel", "laser", "national", "strength" };
        std::vector<std::vector<int>> output = {{ 0, -1,  1, -1,  1,  1},       // flight row:      0	G	F	L	F	F
                                                { 1,  0, -1,  1,  1, -1},       // gadgets row:     G	0	I	G	G	S
                                                {-1,  1,  0, -1,  1,  1},       // intel row:       F	I	0	L	I	I
                                                { 1, -1,  1,  0,  1, -1},       // laser row:       L	G	L	0	L	S
                                                {-1, -1, -1, -1,  0, -1},       // national row:    F	G	I	L	0	S
                                                {-1,  1, -1,  1,  1,  0} };     // str row:         F	S	I	S	S	0
		for (int i = 0; i < input.size(); i++)
		{
            // Create the power to test
			Power* leftPower = powerFactory(input[i]);
            
            // Create all the right side powers
            for (int j = 0; j < input.size(); j++)
            {
                Power* rightPower = powerFactory(input[j]);
                
                // Ignore temp
                std::string temp;
				
                if (output[i][j] != leftPower->fight(rightPower))
                {
					std::stringstream ss;
					ss << "When fighting \"" << input[i] << "\" against \""  << input[j] << "\" ";
                    ss << "should be " << output[i][j] << " you gave " << leftPower->fight(rightPower);
					FAIL(ss.str());
                }

                
                // We'll cover destructors later
                delete rightPower;
            }
            // We'll cover destructors later
			delete leftPower;
	    }
	}
}

TEST_CASE("hero.h/cpp tests", "[graded]") 
{
    SECTION("Hero create and member functions (except stream output)|3")
    {
		{
			std::string heroString = "Nathan Greenfield|intel,gadget|5";
			Hero myHero(heroString);

			// Check name
			if (myHero.getName() != "Nathan Greenfield")
			{
				std::stringstream ss;
				ss << "Hero made from \"" << heroString << "\" name should be "
					<< " Nathan Greenfield" << ", not \"" << myHero.getName() << "\"" << std::endl;
				FAIL(ss.str());
			}

			// Check health
			if (myHero.getHealth() != 5)
			{
				std::stringstream ss;
				ss << "Hero made from \"" << heroString << "\" health should be "
					<< " 5 " << ", not \"" << myHero.getHealth() << "\"" << std::endl;
				FAIL(ss.str());
			};

			// Check take damage
			myHero.takeDamage();
			if (myHero.getHealth() != 4)
			{
				std::stringstream ss;
				ss << "After taking damage, health should be 4, not "
					<< myHero.getHealth() << std::endl;
				FAIL(ss.str());
			}

			// Check reset
			myHero.resetHealth();
			if (myHero.getHealth() != 5)
			{
				std::stringstream ss;
				ss << "After resetting health it should be 5, not "
					<< myHero.getHealth() << std::endl;
				FAIL(ss.str());
			}
		}
    }

	SECTION("Hero output function (with pointers)|3")
	{
		{
			std::string heroString = "Inspector Gadget|gadget,laser,flight|4";
			Hero* myHero = new Hero(heroString);

			// Check print output
			std::stringstream ss;
			ss << *myHero;

			// Break up output
			std::vector<std::string> brokenOutput = strSplit(ss.str(), '\n');

			// Check number of lines
			if (brokenOutput.size() != 5)
			{
				std::stringstream ss;
				ss << "Hero made from \"" << heroString << "\" printed "
					<< brokenOutput.size() << " lines, not 5 lines." << std::endl;
				FAIL(ss.str());
			}

			// Get expected output
			std::stringstream testOut;
			testOut << "Inspector Gadget has the following powers..." << std::endl;
			testOut << "\t" << GadgetPower() << std::endl;
			testOut << "\t" << LaserPower() << std::endl;
			testOut << "\t" << FlightPower() << std::endl;
			testOut << std::endl;

			// Break up output
			std::vector<std::string> expectedOutput = strSplit(testOut.str(), '\n');

			// Check line 0...
			for (int i = 0; i < brokenOutput.size(); i++)
			{
				std::string templine;
				std::getline(ss, templine);

				if (brokenOutput[i] != expectedOutput[i])
				{
					std::stringstream msg;
					msg << "Expected: \"" << expectedOutput[i] << "\"\n"
						<< "Got: \"" << brokenOutput[i] << "\"";
					FAIL(msg.str());
				}
			}

			delete myHero;
			myHero = nullptr;
		}
	}
}

TEST_CASE("fight.h/cpp tests", "[graded]")
{
	SECTION("Load heroes test|2")
	{
		{
			std::vector<Hero*> hVec;

			// Load special input file
			loadHeroes("input/testHeroes01.txt", hVec);

			// Check that all 3 heroes loaded
			if (hVec.size() != 3)
			{
				std::stringstream ss;
				ss << "There should be 3 heroes loaded, you got " << hVec.size();
				FAIL(ss.str());
			}

			// Check Nathan
			if ((hVec[0]->getName() != "Nathan Greenfield") || (hVec[0]->getHealth() != 3))
			{
				std::stringstream ss;
				ss << "This hero should be \"Nathan Greenfield\", not " << hVec[0]->getName();
				FAIL(ss.str());
			}

			// Check Joseph
			if ((hVec[1]->getName() != "Joseph Greenfield") || (hVec[1]->getHealth() != 4))
			{
				std::stringstream ss;
				ss << "This hero should be \"Joseph Greenfield\", not " << hVec[1]->getName();
				FAIL(ss.str());
			}

			// Check Sanjay
			if ((hVec[2]->getName() != "Sanjay Madhav") || (hVec[2]->getHealth() != 5))
			{
				std::stringstream ss;
				ss << "This hero should be \"Sanjay Madhav\", not " << hVec[2]->getName();
				FAIL(ss.str());
			}

			for (int i = 0; i < hVec.size(); i++)
			{
				delete hVec[i];
				hVec[i] = nullptr;
			}
		}
	}

	SECTION("Hero combat|10")
	{
		{
			std::vector<Hero*> hVec;

			// Load special input file
			loadHeroes("input/testHeroes02.txt", hVec);

			std::stringstream ss;

			// Test Mighty Mouse winning!
			heroCombat(hVec[0], hVec[1], ss);
			std::vector<std::string> output = strSplit(ss.str(), '\n');

			//std::cout << output[output.size() - 2] << std::endl;

			if (output[output.size() - 2].find("Inspector Gadget WINS") == std::string::npos)
			{
				std::stringstream ss;
				ss << "Check your hero combat, Inspector Gadget should win here!" << std::endl;
				ss << "You said: " << output[output.size() - 2] << std::endl;
				FAIL(ss.str());
			}

			// Test Mighty Mouse winning!
			heroCombat(hVec[1], hVec[2], ss);
			output = strSplit(ss.str(), '\n');

			if (output[output.size() - 2].find("Inspector Gadget WINS") == std::string::npos)
			{
				std::stringstream ss;
				ss << "Check your hero combat, Inspector Gadget should win here!";
				ss << "You said: " << output[output.size() - 2] << std::endl;
				FAIL(ss.str());
			}

			for (Hero*& hp : hVec)
			{
				delete hp;
			}
		}
	}

	SECTION("Test fight 01|5")
	{
		fight("input/testInput01.txt", "output/output01.txt", 946684800);
		bool result = false;

		std::string studentOutputFileName = "output/output01.txt";
		std::string expectedOutputFileName = "expected/output01.txt";
		std::vector<std::string> studentOutput;
		std::vector<std::string> expectedOutput;

		// Get vector of expected output
		std::ifstream expectedOutputFile(expectedOutputFileName);
		
		if (!expectedOutputFile.is_open())
		{
			std::stringstream ss;
			ss << "Unable to open file named: " << expectedOutputFileName << std::endl;
			FAIL(ss.str());
		}

		while (!expectedOutputFile.eof())
		{
			std::string temp;
			std::getline(expectedOutputFile, temp);
			expectedOutput.push_back(temp);
		}


		// Get vector of student output
		std::ifstream studentOutputFile(studentOutputFileName);

		if (!studentOutputFile.is_open())
		{
			std::stringstream ss;
			ss << "Unable to open file named: " << studentOutputFileName << std::endl;
			FAIL(ss.str());
		}

		while (!studentOutputFile.eof())
		{
			std::string temp;
			std::getline(studentOutputFile, temp);
			studentOutput.push_back(temp);
			//std::cout << temp << std::endl;
		}

		if (studentOutput.size() != expectedOutput.size())
		{
			std::stringstream ss;
			ss << "You generated " << studentOutput.size() << " lines." << std::endl;
			ss << "I generated  " << expectedOutput.size() << " lines." << std::endl;
			FAIL(ss.str());
		}

		for (unsigned i = 0; i < expectedOutput.size(); i++)
		{
			if (expectedOutput[i][0] != '*')
			{
				if (studentOutput[i] != expectedOutput[i])
				{
					std::stringstream ss;
					ss << "On line #" << i + 1 << "..." << std::endl;
					ss << "You generated \"" << studentOutput[i] << "\"" << std::endl;
					ss << "I generated  \"" << expectedOutput[i] << "\"" << std::endl;
					FAIL(ss.str());
				}
			}
		}
	}

	SECTION("Test fight 01 -- with different seed|5")
	{
		fight("input/testInput01.txt", "output/output02.txt", 946684805);

		std::string studentOutputFileName = "output/output02.txt";
		std::string expectedOutputFileName = "expected/output02.txt";
		std::vector<std::string> studentOutput;
		std::vector<std::string> expectedOutput;

		// Get vector of expected output
		std::ifstream expectedOutputFile(expectedOutputFileName);

		if (!expectedOutputFile.is_open())
		{
			std::stringstream ss;
			ss << "Unable to open file named: " << expectedOutputFileName << std::endl;
			FAIL(ss.str());
		}

		while (!expectedOutputFile.eof())
		{
			std::string temp;
			std::getline(expectedOutputFile, temp);
			expectedOutput.push_back(temp);
		}


		// Get vector of student output
		std::ifstream studentOutputFile(studentOutputFileName);

		if (!studentOutputFile.is_open())
		{
			std::stringstream ss;
			ss << "Unable to open file named: " << studentOutputFileName << std::endl;
			FAIL(ss.str());
		}

		while (!studentOutputFile.eof())
		{
			std::string temp;
			std::getline(studentOutputFile, temp);
			studentOutput.push_back(temp);
			//std::cout << temp << std::endl;
		}

		if (studentOutput.size() != expectedOutput.size())
		{
			std::stringstream ss;
			ss << "You generated " << studentOutput.size() << " lines." << std::endl;
			ss << "I generated  " << expectedOutput.size() << " lines." << std::endl;
			FAIL(ss.str());
		}

		for (unsigned i = 0; i < expectedOutput.size(); i++)
		{
			if (expectedOutput[i][0] != '*')
			{
				if (studentOutput[i] != expectedOutput[i])
				{
					std::stringstream ss;
					ss << "On line #" << i + 1 << "..." << std::endl;
					ss << "You generated \"" << studentOutput[i] << "\"" << std::endl;
					ss << "I generated  \"" << expectedOutput[i] << "\"" << std::endl;
					FAIL(ss.str());
				}
			}
		}
	}

	SECTION("Test fight 02|5")
	{
		fight("input/testInput02.txt", "output/output03.txt", 946684800);

		std::string studentOutputFileName = "output/output03.txt";
		std::string expectedOutputFileName = "expected/output03.txt";
		std::vector<std::string> studentOutput;
		std::vector<std::string> expectedOutput;

		// Get vector of expected output
		std::ifstream expectedOutputFile(expectedOutputFileName);

		if (!expectedOutputFile.is_open())
		{
			std::stringstream ss;
			ss << "Unable to open file named: " << expectedOutputFileName << std::endl;
			FAIL(ss.str());
		}

		while (!expectedOutputFile.eof())
		{
			std::string temp;
			std::getline(expectedOutputFile, temp);
			expectedOutput.push_back(temp);
		}


		// Get vector of student output
		std::ifstream studentOutputFile(studentOutputFileName);

		if (!studentOutputFile.is_open())
		{
			std::stringstream ss;
			ss << "Unable to open file named: " << studentOutputFileName << std::endl;
			FAIL(ss.str());
		}

		while (!studentOutputFile.eof())
		{
			std::string temp;
			std::getline(studentOutputFile, temp);
			studentOutput.push_back(temp);
			//std::cout << temp << std::endl;
		}

		if (studentOutput.size() != expectedOutput.size())
		{
			std::stringstream ss;
			ss << "You generated " << studentOutput.size() << " lines." << std::endl;
			ss << "I generated  " << expectedOutput.size() << " lines." << std::endl;
			FAIL(ss.str());
		}

		for (unsigned i = 0; i < expectedOutput.size(); i++)
		{
			if (expectedOutput[i][0] != '*')
			{
				if (studentOutput[i] != expectedOutput[i])
				{
					std::stringstream ss;
					ss << "On line #" << i + 1 << "..." << std::endl;
					ss << "You generated \"" << studentOutput[i] << "\"" << std::endl;
					ss << "I generated  \"" << expectedOutput[i] << "\"" << std::endl;
					FAIL(ss.str());
				}
			}
		}
	}

	SECTION("Test fight 02 -- with different seed|5")
	{
		fight("input/testInput02.txt", "output/output04.txt", 777777777);

		std::string studentOutputFileName = "output/output04.txt";
		std::string expectedOutputFileName = "expected/output04.txt";
		std::vector<std::string> studentOutput;
		std::vector<std::string> expectedOutput;

		// Get vector of expected output
		std::ifstream expectedOutputFile(expectedOutputFileName);

		if (!expectedOutputFile.is_open())
		{
			std::stringstream ss;
			ss << "Unable to open file named: " << expectedOutputFileName << std::endl;
			FAIL(ss.str());
		}

		while (!expectedOutputFile.eof())
		{
			std::string temp;
			std::getline(expectedOutputFile, temp);
			expectedOutput.push_back(temp);
		}


		// Get vector of student output
		std::ifstream studentOutputFile(studentOutputFileName);

		if (!studentOutputFile.is_open())
		{
			std::stringstream ss;
			ss << "Unable to open file named: " << studentOutputFileName << std::endl;
			FAIL(ss.str());
		}

		while (!studentOutputFile.eof())
		{
			std::string temp;
			std::getline(studentOutputFile, temp);
			studentOutput.push_back(temp);
			//std::cout << temp << std::endl;
		}

		if (studentOutput.size() != expectedOutput.size())
		{
			std::stringstream ss;
			ss << "You generated " << studentOutput.size() << " lines." << std::endl;
			ss << "I generated  " << expectedOutput.size() << " lines." << std::endl;
			FAIL(ss.str());
		}

		for (unsigned i = 0; i < expectedOutput.size(); i++)
		{
			if (expectedOutput[i][0] != '*')
			{
				if (studentOutput[i] != expectedOutput[i])
				{
					std::stringstream ss;
					ss << "On line #" << i + 1 << "..." << std::endl;
					ss << "You generated \"" << studentOutput[i] << "\"" << std::endl;
					ss << "I generated  \"" << expectedOutput[i] << "\"" << std::endl;
					FAIL(ss.str());
				}
			}
		}
	}

}