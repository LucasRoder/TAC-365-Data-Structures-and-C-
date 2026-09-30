// �2023 Nathan Greenfield
#pragma once

#include <iostream>

class Money
{
private:
	// Rather than deal with fractional dollars and cents,
	// store everything as integer cents
	// it'll make life easier, trust me.
	long long mCents;

public:
	// Name:
	//        Money default constructor
	// Input:
	//        None
	// Output:
	//        None
	// Side effects:
	//        Sets the money member variables to 0
	// Summary:
	//        Creates a Money object
	Money();

	// Name:
	//        Money parameterized constructor
	// Input:
	//        1. An integer (stored as a long long) with the number of dollars
	//        2. An integer (stored as a long long) with the number of cents
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        Sets the relevant member variables for the class
	// Summary:
	//        Creates a Money object
	Money(long long inDollars, long long inCents);

	// Name:
	//        Money parameterized constructor
	// Input:
	//        1. A decimal (stored as a double) with the number of dollars
	//        and cents (to the right of the decimal)
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        Sets the relevant member variables for the class
	// Summary:
	//        Creates a Money object
	Money(double inDollars);

	// Name:
	//        Money parameterized constructor
	// Input:
	//        1. An integer (stored as a long long) with the number of cents
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        Sets the relevant member variables for the class
	// Summary:
	//        Creates a Money object
	Money(long long inCents);

	// Name:
	//        Money parameterized constructor
	// Input:
	//        1. An integer (stored as an int) with the number of cents
	// Output:
	//        None (it's a constructor)
	// Side effects:
	//        Sets the relevant member variables for the class
	// Summary:
	//        Creates a Money object -- and for convenience
	//			raw numbers in C++ are interpreted as int,
	//			unless otherwise specified
	Money(int inCents);

	// Name:
	//        Arithmetic assignment operator
	// Input:
	//        1. Another money object
	// Output:
	//        The current object, returned by reference
	// Side effects:
	//        Adds or subtracts the other money into this money
	// Summary:
	//		  Arithmetic assignment operator, like with integers
	//			a += b
	//			a -= b
	Money& operator+=(const Money& right);
	Money& operator-=(const Money& right);

	// Name:
	//        Arithmetic assignment operator
	// Input:
	//        1. A decimal (stored as a double)
	// Output:
	//        The current object, returned by reference
	// Side effects:
	//        Multiplies or divides the money by the scalar
	// Summary:
	//		  Arithmetic assignment operator, like with integers
	//			a *= b -> a = a * b -> a = a.operator*=(b) where b is right, a is this
	//			a \= b
	Money& operator*=(double right);
	Money& operator/=(double right);

	// Name:
	//        Comparison operator
	// Input:
	//        1. A money that is the left hand of the operator
	//        2. A money that is the right hand of the operator
	// Output:
	//        A boolean in line with the normal comparison
	// Side effects:
	//        None
	// Summary:
	//		  Comparison operator, like with integers
	//			a <= b
	friend bool operator<(const Money& left, const Money& right);
	friend bool operator>(const Money& left, const Money& right);
	friend bool operator<=(const Money& left, const Money& right);
	friend bool operator>=(const Money& left, const Money& right);
	friend bool operator==(const Money& left, const Money& right);
	friend bool operator!=(const Money& left, const Money& right);

	// Name:
	//        Binary arithmetic operator
	// Input:
	//        1. A money that is the left hand of the operator
	//        2. A money that is the right hand of the operator
	// Output:
	//        A new money object that contains the combined value
	// Side effects:
	//        Adds or subtracts the two money inputs
	// Summary:
	//		  Arithmetic assignment operator, like with integers
	//			c = a + b
	//			c = a - b
	friend Money operator+(const Money& left, const Money& right);
	friend Money operator-(const Money& left, const Money& right);

	// Name:
	//        Binary arithmetic operator
	// Input:
	//        1. A money that is the left hand of the operator
	//        2. A scalar (as a double) that is the right hand of the operator
	// Output:
	//        A new money object that contains the combined value
	// Side effects:
	//        Multiplies or divides the scaler into the money
	// Summary:
	//		  Arithmetic assignment operator, like with integers
	//			c = a + b
	//			c = a - b
	friend Money operator*(const Money& left, double right);
	friend Money operator/(const Money& left, double right);

	// Name:
	//        Output stream operator
	// Input:
	//        1. The stream to output to (right of the operator)
	//        2. The money to display (left of the operator)
	// Output:
	//        The inputted output stream
	// Side effects:
	//        Displays the money to the output
	// Summary:
	//		  Since all money is dollars -- add a "$" before the number
	//		  If the money is negative, the negative goes after the "$" but before the numbers
	//		  Display only 2 digits for cents -- don't forget leading 0's!
	friend std::ostream& operator<<(std::ostream& out, const Money& money);

	// Name:
	//        Input stream operator
	// Input:
	//        1. The stream to get a money from (right of the operator)
	//        2. The money to store the value (left of the operator)
	// Output:
	//        The inputted input stream
	// Side effects:
	//        None
	// Summary:
	//		  You don't need to worry about the "$" for this one
	//		  Since money is given in dollars.cents, read in a decimal number
	//		  Then store everything in the member variable for the Money
	friend std::istream& operator>>(std::istream& in, Money& money);
};

