#include "money.h"
#include <cmath>

Money::Money()
{
	mCents = 0;
}

Money::Money(long long inDollars, long long inCents)
{
	mCents = inDollars * 100 + inCents;
}

Money::Money(double inDollars)
{
	mCents = llround(inDollars * 100);
}

Money::Money(long long inCents)
{
	mCents = inCents;
}

Money::Money(int inCents)
{
	mCents = inCents;
}

Money& Money::operator+=(const Money& right)
{
	mCents = mCents + right.mCents;
	return *this;
}

Money& Money::operator-=(const Money& right)
{
	mCents = mCents - right.mCents;
	return *this;
}

Money& Money::operator*=(double right)
{
	mCents = static_cast<long long>(mCents * right);
	return *this;
}

Money& Money::operator/=(double right)
{
	mCents = static_cast<long long>(mCents / right);
	return *this;
}

bool operator<(const Money& left, const Money& right){
	return left.mCents < right.mCents;

}

bool operator<=(const Money& left, const Money& right){
	return left.mCents <= right.mCents;

}

bool operator>(const Money& left, const Money& right){
	return left.mCents > right.mCents;

}

bool operator>=(const Money& left, const Money& right){
	return left.mCents >= right.mCents;

}

bool operator!=(const Money& left, const Money& right){
	return left.mCents != right.mCents;

}

bool operator==(const Money& left, const Money& right){
	return left.mCents == right.mCents;

}

Money operator+(const Money& left, const Money& right){
	return Money(left.mCents + right.mCents);
}

Money operator-(const Money& left, const Money& right){
	return Money(left.mCents - right.mCents);
}

Money operator*(const Money& left, double right){
	return Money(static_cast<long long>(left.mCents * right));
}

Money operator/(const Money& left, double right){
	return Money(static_cast<long long>(left.mCents / right));
}


std::ostream& operator<<(std::ostream& out, const Money& money){
	long long cents = money.mCents;

	out << "$";
	if (cents < 0){
		out << "-";
		cents = -cents;
	}

	out << cents / 100 << ".";
	if (cents % 100 < 10){
		out << "0";
	}
	out << cents % 100;

	return out;
}

std::istream& operator>>(std::istream& in, Money& money){
	double dollars;
	in >> dollars;
	money.mCents = llround(dollars * 100);
	return in;
}
