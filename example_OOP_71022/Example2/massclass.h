#pragma once
#include <iostream>
class masclass
{
public:
	masclass() = default;
	masclass(int length);
	masclass(const masclass& A);
	masclass(masclass&& A) noexcept;
	~masclass();
	void outputMas();
	int summOfVal();
	masclass& operator=(const masclass& B);
	masclass& operator=(masclass&& B);
private:
	int len;
	int* mas;
};

