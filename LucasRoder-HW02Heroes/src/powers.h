// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#pragma once
#include <string>

enum POWER_ID
{
	POWER_STRENGTH,
	POWER_FLIGHT,
	POWER_LASER,
	POWER_INTEL,
	POWER_GADGETS,
	POWER_NATIONAL
};

class Power
{
public:
	POWER_ID getID();

	// Outputs text when using the power
	virtual std::string use() = 0;

	// Outputs this power's description 
	friend std::ostream& operator<<(std::ostream& out, const Power& p);

	// Fights another power
	// -1 = other power wins
	// 0 = tie
	// 1 = this power wins
	virtual int fight(Power* otherPower) = 0;

	// TODO: Extra Credit only after completing the rest of the assignment.
    // NOTE: Destructors will be covered later in the semester.
    // TODO: comment this in for extra credit destructor custom impl in power.cpp
    // ~Power();

    // TODO: comment this out for extra credit destructor custom impl in power.cpp
	virtual ~Power() = default;

protected:
	std::string mDescription;
	POWER_ID mPowerID;
};

class StrengthPower : public Power
{
public:
	StrengthPower();
	virtual std::string use();
	virtual int fight(Power* other);
};


class FlightPower : public Power
{
public:
	FlightPower();
	virtual std::string use();
	virtual int fight(Power* other);
};

class LaserPower : public Power
{
public:
	LaserPower();
	virtual std::string use();
	virtual int fight(Power* other);
};

class IntelPower : public Power
{
public:
	IntelPower();
	virtual std::string use();
	virtual int fight(Power* other);
};

class GadgetPower : public Power
{
public:
	GadgetPower();
	virtual std::string use();
	virtual int fight(Power* other);
};

class NationalPower : public Power
{
public:
	NationalPower();
	virtual std::string use();
	virtual int fight(Power* other);
};

Power* powerFactory(const std::string& powerName);

