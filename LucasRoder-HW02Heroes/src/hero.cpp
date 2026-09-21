#include "hero.h"
#include "strlib.h"
#include <iostream>

Hero::Hero(const std::string& heroDef){
	std::vector<std::string> hero = strSplit(heroDef, '|');
	// first part of split is name 
	mName = hero[0];
	// second part add poswers
	std::vector<std::string> powers = strSplit(hero[1], ',');
	for (int i = 0; i < powers.size(); i++){
    	mPowers.push_back(powerFactory(powers[i]));
	}

	// third part health
	mHealth = std::stoi(hero[2]);
	mMaxHealth = mHealth;

}

std::string Hero::getName()
{
	return mName;
}

Power* Hero::useRandomPower()
{
	int randomIndex = std::rand() % mPowers.size();
	Power* chosenPower = mPowers[randomIndex];

	return chosenPower;
}

int Hero::getHealth()
{
	
	return mHealth;
}

void Hero::takeDamage()
{
	mHealth -= 1;
}

void Hero::resetHealth()
{
	
	mHealth = mMaxHealth;
}

std::ostream& operator<<(std::ostream& out, const Hero& h)
{
	out << h.mName << " has the following powers..." << std::endl;

	for (int i = 0; i < h.mPowers.size(); i++)
	{
		out << "*\t" << *(h.mPowers[i]) << std::endl;
	}

	return out;
}
