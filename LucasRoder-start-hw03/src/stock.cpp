#include "stock.h"
#include <iostream>
#include <string>


Stock::Stock(std::string inName, std::string inSymbol, const Money& inPurPrice, double inNumShares){
    mName = inName;
    mSymbol = inSymbol;
    mPurchasePrice = inPurPrice;
    mCurrentPrice = inPurPrice;
    mNumShares = inNumShares;

}

Stock::Stock(){
      mName = "";
      mSymbol = "";
      mPurchasePrice = Money();
      mCurrentPrice = Money();
      mNumShares = 0;
}


// getters 
Money Stock::getCurrPrice() const{
    return mCurrentPrice;
}

Money Stock::getPurPrice() const{
    return mPurchasePrice;
}


std::string Stock::getSymbol() const{
    return mSymbol;
}

std::string Stock::getName() const{
    return mName;
}

double Stock::getNumShares() const{
    return mNumShares;

}

Money Stock::getChange() const{
    return mCurrentPrice - mPurchasePrice;
}

void Stock::setCurrentPrice(const Money& inCurrPrice){
    mCurrentPrice = inCurrPrice;
}


std::ostream& operator<<(std::ostream& out, const Stock& stock){
    out << stock.mSymbol << " : " << stock.mNumShares << " @ " << stock.mCurrentPrice;
    return out;
}
