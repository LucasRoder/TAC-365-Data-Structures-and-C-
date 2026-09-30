#include "catch.hpp"
#include <string>
#include <sstream>

#include "money.h"
#include "stock.h"
#include "portfolio.h"
#include "driver.h"

extern bool CheckTextFilesSame(const std::string& fileNameA, 
	const std::string& fileNameB);

static int grade = 0;

TEST_CASE("Test MONEY class", "[graded]")
{
	SECTION("Default constructor and output operator|2")
	{
		Money m1;

		std::stringstream ss;
		ss << m1;
		ss.flush();

		REQUIRE(ss.str() == "$0.00");

		grade += 2;
	}

	SECTION("2 long parameter constructor and output operator|2")
	{
		Money m1(11, 50);

		std::stringstream ss;
		ss << m1;
		ss.flush();

		REQUIRE(ss.str() == "$11.50");

		grade += 2;
	}

	SECTION("Double constructor and output operator|2")
	{
		Money m1(-32.11);

		std::stringstream ss;
		ss << m1;
		ss.flush();

		REQUIRE(ss.str() == "$-32.11");

		grade += 2;
	}

	SECTION("1 long long constructor and output operator|2")
	{
		Money m1((long long)10001);

		std::stringstream ss;
		ss << m1;
		ss.flush();

		REQUIRE(ss.str() == "$100.01");

		grade += 2;
	}

	SECTION("1 int constructor and output operator|2")
	{
		Money m1(-101);

		std::stringstream ss;
		ss << m1;
		ss.flush();

		REQUIRE(ss.str() == "$-1.01");

		grade += 2;
	}

	SECTION("Check < operator|2")
	{
		Money m1(11, 50);
		Money m2(110, 50);

		REQUIRE(m1 < m2);
		REQUIRE(!(m2 < m1));

		grade += 2;
	}

	SECTION("Check <= operator|2")
	{
		Money m1(11, 50);
		Money m2(110, 50);
		Money m3(11.50);

		REQUIRE(m1 <= m2);
		REQUIRE(!(m2 <= m1));
		REQUIRE(m1 <= m3);
		
		grade += 2;
	}

	SECTION("Check > operator|2")
	{
		Money m1(11, 50);
		Money m2(110, 50);

		REQUIRE(!(m1 > m2));
		REQUIRE(m2 > m1);

		grade += 2;
	}

	SECTION("Check >= operator|2")
	{
		Money m1(11, 50);
		Money m2(110, 50);
		Money m3(11.50);

		REQUIRE(!(m1 >= m2));
		REQUIRE(m2 >= m1);
		REQUIRE(m1 >= m3);

		grade += 2;
	}

	SECTION("Check == operator|2")
	{
		Money m1(11, 50);
		Money m2(110, 50);
		Money m3(11.50);

		REQUIRE(!(m1 == m2));
		REQUIRE(!(m2 == m1));
		REQUIRE(m1 == m3);

		grade += 2;
	}

	SECTION("Check != operator|2")
	{
		Money m1(11, 50);
		Money m2(110, 50);
		Money m3(11.50);

		REQUIRE(m1 != m2);
		REQUIRE(m2 != m1);
		REQUIRE(!(m1 != m3));

		grade += 2;
	}

	SECTION("+ operator and output operator|2")
	{
		Money m1(101);
		Money m2(10,10);
		Money m3 = m1 + m2;

		
		std::stringstream ss;
		ss << m3;
		ss.flush();

		REQUIRE(ss.str() == "$11.11");

		grade += 2;
	}

	SECTION("- operator and output operator|2")
	{
		Money m1(101);
		Money m2(10, 1);
		Money m3 = m2 - m1;
		Money m4 = m1 - Money(190);


		std::stringstream ss;
		ss << m3;
		ss.flush();
		REQUIRE(ss.str() == "$9.00");

		ss.str("");
		ss << m4;
		ss.flush();
		REQUIRE(ss.str() == "$-0.89");

		grade += 2;
	}

	SECTION("* operator and output operator|2")
	{
		Money m1(101);
		Money m2 = m1 * -0.9;
		Money m3 = m1 * 3;


		std::stringstream ss;
		ss << m2;
		ss.flush();
		REQUIRE(ss.str() == "$-0.90");

		ss.str("");
		ss << m3;
		ss.flush();
		REQUIRE(ss.str() == "$3.03");

		grade += 2;
	}

	SECTION("/ operator and output operator|2")
	{
		Money m1(101);
		Money m2 = m1 / -0.9;
		Money m3 = m1 / 3;


		std::stringstream ss;
		ss << m2;
		ss.flush();
		REQUIRE(ss.str() == "$-1.12");

		ss.str("");
		ss << m3;
		ss.flush();
		REQUIRE(ss.str() == "$0.33");

		grade += 2;
	}

	SECTION("+= operator and output operator|2")
	{
		Money m1(101);
		Money m2(10, 10);
		m2 += m1;

		std::stringstream ss;
		ss << m2;
		ss.flush();

		REQUIRE(ss.str() == "$11.11");

		grade += 2;
	}

	SECTION("-= operator and output operator|2")
	{
		Money m1(101);
		Money m2(10, 1);
		m2 -= m1;


		std::stringstream ss;
		ss << m2;
		ss.flush();
		REQUIRE(ss.str() == "$9.00");

		grade += 2;
	}

	SECTION("*= operator and output operator|2")
	{
		Money m1(101);
		m1 *= -0.9;


		std::stringstream ss;
		ss << m1;
		ss.flush();
		REQUIRE(ss.str() == "$-0.90");

		grade += 2;
	}

	SECTION("/= operator and output operator|2")
	{
		Money m1(101);
		m1 /= 3;


		std::stringstream ss;
		ss << m1;
		ss.flush();
		REQUIRE(ss.str() == "$0.33");

		grade += 2;
	}

	SECTION("input and output operator|2")
	{
		Money m1;
		
		std::stringstream ss;
		ss << "10.01";
		ss.flush();
		ss >> m1;

		std::stringstream ss2;
		ss2 << m1;
		ss2.flush();
		REQUIRE(ss2.str() == "$10.01");

		std::stringstream ss3;
		ss3 << "-0.01";
		ss3.flush();
		ss3 >> m1;

		std::stringstream ss4;
		ss4 << m1;
		ss4.flush();
		REQUIRE(ss4.str() == "$-0.01");
		
		grade += 2;
	}

	// SECTION("Score")
	// {
	// 	WARN("*** SCORE: " << grade << "/" << 90 << "***");
	// }
}

