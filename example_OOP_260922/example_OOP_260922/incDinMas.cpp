#include "incDinMas.h"
#include <iostream>

incDinMas::incDinMas(int Length):length(Length)
{
	mas = new int[length];
	this->initMasValue();
}

incDinMas::~incDinMas()
{
	delete[] mas;
}

void incDinMas::sumOfMasEl()
{
	int result = 0;
	for (size_t iter = 0; iter < length; iter++)
		result += mas[iter];
	std::cout << "Sum of values:" << result << std::endl;
}

void incDinMas::initMasValue()
{
	srand(time(NULL));
	for (size_t iter = 0; iter < length; iter++)
		mas[iter] = rand() %100 + 1;
}
