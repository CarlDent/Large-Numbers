#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef std::vector<unsigned int > _BigInt;
const _BigInt ZERO(0);
class BigInt
{
	friend	bool DigitCompare(const _BigInt, const _BigInt, unsigned int);
public:
	BigInt();
	//equal
		// =
	BigInt& operator = (const int);
	BigInt& operator = (const std::string);
	BigInt& operator = (const _BigInt);
	//add
		// +
	//BigInt& operator+ (const int);
	friend BigInt operator+ (BigInt, BigInt);
	BigInt Add(BigInt, BigInt);
		//+=
	//subtract
		// -
	friend _BigInt operator- (BigInt, BigInt);
	_BigInt Subtract(BigInt, BigInt);
		//--
		//-=
	//multiply
		// *
	friend _BigInt operator* (BigInt, BigInt);
	_BigInt Multiply(BigInt, BigInt);
		//*=
	//divide
		// /
	_BigInt Divide(BigInt, BigInt);
		// /=
	//modulo
		// %
		// %=
	//compare
		//==
		//<
		//>
		friend bool operator> (BigInt&, BigInt&);
		friend bool operator> (_BigInt&, _BigInt&);
		//<=
		//>=
		//!=
	//subscripts
		// []
		int operator[] (std::size_t argv);
	// I/O
		std::string ReturnValue();
		int SizeOf();
		_BigInt getNumber();
		_BigInt * getNumberPtr();
		friend std::ostream	&operator<<(std::ostream &output, BigInt argv);
		friend std::ostream &operator<<(std::ostream &output, _BigInt argv);
	~BigInt();
protected:
	unsigned int _size = 0;
	_BigInt value;
	bool _sign = 0;

private:
	bool scientific_notation = 0;
	void Size();
	int Counter(_BigInt, _BigInt);
};