TEST_CASE("Test STOCK class", "[graded]")
{
	SECTION("Default constructor, setters and getters|2")
	{
		Stock s1("Disney", "DIS", Money(10001), 2.01);

		REQUIRE(s1.getName() == "Disney");
		REQUIRE(s1.getSymbol() == "DIS");
		REQUIRE(s1.getNumShares() == 2.01);
		REQUIRE(s1.getCurrPrice() == Money(100, 01));
		REQUIRE(s1.getPurPrice() == Money(10001));

		s1.setCurrentPrice(Money(110001));
		REQUIRE(s1.getChange() == Money(100000));

		grade += 2;
	}

	SECTION("Test << operator|2")
	{
		Stock s1("Disney", "DIS", Money(10010), 2.01);
		Stock s2("Birkshire", "BRK", Money(200000), 99.2);

		std::stringstream ss1;
		ss1 << s1;
		ss1.flush();
		REQUIRE(ss1.str() == "DIS : 2.01 @ $100.10");

		std::stringstream ss2;
		ss2 << s2;
		ss2.flush();
		REQUIRE(ss2.str() == "BRK : 99.2 @ $2000.00");

		grade += 2;
	}
	
	// SECTION("Score")
	// {
	// 	WARN("*** SCORE: " << grade << "/" << 90 << "***");
	// }
}

