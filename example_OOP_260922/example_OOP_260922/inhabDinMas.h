#pragma once
class inhabDinMas
{
protected:
	int* mas;
	int length;
public:
	inhabDinMas(int Length);
	~inhabDinMas();
	
};
class Owner : public inhabDinMas
{
public:
	Owner(int Length);
	~Owner();
	void initMasValue();
	void sumOfMasValue();
};

