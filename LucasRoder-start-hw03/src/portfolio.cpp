#include "portfolio.h"

StockPortfolio::StockPortfolio(){
    mStocks.clear();
}

void StockPortfolio::addStock(Stock inStock){
     mStocks[inStock.getSymbol()] = inStock;
}

bool StockPortfolio::containsStock(std::string inSymbol){
    return mStocks.count(inSymbol) > 0;

}

Stock& StockPortfolio::operator[](std::string inSymbol){
    return mStocks[inSymbol];
}

Money StockPortfolio::getTotalValue() const{
    Money total;
    for (const auto& pair : mStocks){
        Stock stock = pair.second;
        Money stockValue = stock.getCurrPrice() * stock.getNumShares();
        total += stockValue;
    }
    return total;
}

Money StockPortfolio::getOrigValue() const{
    Money total;
    for (const auto& pair : mStocks){
        Stock stock = pair.second;
        Money stockValue = stock.getPurPrice() * stock.getNumShares();
        total += stockValue;
    }
    return total;
}

Money StockPortfolio::getProfit() const{
    Money total;
    for (const auto& pair : mStocks){
        Stock stock = pair.second;
        Money stockProfit = stock.getChange() * stock.getNumShares();
        total += stockProfit;
    }
    return total;
}

std::vector<std::string> StockPortfolio::getAlphaList(){
    std::vector<std::string> symbols;
    for (const auto& pair : mStocks){
        std::string symbol = pair.first;
        symbols.push_back(symbol);
    }
    return symbols;
}

std::vector<std::string> StockPortfolio::getValueList(){
    std::vector<std::string> symbols = getAlphaList();
    int size = symbols.size();

    // Selection sort: find the highest price in the unsorted part and swap it to the front
    for (int i = 0; i < size; i++){
        int maxIndex = i;

        for (int j = i + 1; j < size; j++){
            Money price = mStocks[symbols[j]].getCurrPrice();
            Money maxPrice = mStocks[symbols[maxIndex]].getCurrPrice();
            if (price > maxPrice){
                maxIndex = j;
            }
        }

        std::string temp = symbols[i];
        symbols[i] = symbols[maxIndex];
        symbols[maxIndex] = temp;
    }
    return symbols;
}

std::vector<std::string> StockPortfolio::getDiffList(){
    std::vector<std::string> symbols = getAlphaList();
    int size = symbols.size();

    // Selection sort: find the biggest change in the unsorted part and swap it to the front
    for (int i = 0; i < size; i++){
        int maxIndex = i;

        for (int j = i + 1; j < size; j++){
            Money change = mStocks[symbols[j]].getChange();
            Money maxChange = mStocks[symbols[maxIndex]].getChange();
            if (change > maxChange){
                maxIndex = j;
            }
        }

        std::string temp = symbols[i];
        symbols[i] = symbols[maxIndex];
        symbols[maxIndex] = temp;
    }
    return symbols;
}
