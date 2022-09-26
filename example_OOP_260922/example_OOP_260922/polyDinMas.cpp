#include "polyDinMas.h"
#include <iostream>
polyDinMas::polyDinMas()
{
	std::cout << "Base Constructor\n";
}

polyDinMas::~polyDinMas()
{
	std::cout << "Base Destructor\n";
}

intOwner::intOwner(int Length):length(Length)
{
	std::cout << "intOwner Constructor\n";
	mas = new int[length];
	initDinMas();
}

intOwner::~intOwner()
{
	std::cout << "intOwner Destructor\n";
	delete[] mas;
}

void intOwner::initDinMas()
{
	for (size_t iter = 0; iter < length; iter++)
	{
		mas[iter] = rand() % 100 + 1;
	}
}

void intOwner::sumOfMasValue()
{
	int result = 0;
	for (size_t iter = 0; iter < length; iter++)
		result += mas[iter];
	std::cout << "Sum of values:" << result << std::endl;
}

symbolOwner::symbolOwner(int Length):length(Length)
{
	std::cout << "symbolOwner Constructor\n";
	mas = new char[length];
	initDinMas();
}

symbolOwner::~symbolOwner()
{
	std::cout << "symbolOwner Destructor\n";
	delete[] mas;
}

void symbolOwner::initDinMas()
{
	for (size_t iter = 0; iter < length; iter++)
	{
		mas[iter] = static_cast<char>(rand() % ('Z'-'A') + 'A');
	}
}

void symbolOwner::sumOfMasValue()
{
	std::string result;
	for (size_t iter = 0; iter < this->length; iter++)
		result += mas[iter];
	std::cout << "Sum of values:" << result << std::endl;
}
