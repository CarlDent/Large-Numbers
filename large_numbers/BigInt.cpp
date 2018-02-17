#include "stdafx.h"
#include "BigInt.h"


BigInt::BigInt()
{
}
/* +++++ ASSIGNMENT BLOCK  +++++ */

/***********************************
Assigns value to the integer array
************************************/
BigInt& BigInt::operator = (int argv) {
	//Convert unparsible int to string
	std::string buffer = std::to_string(argv);
	//determine sign
	if (buffer[0] == '-') {
		//if sign is found; remove sign
		buffer.erase(0, 0);
		//states that object is negative
		this->_sign = 1;
	}
	else {
		this->_sign = 0;
	}
	//reverses string inorder so that the number is smallest place value to largest
	std::reverse(buffer.begin(), buffer.end());
	//clear previous value
	if (_size > 0) {
		this->value.clear();
	}
	//loops through string extracting numbers
	for (int i = 0, len = buffer.size(); i < len; i++) {
		this->value.push_back(buffer[i] - 48);
		this->_size++;
	}
	return *this;
}
BigInt& BigInt::operator = (const _BigInt argv) {
	this->value = argv;
	return *this;
}

/* +++++ ADDING BLOCK +++++ */

// ADDING OPERATOR OVERLOAD
// redirects to .Add function

BigInt operator+ (BigInt arga, BigInt argb) {
	return arga.Add(arga, argb);
}
// ADD()
// Adds two number together
BigInt BigInt::Add(BigInt arga, BigInt argb) {
	 // If either value is a negative then converts to substraction
	if (!arga._sign != !argb._sign) {
		/*return *this;*/ //Substract()		TODO
	}
	 //forward variable declaration
	int carry = 0;
	int digit = 0;
	int width = (arga > argb) ? arga._size : argb._size; // determines width of composite
	((arga > argb) ? argb.value.resize(width, 0) : arga.value.resize(width, 0));
	BigInt buffer; //hold value
	//loops through the two vectors adding and carrying
	for (int i = 0; i < width; i++) {
		digit = (arga[i]) + (argb[i]) + carry; 
		carry = digit / 10;
		buffer.value.push_back(digit % 10); 
		//adds carried digit at the end if big enough
		if (i == (width - 1) && carry > 0)  {
			buffer.value.push_back(carry);
		}
	}
	//adding
	buffer._sign = arga._sign;
	return buffer;
}

/* +++++ SUBTRACTION BLOCK +++++ */
_BigInt operator- (BigInt arga, BigInt argb) {
	return arga.Subtract(arga, argb);
}
_BigInt BigInt::Subtract(BigInt arga, BigInt argb) {
	if (!arga._sign != !argb._sign) {
		/*return *this;*/ //Substract()		TODO
	}
}
/* +++++ MULTIPLICATION BLOCK +++++ */

