// �2023 Nathan Greenfield
#pragma once

#include <map>
#include <vector>

#include "stock.h"


class StockPortfolio
{
private:
	// A map with the stock symbol as the key and the actual stock as a value
	std::map<std::string, Stock> mStocks;

public:
	// Name:
	//        StockPortfolio default constructor
	// Input:
	//        None
	// Output:
	//        None
	// Side effects:
	//        Sets the money member variables to empty
	// Summary:
	//        Creates a StockPortfolio
	StockPortfolio();

	// Name:
	//        addStock
	// Input:
	//        1. A stock to add to the map
	// Output:
	//        None
	// Side effects:
	//        Adds the key/value pair from the stock into the map
	// Summary:
	//        Doesn't check if the stock already exists
	//		  will overwrite the old stock if it's in there
	void addStock(Stock inStock);

	// Name:
	//        containsStock
	// Input:
	//        1. A string with a stock symbol
	// Output:
	//        None
	// Side effects:
	//        Returns true if the key exists in the map -- otherwise false
	// Summary:
	//        A way to check for a stock before accessing it
	bool containsStock(std::string inSymbol);

	// Name:
	//        operator[]
	// Input:
	//        1. A string with a stock symbol
	// Output:
	//        The stock from the map
	// Side effects:
	//        Doesn't check if the stock exists -- can cause an error
	// Summary:
	//        Gets the value attached to the key 
	Stock& operator[](std::string inSymbol);

	// Name:
	//        getTotalValue
	// Input:
	//        None
	// Output:
	//        A money with the current value of the stock portfolio
	// Side effects:
	//        None
	// Summary:
	//        Gets the net-worth of all the stocks in the portfolio
	Money getTotalValue() const;

	// Name:
	//        getOrigValue
	// Input:
	//        None
	// Output:
	//        A money with the original value of the stock portfolio
	// Side effects:
	//        None
	// Summary:
	//        Gets the purchase price of all the stocks in the portfolio
	Money getOrigValue() const;
	
	// Name:
	//        getProfit
	// Input:
	//        None
	// Output:
	//        A money with the change in value of the stock portfolio
	// Side effects:
	//        None
	// Summary:
	//        Gets the money made (between purchase and current prices)
	//		  of all the stocks in the portfolio
	Money getProfit() const;

	// Name:
	//        getAlphaList
	// Input:
	//        None
	// Output:
	//        A vector with the stock symbols
	// Side effects:
	//        None
	// Summary:
	//        The stock symbols will be sorted in alphabetical order
	//        Hint: a std::map stores items in alpha order.
	std::vector<std::string> getAlphaList();

	// Name:
	//        getValueList
	// Input:
	//        None
	// Output:
	//        A vector with the stock symbols
	// Side effects:
	//        None
	// Summary:
	//        The stock symbols will be sorted by (decreasing) current value
	//		  This is by individual stock price -- not all the stocks of a company
	//        Note: You must use Selection Sort from lecture slides, 
	//              You may NOT std::sort()
	std::vector<std::string> getValueList();

	// Name:
	//        getDiffList
	// Input:
	//        None
	// Output:
	//        A vector with the stock symbols
	// Side effects:
	//        None
	// Summary:
	//        The stock symbols will be sorted by (decreasing) change
	//		  This is by individual stock difference -- not all the stocks of a company
	std::vector<std::string> getDiffList();

};
