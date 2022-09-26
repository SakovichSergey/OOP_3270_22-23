#pragma once
class polyDinMas
{ 
public:
	virtual void initDinMas() = 0;
	virtual void sumOfMasValue() = 0;
	polyDinMas();
	virtual ~polyDinMas()=0;
};
class intOwner : public polyDinMas
{
	int* mas;
	int length;
public:
	intOwner(int Length);
	~intOwner();
	void initDinMas();
	void sumOfMasValue();
};
class symbolOwner : public polyDinMas
{
	char* mas;
	int length;
public:
	symbolOwner(int Length);
	~symbolOwner();
	void initDinMas();
	void sumOfMasValue();
};