// Returns Vector with two multipled classes
_BigInt operator* (BigInt arga, BigInt argb){
	return arga.Multiply(arga, argb);
}
_BigInt BigInt::Multiply(BigInt arga, BigInt argb) {
	//variable defitions
	//pointers to bigger and smaller objects
	/*
		Smaller digit multiplying larger digit makes math easier to do.
	*/
	BigInt	*big_arg	= (arga > argb) ? &arga : &argb,
			*small_arg	= (arga > argb) ? &argb : &arga;
	unsigned int width = big_arg->SizeOf();
	BigInt combine, total;
	//Repeat for size of multiple
	for (int i = 0; i < small_arg->SizeOf(); i++) {
		combine.value.clear(); //clears out value of the last multiplycation
		int carry = 0;
		int digit = 0;
		//for if second or greater digit shifts over multiplication
		for (int place_carry = 0; place_carry < i; place_carry++) {
			combine.value.push_back(0);
		}
		//goes through a single digit of multiplication
		for (int j = 0; j < width; j++) {
			int multiple = small_arg->value[i];

			digit = (big_arg->value[j]) * multiple + carry;
			carry = digit / 10;
			combine.value.push_back(digit % 10);

			if (j == (width - 1) && carry > 0) {
				combine.value.push_back(carry);
			}
		}
		//resizes total vector to contain combine vector
		if (combine > total) {
			total.value.resize(combine.value.size(), 0);
		}
		//combines the two for total
		total = (combine + total);
	}
	return total.value;
}
_BigInt BigInt::Divide(BigInt arga, BigInt argb) {
	//inline _BigInt DivideDividendTrasfer(_BigInt * dividend_tras, _BigInt * in_op, int begin, int end) {
	//	for (int i = begin; i < end; i++) {

	//	}
	//};
	/*
	50 / 5 = 10
	divisor = 5
	dividend = 50
	quotient = 10
	*/
	if (arga > argb) {
		_BigInt buffer(0);
		return buffer;
	}
	_BigInt * dividend	= arga.getNumberPtr(),
			* divisor	= argb.getNumberPtr();
	_BigInt remainder, quotient, dividend_in_op;
	for (int i = (dividend->size() - dividend->size()); i < dividend->size(); i++) {
		dividend_in_op.push_back(dividend->at(i));
	}
	for (int progress = divisor->size(); progress < dividend->size; progress++) {
		if (*divisor > dividend_in_op) {
			continue;
		}
	}
}
/* Counts number times an number goes into another number*/
int BigInt::Counter(_BigInt arga, _BigInt argb) {
	if (argb == ZERO) {
		return 0;
	}
	else if (argb > arga) {
		return 0;
	}
	else {
		return 0; /*( (this->))*/
	}
}
/* +++++ COMPARE OPERATOR BLOCK +++++ */
bool operator> (BigInt& arga, BigInt& argb) {
	arga.Size();
	argb.Size();
	if (arga._size > argb._size) {
		return 1;
	}
	else if (arga._size < argb._size) {
		return 0;
	}
	else{
		return DigitCompare(arga.value, argb.value, (arga._size - 1));
	}
}

bool operator> (_BigInt& arga, _BigInt& argb) {
	if (arga.size() > argb.size()) {
		return 1;
	}
	else if (arga.size() < argb.size()) {
		return 0;
	}
	else {
		return DigitCompare(arga, argb, (arga.size() - 1));
	}
}
// DIGITCOMPARE
// Recursively checks digits until one is larger
bool DigitCompare(const _BigInt arga, const _BigInt argb, unsigned int place_value) {
	if (arga[place_value] > argb[place_value]) {
		return 1;
	}
	else if (arga[place_value] < argb[place_value]){
		return 0;
	}
	else if ((arga[place_value] == argb[place_value]) && place_value == 0) {
		return false;
	}
	else {
		return DigitCompare(arga, argb, (place_value - 1));
	}
}
/* +++++ SUBSCRIPT BLOCK +++++ */
int BigInt::operator[] (std::size_t argv) {
	return this->value[argv];
}
/* +++++ I/O BLOCK +++++ */
std::ostream &operator<<(std::ostream &out, BigInt argv) {
	//declarations	
	std::string str_buffer;
	str_buffer.resize(argv.SizeOf(), ' ');
	std::reverse(argv.value.begin(), argv.value.end());
	for (int i = 0, len = argv.value.size(); i < len; i++) {
		str_buffer[i] = (argv[i] + 48);
	}
	out << str_buffer;
	return out;
}
std::ostream &operator<<(std::ostream &out, _BigInt argv) {
	std::string str_buffer;
	str_buffer.resize(argv.size(), NULL);
	std::reverse(argv.begin(), argv.end());
	for (int i = 0, len = argv.size(); i < len; i++) {
		str_buffer[i] = (argv[i] + 48);
	}
	out << str_buffer;
	return out;
}
_BigInt BigInt::getNumber() {
	return this->value;
}
void BigInt::Size() {
	this->_size = value.size();
}
int BigInt::SizeOf() {
	this->Size();
	return this->_size;
}
_BigInt * BigInt::getNumberPtr() {
	return &this->value;
}
BigInt::~BigInt()
{
}
