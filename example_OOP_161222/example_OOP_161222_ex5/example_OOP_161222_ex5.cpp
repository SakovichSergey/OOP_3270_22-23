#include "pch.h"
#include "funcTabulation.h"
using namespace System;

int main(array<System::String ^> ^args)
{
	funcTabulation ^A;
	A = gcnew funcTabulation(Console::ReadLine(), Console::ReadLine(), Console::ReadLine());
	A->tabulation();
    return 0;
}
