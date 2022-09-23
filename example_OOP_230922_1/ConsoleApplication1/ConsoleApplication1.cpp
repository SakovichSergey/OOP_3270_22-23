// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include "Personn.h"
#include "owningexample.h"
#include "Shape.h"
void Exampl1();
void Exampl2();
void Exampl3();
void OutputDate(std::string str, Shape* shape);
void OutputDate(Shape* shape);
int main()
{
	auto startTime = std::chrono::steady_clock::now();
	//Exampl1();
	//Exampl2();
	Exampl3();
	auto finishTime = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count() << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

void Exampl1()
{
	Personn p1;
	p1.age = 21;
	p1.name = "Misha";
	p1.print();
	Personn* p2;
	p2 = new Personn();
	p2->age = 22;
	p2->name = "Masha";
	p2->print();
}

void Exampl2()
{
	owningexample A(1, 2);
	A.SetIValue(3);
	std::cout << A.GetIValue() << "\n";
	owner B(3, 4);
	/*B.SetIValue(5);
	std::cout << B.GetIValue() << "\n";*/
	B.SetJValue(7);
	std::cout << B.GetJValue() << "\n";
	B.InputIValue();
	B.PrintValue();
}

void Exampl3()
{
	Circle A(3);
	Rectangle B(5, 7);
	Triangle C(3, 5, 7);
	std::cout << "Circle \tS=" << A.GetArea() 
		<< "\tP=" << A.GetPerimetr() << std::endl;
	std::cout << "Rectangle \tS=" << B.GetArea()
		<< "\tP=" << B.GetPerimetr() << std::endl;
	std::cout << "Triangle \tS=" << C.GetArea()
		<< "\tP=" << C.GetPerimetr() << std::endl;
	Shape* shape;
	shape = new Circle(3);
	std::cout << "Shape:Circle \tS=" << shape->GetArea()
		<< "\tP=" << shape->GetPerimetr() << std::endl;
	OutputDate("Circle", shape);
	OutputDate(shape);
	delete shape;
	shape = new Rectangle(5, 7);
	std::cout << "Shape:Rectangle \tS=" << shape->GetArea()
		<< "\tP=" << shape->GetPerimetr() << std::endl;
	OutputDate("Rectangle", shape);
	OutputDate(shape);
	delete shape;
	shape = new Triangle(3, 5, 7);
	std::cout << "Shape:Triangle \tS=" << shape->GetArea()
		<< "\tP=" << shape->GetPerimetr() << std::endl;
	OutputDate("Triangle", shape);
	OutputDate(shape);
	delete shape;
}

void OutputDate(std::string str, Shape* shape)
{
	std::cout << "Shape:"<< str<< "\tS = " << shape->GetArea()
		<< "\tP=" << shape->GetPerimetr() << std::endl;
}

void OutputDate(Shape* shape)
{
	std::cout << "Shape:" << shape->str << "\tS = " << shape->GetArea()
		<< "\tP=" << shape->GetPerimetr() << std::endl;
}

