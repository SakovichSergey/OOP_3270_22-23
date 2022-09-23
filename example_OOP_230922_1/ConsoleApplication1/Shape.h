#pragma once
#include<iostream>
class Shape
{
	public:
	std::string str;
	Shape(std::string nameShape)
	{
		str = nameShape;
	}
	virtual double GetArea() = 0;
	virtual double GetPerimetr() = 0;
};
class Circle : public Shape
{
	int radius=0;
public:
	Circle(int r) :radius(r),Shape("Circle"){ }
	double GetArea();
	double GetPerimetr();
};
class Rectangle : public Shape
{
	int width, higth;
public:
	Rectangle(int w, int h):width(w),higth(h),Shape("Rectangle"){}
	double GetArea();
	double GetPerimetr();
};
class Triangle :public Shape
{
	int aLength, bLength, cLength;
public:
	Triangle(int a, int b, int c):aLength(a),bLength(b),cLength(c),Shape("Triangle"){}
	double GetArea();
	double GetPerimetr();
};

