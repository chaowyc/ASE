#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long LLT;

class BigInt
{
public:
	BigInt():num(), negative(false){}
	BigInt(const LLT);
	BigInt(const char*);
	BigInt(const string);
	BigInt(const BigInt & x);
	BigInt & operator = (const BigInt &);
	friend istream & operator >> (istream &, BigInt &);
	friend ostream & operator << (ostream &, BigInt);
	const BigInt operator + (const BigInt &) const;
	const BigInt operator - (const BigInt &) const;
	const BigInt operator * (const BigInt &) const;
	const BigInt operator / (const LLT &) const;
	const LLT operator % (const LLT &) const;

	bool operator > (const BigInt &) const;
	bool operator < (const BigInt &) const;
	bool operator == (const BigInt &) const;
	bool operator >= (const BigInt &) const;
	bool operator <= (const BigInt &) const;
	friend const BigInt abs(const BigInt &);
	const BigInt operator - () const;
private:
	deque<int> num;
	bool negative;
};
