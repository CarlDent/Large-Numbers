// large_numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BigInt.h"

int main()
{
	BigInt value1, value2, value3;
	value1 = 25;
	value2 = 2367802;
	value3 = value1 * value2;
	int value4 = (2147483647 * 2147483647);
	std::cout << value4 << std::endl << value3 << std::endl;
	//value1 = value1 + 15;
	//std::cout << value1 << std::endl;
    return 0;
}


