// Copyright (c) 2023 Nathan Greenfield. All rights reserved


// I dont understand why some stuff is written ion the .cpp and others in the .h
#include "powers.h"

#include <iostream>

POWER_ID Power::getID()
{
	return mPowerID;
}

// Strength Power
StrengthPower::StrengthPower()
{
	mDescription = "Superhuman Strength";
	mPowerID = POWER_STRENGTH;
}


std::string StrengthPower::use()
{
	return "SMASH!!";
}

int StrengthPower::fight(Power* otherPower)
{
	int retVal = 0;
	POWER_ID otherID = otherPower->getID();
	// win
	if (otherID == POWER_GADGETS || otherID == POWER_LASER || otherID == POWER_NATIONAL)
	{
		std::cout << "STRENGTH WINS!" << std::endl;
		retVal = 1;
	}
	// loss
	else if (otherID == POWER_FLIGHT || otherID == POWER_INTEL)
	{
		std::cout << "STRENGTH LOSES! " << std::endl;
		retVal = -1;
	// tie
	} else{
		std::cout << "TIE! " << std::endl;
		retVal = 0;

	}

	return retVal;
}

// Flight Power
FlightPower::FlightPower()
{
	mDescription = "Ability to fly";
	mPowerID = POWER_FLIGHT;
}

std::string FlightPower::use()
{
	return "flies away, maybe far from this place.";
}

int FlightPower::fight(Power* otherPower)
{
	int retVal = 0;
	POWER_ID otherID = otherPower->getID();
	// WIN
	if (otherID == POWER_INTEL || otherID == POWER_NATIONAL || otherID == POWER_STRENGTH){
		std::cout << "FLIGHT WINS!" << std::endl;
		retVal = 1;
	// Loss
	} else if (otherID == POWER_GADGETS || otherID == POWER_LASER){
		std::cout << "FLIGHT LOSSES!" << std::endl;
		retVal = -1;
	} else{
		// Tie 
		std::cout << "TIE! " << std::endl;
		retVal = 0;
	}
	

	return retVal;
}

// Laser Power
LaserPower::LaserPower()
{
	mDescription = "Can shoot lasers";
	mPowerID = POWER_LASER;
}

std::string LaserPower::use()
{
	return "shoots lasers from their eyes. PEWPEWPEW!";
}

int LaserPower::fight(Power* otherPower)
{
	int retVal = 0;
	POWER_ID otherID = otherPower->getID();
	// WIN
	if (otherID == POWER_FLIGHT || otherID == POWER_INTEL || otherID == POWER_NATIONAL){
		std::cout << "LASER WINS!" << std::endl;
		retVal = 1;
	// Loss
	} else if (otherID == POWER_GADGETS || otherID == POWER_STRENGTH){
		std::cout << "LASER LOSES!" << std::endl;
		retVal = -1;
	} else{
		// Tie
		std::cout << "TIE! " << std::endl;
		retVal = 0;
	}

	return retVal;
}

// Intelligence Power
IntelPower::IntelPower()
{
	mDescription = "Superhuman Intelligence";
	mPowerID = POWER_INTEL;
}

std::string IntelPower::use()
{
	return "ponders deeply.";
}

int IntelPower::fight(Power* otherPower)
{
	int retVal = 0;
	POWER_ID otherID = otherPower->getID();
	if (otherID == POWER_GADGETS || otherID == POWER_NATIONAL || otherID == POWER_STRENGTH)
	{
		std::cout << "INTELLIGENCE WINS !" << std::endl;
		retVal = 1;
	}
	else if (otherID == POWER_FLIGHT || otherID == POWER_LASER)
	{
		std::cout << "INTELLIGENCE LOSES!" << std::endl;
		retVal = -1;
	} else{
		std::cout << "TIE! " << std::endl;
		retVal = 0;
	}

	return retVal;
}

// Gadget Power
GadgetPower::GadgetPower()
{
	mDescription = "Uses some crazy gadgets";
	mPowerID = POWER_GADGETS;
}

std::string GadgetPower::use()
{
	return "uses what's (hopefully) the right tool for the job.";
}

int GadgetPower::fight(Power* otherPower)
{
	int retVal = 0;
	POWER_ID otherID = otherPower->getID();
	// WIN
	if (otherID == POWER_FLIGHT || otherID == POWER_LASER || otherID == POWER_NATIONAL){
		std::cout << "GADGETS WINS!" << std::endl;
		retVal = 1;
	// Loss
	} else if (otherID == POWER_INTEL || otherID == POWER_STRENGTH){
		std::cout << "GADGETS LOSES!" << std::endl;
		retVal = -1;
	} else{
		// Tie
		std::cout << "TIE! " << std::endl;
		retVal = 0;
	}

	return retVal;
}

// Nationalism Power
NationalPower::NationalPower()
{
	mDescription = "A strong belief in their mother country";
	mPowerID = POWER_NATIONAL;
}

std::string NationalPower::use()
{
	return "screams AMERICA YEAH!!";
}

int NationalPower::fight(Power* otherPower)
{
	int retVal = 0;
	POWER_ID otherID = otherPower->getID();
	// National never beats anything, so there's no WIN branch.
	if (otherID == POWER_NATIONAL){
		// Tie
		std::cout << "TIE! " << std::endl;
		retVal = 0;
	} else{
		// Loss
		std::cout << "NATIONAL LOSES!" << std::endl;
		retVal = -1;
	}

	return retVal;
}

std::ostream& operator<<(std::ostream& out, const Power& p)
{
	out << p.mDescription;
	return out;
}

Power* powerFactory(const std::string& powerName)
{
	Power* retVal = nullptr;

	if (powerName == "strength"){
		retVal = new StrengthPower();
	} else if (powerName == "flight"){
		retVal = new FlightPower();
	} else if (powerName == "laser"){
		retVal = new LaserPower();
	} else if (powerName == "intel"){
		retVal = new IntelPower();
	} else if (powerName == "gadget"){
		retVal = new GadgetPower();
	} else if (powerName == "national"){
		retVal = new NationalPower();
	}

	return retVal;
}