TEST_CASE("Test PORTFOLIO class", "[graded]")
{
	SECTION("Constructor, getTotalValue|2")
	{
		StockPortfolio port;

		REQUIRE(port.getOrigValue() == Money(0));

		grade += 2;
	}

	SECTION("Constructor, add stocks, containsStock|4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);
		
		REQUIRE(port.containsStock("DIS") == true);
		REQUIRE(port.containsStock("XYZ") == true);
		REQUIRE(port.containsStock("BOB") == false);
		REQUIRE(port.containsStock("NATE") == false);
	
		grade += 4;
	}

	SECTION("Constructor, add stocks, operator[]|4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		std::stringstream ss1;
		ss1 << port["DIS"];
		ss1.flush();
		REQUIRE(ss1.str() == "DIS : 2.01 @ $100.01");

		port["BRK"].setCurrentPrice(Money(1001));		
		std::stringstream ss2;
		ss2 << port["BRK"];
		ss2.flush();
		REQUIRE(ss2.str() == "BRK : 1 @ $10.01");

		grade += 4;
	}

	SECTION("Constructor, add stocks, getOrigValue|4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		REQUIRE(port.getOrigValue() == Money(2077638));

		grade += 4;
	}

	SECTION("Constructor, add stocks, operator[], getTotalValue|4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		port["DIS"].setCurrentPrice(port["DIS"].getPurPrice() * 2);
		port["BRK"].setCurrentPrice(port["BRK"].getPurPrice() * 2);
		port["ABC"].setCurrentPrice(port["ABC"].getPurPrice() * 2);
		port["XYZ"].setCurrentPrice(port["XYZ"].getPurPrice() * 2);
		
		REQUIRE(port.getTotalValue() == Money(4155277));

		grade += 4;
	}

	SECTION("Constructor, add stocks, operator[], getProfit|4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		port["DIS"].setCurrentPrice(port["DIS"].getPurPrice() * 2);
		port["BRK"].setCurrentPrice(port["BRK"].getPurPrice() * 2);
		port["ABC"].setCurrentPrice(port["ABC"].getPurPrice() * 2);
		port["XYZ"].setCurrentPrice(port["XYZ"].getPurPrice() * 2);

		REQUIRE(port.getProfit() == Money(2077638));

		grade += 4;
	}

	SECTION("Constructor, add stocks, operator[], getAlphaList|4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		std::vector<std::string> alphaList = port.getAlphaList();

		REQUIRE(alphaList[0] == "ABC");
		REQUIRE(alphaList[1] == "BRK");
		REQUIRE(alphaList[2] == "DIS");
		REQUIRE(alphaList[3] == "XYZ");

		grade += 4;
	}

	SECTION("Constructor, add stocks, operator[], getValueList|4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		port["DIS"].setCurrentPrice(port["DIS"].getPurPrice() * 2);
		port["BRK"].setCurrentPrice(port["BRK"].getPurPrice() * 2);
		port["ABC"].setCurrentPrice(port["ABC"].getPurPrice() * 2);
		port["XYZ"].setCurrentPrice(port["XYZ"].getPurPrice() * 2);

		std::vector<std::string> valueList = port.getValueList();

		REQUIRE(valueList[0] == "BRK");
		REQUIRE(valueList[1] == "DIS");
		REQUIRE(valueList[2] == "XYZ");
		REQUIRE(valueList[3] == "ABC");

		grade += 4;
	}

	SECTION("Constructor, add stocks, operator[], getDiffList|4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		port["DIS"].setCurrentPrice(port["DIS"].getPurPrice() * 2);
		port["BRK"].setCurrentPrice(port["BRK"].getPurPrice() * 0.5);
		port["ABC"].setCurrentPrice(port["ABC"].getPurPrice() * 1.1);
		port["XYZ"].setCurrentPrice(port["XYZ"].getPurPrice() * 5);

		std::vector<std::string> diffList = port.getDiffList();

		REQUIRE(diffList[0] == "XYZ");
		REQUIRE(diffList[1] == "DIS");
		REQUIRE(diffList[2] == "ABC");
		REQUIRE(diffList[3] == "BRK");

		grade += 4;
	}

	// SECTION("Score")
	// {
	// 	WARN("*** SCORE: " << grade << "/" << 90 << "***");
	// }
}

