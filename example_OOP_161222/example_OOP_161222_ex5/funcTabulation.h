#pragma once
using namespace System;
ref class funcTabulation
{
public:
	double start;
	double step;
	double finish;
	funcTabulation(String^,String^,String^);
	void tabulation();
	double function(double xVal);
};

