#include "driver.h"
#include "strlib.h"

#include <fstream>

bool buyStock(StockPortfolio& inPort, const std::string& inString){
    std::vector<std::string> parts = strSplit(inString, '|');
    if (parts.size() != 4){
        return false;
    }

    std::string symbol = parts[0];
    std::string name = parts[1];
    double price = 0;
    double numShares = 0;

    try {
        price = std::stod(parts[2]);
        numShares = std::stod(parts[3]);
    } catch (const std::exception& error) {
        return false;
    }

    Stock newStock(name, symbol, Money(price), numShares);
    inPort.addStock(newStock);
    return true;
}

bool updateStock(StockPortfolio& inPort, const std::string& inString){
    std::vector<std::string> parts = strSplit(inString, '|');
    if (parts.size() != 2){
        return false;
    }

    std::string symbol = parts[0];
    if (!inPort.containsStock(symbol)){
        return false;
    }

    double newPrice = 0;
    try {
        newPrice = std::stod(parts[1]);
    } catch (const std::exception& error) {
        return false;
    }

    inPort[symbol].setCurrentPrice(Money(newPrice));
    return true;
}

bool processFile(StockPortfolio& inPort, const std::string& inString){
    std::ifstream file(inString);
    if (!file.is_open()){
        return false;
    }

    std::string line;
    while (std::getline(file, line)){
        if (line == ""){
            continue;
        }

        bool success;
        if (line[0] == '+'){
        
            std::string updateInfo = line.substr(1);
            success = updateStock(inPort, updateInfo);
        } else {
            success = buyStock(inPort, line);
        }

        if (!success){
            return false;
        }
    }
    return true;
}