TEST_CASE("Test DRIVER functions", "[graded]")
{
	SECTION("buyStock test|4")
	{
		StockPortfolio port;

		REQUIRE(buyStock(port, "APPL|Apple Inc.|0.11|10000.50"));
		REQUIRE(buyStock(port, "KHC|Kraft Heinz Co.|88.22|10"));

		if (port.containsStock("APPL"))
		{
			REQUIRE(port["APPL"].getName() == "Apple Inc.");
			REQUIRE(port["APPL"].getNumShares() == 10000.5);
			REQUIRE(port["APPL"].getCurrPrice() == Money(11));
			REQUIRE(port["APPL"].getPurPrice() == Money(11));
			REQUIRE(port["APPL"].getChange() == Money(0));
			REQUIRE(port["APPL"].getSymbol() == "APPL");
		}
		else
		{
			REQUIRE(false);
		}

		if (port.containsStock("KHC"))
		{
			REQUIRE(port["KHC"].getName() == "Kraft Heinz Co.");
			REQUIRE(port["KHC"].getNumShares() == 10);
			REQUIRE(port["KHC"].getCurrPrice() == Money(8822));
			REQUIRE(port["KHC"].getPurPrice() == Money(8822));
			REQUIRE(port["KHC"].getChange() == Money(0));
			REQUIRE(port["KHC"].getSymbol() == "KHC");
		}
		else
		{
			REQUIRE(false);
		}

		grade += 4;
	}

	SECTION("updateStock test|4")
	{
		StockPortfolio port;

		REQUIRE(buyStock(port, "APPL|Apple Inc.|0.11|10000.50"));
		REQUIRE(buyStock(port, "KHC|Kraft Heinz Co.|88.22|10"));

		REQUIRE(!updateStock(port, "BTI|38.03"));
		REQUIRE(updateStock(port, "APPL|135.43"));

		if (port.containsStock("APPL"))
		{
			REQUIRE(port["APPL"].getName() == "Apple Inc.");
			REQUIRE(port["APPL"].getNumShares() == 10000.5);
			REQUIRE(port["APPL"].getCurrPrice() == Money(13543));
			REQUIRE(port["APPL"].getPurPrice() == Money(11));
			REQUIRE(port["APPL"].getChange() == Money(13532));
			REQUIRE(port["APPL"].getSymbol() == "APPL");
		}
		else
		{
			REQUIRE(false);
		}

		grade += 4;
	}

	SECTION("processFile test|4")
	{
		StockPortfolio port;

		REQUIRE(processFile(port, "input/test01.txt"));

		// Check for non-existant stock
		REQUIRE(!port.containsStock("ABC"));

		// Check an updated stock
		if (port.containsStock("APPL"))
		{
			REQUIRE(port["APPL"].getName() == "Apple Inc.");
			REQUIRE(port["APPL"].getNumShares() == 10000);
			REQUIRE(port["APPL"].getCurrPrice() == Money(13543));
			REQUIRE(port["APPL"].getPurPrice() == Money(11));
			REQUIRE(port["APPL"].getChange() == Money(13532));
			REQUIRE(port["APPL"].getSymbol() == "APPL");
		}
		else
		{
			REQUIRE(false);
		}

		// Check an updated stock
		if (port.containsStock("BRK.A"))
		{
			REQUIRE(port["BRK.A"].getName() == "Berkshire Hathaway Inc. Cl A");
			REQUIRE(port["BRK.A"].getNumShares() == 11);
			REQUIRE(port["BRK.A"].getCurrPrice() == Money(365500.00));
			REQUIRE(port["BRK.A"].getPurPrice() == Money(130700));
			REQUIRE(port["BRK.A"].getChange() == Money(364193.00));
			REQUIRE(port["BRK.A"].getSymbol() == "BRK.A");
		}
		else
		{
			REQUIRE(false);
		}

		// Check an regular stock
		if (port.containsStock("MDLZ"))
		{
			REQUIRE(port["MDLZ"].getName() == "Mondelez International Inc. Cl A");
			REQUIRE(port["MDLZ"].getNumShares() == 30);
			REQUIRE(port["MDLZ"].getCurrPrice() == Money(31.07));
			REQUIRE(port["MDLZ"].getPurPrice() == Money(31.07));
			REQUIRE(port["MDLZ"].getChange() == Money(0));
			REQUIRE(port["MDLZ"].getSymbol() == "MDLZ");
		}
		else
		{
			REQUIRE(false);
		}


		grade += 4;
	}

	// SECTION("Score")
	// {
	// 	WARN("*** SCORE: " << grade << "/" << 90 << "***");
	// }
}