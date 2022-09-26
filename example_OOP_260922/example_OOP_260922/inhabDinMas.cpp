#include "inhabDinMas.h"
#include <iostream>
inhabDinMas::inhabDinMas(int Length):length(Length)
{
	mas = new int[length];
}

inhabDinMas::~inhabDinMas()
{
	std::cout << "Destructor Base class\n";
	delete[] mas;
}

Owner::Owner(int Length):inhabDinMas(Length)
{
	
}

Owner::~Owner()
{
	std::cout << "Destructor Owner class\n";
}

void Owner::initMasValue()
{
	for (size_t iter = 0; iter < length; iter++)
	{ 
		mas[iter] = rand() % 100 + 1;
	}
}

void Owner::sumOfMasValue()
{
	int result = 0;
	for (size_t iter = 0; iter < this->length; iter++)
		result += mas[iter];
	std::cout << "Sum of values:"<< result << std::endl ;
}
