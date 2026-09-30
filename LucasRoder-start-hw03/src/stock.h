// �2023 Nathan Greenfield
#pragma once

#include <iostream>
#include <string>

#include "money.h"

class Stock
{
private:
	// Stock's purchase price (which doesn't change) -- stored as a Money
	Money mPurchasePrice;
	// Stock's current price (which can change with a setter) -- stored as a Money
	Money mCurrentPrice;
	// Company's name
	std::string mName;
	// Company's stock symbol
	std::string mSymbol;
	// Number of shares owned (as a decimal, becuase you can own 1/2 shares)
	double mNumShares;
	
public:
	// Name:
	//        Stock parameterized constructor
	// Input:
	//        1. A string (passed as constant reference) with the company's name
	//        1. A string (passed as constant reference) with the company's stock symbol
	//        1. A Money (passed as constant reference) with the stock's purchase price
	//        1. A decimal holding the number of shares
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        None
	// Summary:
	//        Sets the object's member variables
	Stock(std::string inName, std::string inSymbol, const Money& inPurPrice, double inNumShares);

	// Name:
	//        Stock default constructor
	// Input:
	//        None
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        None
	// Summary:
	//        Sets the object's member variables
	//		  This is needed but we've not covered the idea of shallow and deep copies
	//		  so just set the members appropriately (to 0, for example)
	Stock();

	// Name:
	//        Getters
	// Input:
	//        None
	// Output:
	//        The appropriate member variable
	// Side effects:
	//        Is const-safe, so none
	// Summary:
	//        Just in case we need them, they're nice to have
	Money getCurrPrice() const;
	Money getPurPrice() const;
	std::string getSymbol() const;
	std::string getName() const;
	double getNumShares() const;

	// Name:
	//        getChange
	// Input:
	//        None
	// Output:
	//        A money reflecting the change in the stock's value
	// Side effects:
	//        Is const-safe, so none
	// Summary:
	//        Calculates the difference between the current price and the original price
	Money getChange() const;
	
	// Name:
	//        Setters
	// Input:
	//        The appropriate input for the member we're gonna change
	// Output:
	//        None
	// Side effects:
	//        Sets the appropriate member variable
	// Summary:
	//        I think we only need for price --
	//			we won't handle complex things like buying more stock
	void setCurrentPrice(const Money& inCurrPrice);

	// Name:
	//        Output stream operator
	// Input:
	//        1. The output stream to display to
	//        2. The stock to display
	// Output:
	//        The inputted output stream
	// Side effects:
	//        Displays the stock to the output stream
	// Summary:
	//		  Displays a stock like this: "DIS : 2.01 @ $100.01"
	//		  First item is the stock symbol
	//		  Next is the number of shares
	//		  Last is the current value of the stock
	friend std::ostream& operator<<(std::ostream& out, const Stock& stock);
};