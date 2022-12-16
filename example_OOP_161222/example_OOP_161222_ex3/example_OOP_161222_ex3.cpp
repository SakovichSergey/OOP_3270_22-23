#include "pch.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	int value = 0;
	Console::Write(value);
	Console::WriteLine("Hello world\t" + value + " something yet!");
	int var = Convert::ToInt32(Console::ReadLine());
	Console::WriteLine("Значение=" + var);
	return 0;
}
