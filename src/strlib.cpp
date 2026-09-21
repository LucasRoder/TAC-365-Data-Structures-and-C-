#include "strlib.h"


std::vector<std::string> strSplit(const std::string& str, char splitChar){
	std::vector<std::string> formatedList;
	std::string word;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == splitChar){
			formatedList.push_back(word);
			word.clear();
		} else{
			word += str[i];
		}
	}
	formatedList.push_back(word); // pushs final word when there is no split char

	return formatedList;
}

