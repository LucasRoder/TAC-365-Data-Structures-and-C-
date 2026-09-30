// �2023 Nathan Greenfield
#pragma once

#include "portfolio.h"

// Name:
//        buyStock
// Input:
//        1. A StockPortfolio, passed by reference
//        2. A string (passed by constant reference)
//			with the stock information
// Output:
//        True to indicate that the stock was added successfully
// Side effects:
//        Adds a key-value pair to the StockPortfolio map
// Summary:
//        Adds a stock to the portfolio
//		  String needs to be in the form: "ORCL|Oracle Corp.|1.02|90.5"
//		  The terms are separated by bars "|" they are...
//			1. The stock symbol
//			2. The company name
//			3. The purchase price (as a decimal)
//			4. The number purchased (as a decimal)
bool buyStock(StockPortfolio& inPort, const std::string& inString);

// Name:
//        updateStock
// Input:
//        1. A StockPortfolio, passed by reference
//        2. A string (passed by constant reference)
//			with the update information
// Output:
//        True to indicate that the stock was updated successfully
// Side effects:
//        Updates the current price of a stock
// Summary:
//        Updates a stock in the portfolio
//		  String needs to be in the form: "ORCL|63.10"
//		  The terms are separated by bars "|" they are...
//			1. The stock symbol
//			2. The current price (as a decimal)
bool updateStock(StockPortfolio& inPort, const std::string& inString);

// Name:
//        processFile
// Input:
//        1. A StockPortfolio, passed by reference
//        2. A string (passed by constant reference)
//			the filename
// Output:
//        True to indicate that the file was successfully processed
// Side effects:
//        Adds and updates stocks to a portfolio
// Summary:
//        Adds or updates a stock in the portfolio
//        Stocks to be added will be in the form "WDAY|Workday Inc. Cl A|68.22|14"
//				Or the same string as needed by buyStock
//		  Stocks being updated are in the form "+WDAY|282.00"
//				Or the same string as needed by updateStock -- with a "+" in front
//		  Things like empty lines should be ignored
//		  Errors to return false can include things like updating a non-existing stock
//		  Or problems from the buy/update stock functions
bool processFile(StockPortfolio& inPort, const std::string& inString);
