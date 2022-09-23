#include "owningexample.h"
#include <iostream>
owningexample::owningexample(int i, int j):I(i),J(j)
{
	std::cout << "Constructor base class\n";
}

owningexample::~owningexample()
{
	std::cout << "Destructor base class\n";
}

int owningexample::GetIValue()
{
	return I;
}

void owningexample::SetIValue(int i)
{
	I = i;
}

owner::owner(int i, int j):owningexample(i,j)
{
	std::cout << "Constructor owner class\n";
}

owner::~owner()
{
	std::cout << "Destructor owner class\n";
}

int owner::GetJValue()
{
	return J;// this->J;
}

void owner::SetJValue(int j)
{
	J = j;
}

void owner::PrintValue()
{
	std::cout << "I=" << this->GetIValue() 
		<< "\t J="<< J<<std::endl;
}

void owner::InputIValue()
{
	std::cout << "Input I value:";
	int i;
	std::cin >> i;
	this->SetIValue(i);
}
