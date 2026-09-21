#include "fight.h"
#include <fstream>
#include <cstdlib>

bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector)
{
	// if the vector already has heroes in it delete otherwise we'd leak that memory
	for (int i = 0; i < heroVector.size(); i++)
	{
		delete heroVector[i];
	}
	heroVector.clear();

	// if we cant open file return false
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		return false;
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		// if file has blank line skip 
		if (line.empty())
		{
			continue;
		}
		// creates hero with constructor 
		heroVector.push_back(new Hero(line));
	}


	inputFile.close();
	return true;
}

Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in)
{
	int index = -1;

	// keep asking until the user gives us a real, in-range index
	while (true)
	{
		out << prompt;
		in >> index;

		if (index < 0 || index >= (int)heroVector.size())
		{
			out << "That index doesn't match a hero. Please try again." << std::endl;
		} else{
			// input was good, stop looping
			break;
		}
	}

	return heroVector[index];
}

void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output)
{

	heroA->resetHealth();
	heroB->resetHealth();

	// continue untill one health hits 0
	while (heroA->getHealth() > 0 && heroB->getHealth() > 0)
	{
	
		output << "---------------------------------------" << std::endl;
		output << heroA->getName() << " has " << heroA->getHealth() << " health " << std::endl;
		output << heroB->getName() << " has " << heroB->getHealth() << " health " << std::endl;

		// gets random power from botrh oponents 
		Power* powerA = heroA->useRandomPower();
		Power* powerB = heroB->useRandomPower();

		// adds text that descripes power used (ie SMASH!)
		output << "*" << heroA->getName() << " " << powerA->use() << std::endl;
		output << "*" << heroB->getName() << " " << powerB->use() << std::endl;

		// calls whatever power function powerA match and retursn the matchg result 
		int result = powerA->fight(powerB);

		if (result == 1)
		{
			// powerA won the round so heroB takes the damage
			heroB->takeDamage();
		}
		else if (result == -1)
		{
			// powerA lost the round so heroA takes the damage instead
			heroA->takeDamage();
		}
		else
		{
			// it was a tie BOTH heroes take
			// damage when their powers tie
			heroA->takeDamage();
			heroB->takeDamage();
		}

	}


	output << "---------------------------------------" << std::endl;

	// whichever heros health is not <= 0 is the one who is still standing
	if (heroA->getHealth() <= 0)
	{
		output << heroB->getName() << " WINS!!!" << std::endl;
	}
	else
	{
		output << heroA->getName() << " WINS!!!" << std::endl;
	}
}

// automated testing func
int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed)
{

	std::ifstream inputFile(inputFileName);

	std::ofstream outputFile(outputFileName);

	int result = fight(inputFile, outputFile, seed);

	// close both files so everything we wrote actually gets saved to disk
	inputFile.close();
	outputFile.close();

	return result;
}

int fight(std::istream& input, std::ostream& output, unsigned seed)
{
	// random seed
	std::srand(seed);

	// vector of heros in program
	std::vector<Hero*> heroVector;

	//  stays true until the user picks "Quit"
	bool keepGoing = true;

	output << "Seed: " << seed << std::endl;
	output << std::endl;

	while (keepGoing)
	{
		// gamer menu 
		output << "Choose an option:" << std::endl;
		output << "1. Load Heroes" << std::endl;
		output << "2. Print Hero Roster" << std::endl;
		output << "3. Hero Fight!" << std::endl;
		output << "4. Quit" << std::endl;
		output << "> ";

		int choice;
		input >> choice;

		if (choice == 1)
		{
			// ask the user for a filename then uses loadHeroes() to build
		
			output << "Enter the file to load: " << std::endl;
			std::string fileName;
			input >> fileName;
			loadHeroes(fileName, heroVector);
		}
		else if (choice == 2)
		{
			// lists all curent heros.
			output << "The following " << heroVector.size() << " heroes are loaded..." << std::endl;
			for (int i = 0; i < heroVector.size(); i++)
			{
				output << "---------------------------------------" << std::endl;
				output << *heroVector[i];
			}
			// one extra divider after the very last hero, to close out the list
			output << "---------------------------------------" << std::endl;
			output << std::endl;
		}
		else if (choice == 3)
		{
			// shows users loadded heros 
			for (int i = 0; i < heroVector.size(); i++)
			{
				output << i << ": " << heroVector[i]->getName() << std::endl;
			}

			// saves user selected hero
			Hero* heroA = selectHero(heroVector, "Select your first hero: ", output, input);
			Hero* heroB = selectHero(heroVector, "Select your second hero: ", output, input);

			// run the actual fight
			heroCombat(heroA, heroB, output);

			output << std::endl;
		}
		else if (choice == 4)
		{
			// "Quit" 
			keepGoing = false;
		}
		else{
			// error handler
			output << "That's not a valid option. Please try again." << std::endl;
		}
	}

	output << "Goodbye" << std::endl;



	return 0;
}
