#include "firstexample.h"
#include <iostream>
int* InputElementOfMassiv(int *lengthOfMassiv)
{
	std::cout << "Input length of massiv" << std::endl;
	std::cout << "Length = "; std::cin >> *lengthOfMassiv;
	static int * mas = new int[*lengthOfMassiv];
	for (int i=0; i<*lengthOfMassiv;i++)
	{
		mas[i] = rand() % 99 + 1;
		std::cout << mas[i] << "\t";
	}
	std::cout << "\n";
	return mas;
}

int SumOfElemntMassiv(int* mas, int *lengthOfMassiv)
{
	int sum=0,count = 0;
	while (count < *lengthOfMassiv)
	{
		sum += mas[count];
		count++;
	}
	delete[] mas;
		return sum;
}

void OutputOfSumElementMassiv(int sumOfMassivEllement)
{
	std::cout << "Result:";
	std::cout << sumOfMassivEllement << std::endl;
}
