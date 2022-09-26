#pragma once
class incDinMas
{
	int* mas;
	int length;
public:
	incDinMas(int Length);
	~incDinMas();
	void sumOfMasEl();
private:
	void initMasValue();
};

