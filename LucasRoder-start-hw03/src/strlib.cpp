#include "strlib.h"


std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	std::vector<std::string> result;
	std::string current = "";
	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		if (str[i] == splitChar)
		{
			// Hit a split character, so save the piece we built and start a new one
			result.push_back(current);
			current = "";
		}
		else
		{
			current = current + str[i];
		}
	}

	// Save the last piece (there's no split character after it)
	result.push_back(current);
	return result;
}
