#include "pch.h"
#include "funcTabulation.h"

funcTabulation::funcTabulation(String^ start, String^ step, String^ finish)
{
	this->start = Convert::ToDouble(start);
	this->step = Convert::ToDouble(step);
	this->finish = Convert::ToDouble(finish);
}

void funcTabulation::tabulation()
{
	for (start; start < finish; start += step)
		Console::WriteLine("start="+start+"\tvalue="+function(start));
}

double funcTabulation::function(double xVal)
{
	return Math::Pow(Math::Sqrt(xVal*Math::PI),Math::E);
}
