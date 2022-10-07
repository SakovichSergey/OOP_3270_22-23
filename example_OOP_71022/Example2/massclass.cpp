#include "massclass.h"

masclass::masclass(int length):len(length)
{
	std::cout << "Base constructor.\n";
	mas = new int[len];
	for (size_t i = 0; i < len; i++)
		mas[i] = rand() % 100 + 1;
	std::cout << "Adress of mas:" << mas <<std::endl;
}

masclass::masclass(const masclass& A)
{
	std::cout << "Copy constructor.\n";
	len = A.len;
	mas = new int[len];
	for (size_t i = 0; i < len; i++)
		mas[i] = A.mas[i];
	std::cout << "Adress of mas:" << mas << std::endl;
}

masclass::masclass(masclass&& A) noexcept
{
	std::cout << "Move constructor.\n";
	len = A.len;
	mas = A.mas;
	A.mas = nullptr;
	std::cout << "Adress of mas:" << mas << std::endl;
}

masclass::~masclass()
{
	delete[] mas;
	std::cout << "Destructor.\n";
}

void masclass::outputMas()
{
	std::cout << "Output array\n";
	for (size_t i = 0; i < len; i++)
		std::cout << mas[i] << "\t";
	std::cout << std::endl;
}

int masclass::summOfVal()
{
	int value = 0;
	for (size_t i = 0; i < len; i++)
		value += mas[i];
	std::cout << "Sum of array elements:" << value << std::endl;
	return value;
}

masclass& masclass::operator= (const masclass& B) 
{
	std::cout << "Operator =\n";
	len = B.len;
	mas = new int[len];
	for (size_t i = 0; i < len; i++)
		mas[i] = B.mas[i];
	return *this;
}

masclass& masclass::operator=(masclass&& B)
{
	std::cout << "Operator =\n";
	len = B.len;
	mas = B.mas;
	B.mas = nullptr;
	return *this;
	// TODO: вставьте здесь оператор return
}
