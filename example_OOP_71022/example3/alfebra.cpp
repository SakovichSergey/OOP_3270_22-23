#include "alfebra.h"

algebra algebra::operator+()
{
    return algebra(std::abs(a));
}

algebra algebra::operator-()
{
	return algebra(-a);
}

algebra algebra::operator+(algebra b)
{
	return algebra((a+b.a));
}

algebra algebra::operator-(algebra b)
{
	return algebra(a-b.a);
}

algebra algebra::operator*(algebra b)
{
	return algebra(a*b.a);
}

algebra algebra::operator/(algebra b)
{
	return algebra(a/b.a);
}

bool algebra::operator<(algebra b)
{
	return a<b.a;
}

std::ostream& operator<<(std::ostream& out, const algebra& a)
{
	out << a.a;
	return out;
}