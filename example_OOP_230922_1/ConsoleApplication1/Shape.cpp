#include "Shape.h"
#include <corecrt_math.h>
double Circle::GetArea()
{
    return 3.141592*radius*radius;
}

double Circle::GetPerimetr()
{
	return 3.141592*2*radius;
}

double Rectangle::GetArea()
{
	return width*higth;
}

double Rectangle::GetPerimetr()
{
	return 2*(higth+width);
}

double Triangle::GetArea()
{
	double p = this->GetPerimetr() / 2;
	return sqrt(p*(p-aLength)* (p - bLength)* (p - cLength));
}

double Triangle::GetPerimetr()
{
	return 1.0*aLength+bLength+cLength;
}
