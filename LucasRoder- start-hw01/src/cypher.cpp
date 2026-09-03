#include "cypher.h"

#include <iostream>
#include <unordered_map>

// creates a map of normal letter as the key with the cypher letter as the value so text can be easily encrypted
std::unordered_map<char, char> cypherKeyEncryption(const std::string& cypher) {
        std::unordered_map<char, char> cypherMap;
        for (int i = 0; i < 26; i++) {
                char normalLetter = 'A' + i; // chars stored as ascii adding a+1 = b
                char cypherLetter = cypher[i];
                cypherMap[normalLetter] = cypherLetter;

        };

        return cypherMap;
};

// creates a map of cypher letter as the key with the normal letter as the value so text can be easily decrypted
// (this is the REVERSE of cypherKeyEncryption -- key and value are swapped)
std::unordered_map<char, char> cypherKeyDecryption(const std::string& cypher) {
        std::unordered_map<char, char> cypherMap;
        for (int i = 0; i < 26; i++) {
                char normalLetter = 'A' + i;
                char cypherLetter = cypher[i];
                cypherMap[cypherLetter] = normalLetter;

        }

        return cypherMap;
};
// function encrypts or decrypts message depending on cypher provided
// this function just substitutes each character using whatever map it was given
void cypherEncryptDecrypt(std::unordered_map<char, char> cypherMap, const std::string& input, std::string& output) {
        output = "";
        for (int i = 0; i < input.size(); i++) {
                char currentChar = input[i];
                if (islower(currentChar)) {
                        char upperChar = (char) toupper(currentChar);  // puts char in uppercase so it can be translated with cypher
                        output += (char) tolower(cypherMap[upperChar]); //puts char back in lowercase so it will be the right case in output file
                }else if (isupper(currentChar)) {
                        output += cypherMap[currentChar]; // if char is uppercase no need to change
                }else {
                        output += currentChar; // if char is not letter eg punctuation add
                };
        };
};
// Encrypts 2nd input creates encrypt map object and passes it to encrypt/ decrypt function to read input and encrypt to output
void substitutionCypherEncrypt(const std::string& cypher, const std::string& input, std::string& output){
        std::unordered_map<char, char> encryptMap = cypherKeyEncryption(cypher);
        cypherEncryptDecrypt(encryptMap, input, output);

};

// Decrypts 2nd input creates decrypt map object and passes it to encrypt/ decrypt function to read input and decrypt to output
void substitutionCypherDecrypt(const std::string& cypher, const std::string& input, std::string& output)
{
        // Encrypts 2nd input creates encrypt map object and passes it to encrypt/ decrypt function to read input and encrypt to output
        std::unordered_map<char, char> decryptMap = cypherKeyDecryption(cypher);
        cypherEncryptDecrypt(decryptMap, input, output);

};

