// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#pragma once

#include <string>
#include <vector>
#include <ostream>

#include "powers.h"

class Hero
{
public:
    // Name:
    //        Hero parameterized constructor
    // Input:
    //        1. A string (passed as constant reference) with 3 fields.
    //              a. The hero name followed by a vertical bar "|"
    //              b. A list of comma separated power names
    //              c. The maximum health for that hero
    // Output:
    //        None (it's a constructor)
    // Side effects:
    //        Dynamically creates new powers and puts their memory addresses in the Power vector
    // Summary:
    //        Calls the hero constructor to make all the heros
	Hero(const std::string& heroDef);

    // Name:
    //        getName
    // Input:
    //        None
    // Output:
    //        A std::string with the hero's name
    // Side effects:
    //        None
    // Summary:
    //        Name getter
	std::string getName();

	// Name:
    //        print
    // Input:
    //        The output stream that will receive the hero's information
    // Output:
    //        None
    // Side effects:
    //        None
    // Summary:
    //        Displays the health to the indicated output stream
    //        Check the homework write-up for the exact format
    void print(std::ostream& out);

	// Name:
    //        useRandomPower
    // Input:
    //        None
    // Output:
    //        A pointer to a random Power as determined by std::rand
    // Side effects:
    //        Displays that power's flavor text
    // Summary:
    //        Name getter
	Power* useRandomPower();

	// Returns the current health of the hero
	int getHealth();
	// Causes the hero to take one point of damage
	void takeDamage();
	// Resets the heroes' health to the max value
	void resetHealth();

	friend std::ostream& operator<<(std::ostream& out, const Hero& h);

    // TODO: Extra Credit only after completing the rest of the assignment.
    // NOTE: Destructors will be covered later in the semester.
    // TODO: comment this in for extra credit destructor custom impl in hero.cpp
    // ~Hero();

    // TODO: comment this out for extra credit destructor custom impl in hero.cpp
    virtual ~Hero() = default;

private:
	// Max health
	int mMaxHealth;
	// Current health
	int mHealth;
	// Name of hero
	std::string mName;
	// Array of pointers to powers
	std::vector<Power*> mPowers;
};
