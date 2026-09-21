// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#include <ctime>

#include "fight.h"

int main(int argc, const char* argv[])
{
	// Main function takes command line arguments
	// Then passes it to fight in "fight.h / fight.cpp"
	fight(std::cin, std::cout, time(nullptr));
	return 0;
}
