#pragma once
#include<iostream>
class algebra
{
	int a;
public:
	algebra(int A):a(A){}
	int get_a() { return a;}
	algebra operator+();
	algebra operator-();
	algebra operator+(algebra b);
	algebra operator-(algebra b);
	algebra operator*(algebra b);
	algebra operator/(algebra b);
	bool operator<(algebra b);
	friend std::ostream& operator<<(std::ostream& out, const algebra& a);

};

