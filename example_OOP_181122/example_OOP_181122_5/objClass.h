#pragma once
#include <iostream>
class objClass
{
	int a;
public:
	objClass(int A):a(A){}
	virtual void get_A()
	{
		std::cout << a << "\n";
	}
};
class strClass : public objClass
{
	std::string str;
public:
	strClass(int A, std::string STR) :objClass(A),str(STR) {}
	 void get_A()
	{
		 objClass::get_A();
		std::cout << str << "\n";
	}
};

