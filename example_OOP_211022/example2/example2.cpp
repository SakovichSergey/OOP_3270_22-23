// example2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
class print
{
public:
	void operator()(int x)
	{
		std::cout << x << "\n";
	}
	void operator()(const char* str)
	{
		std::cout << str;
	}
};
static print println;
class Point
{
	int x, y;
public:
	Point(int X,int Y):x(X),y(Y){}
	void outPoint()
	{
		[this]() {println("Point::x = "); println(x); println("Point::y = "); println(y); }();
	}
};
int main()
{
	//Лямбда - выражения
	[](){println("Lambda expression!\n"); }();
	//[] - блок захвата
	//() - блок списка формальных аргументов
	//{} - блок кода
	//() - вызов лямбда выражения
	int aVal = 0;
	[](int value){value++; println(value); }(aVal);
	println(aVal);
	[](int* ptr) {(* ptr)++; println(*ptr); }(&aVal);
	println(aVal);
	[](int& lptr) {lptr++; println(lptr); }(aVal);
	println(aVal);
	auto bVal = [](int& lptr) {lptr++; return lptr; }(aVal);
	println(bVal);
	println(aVal);
	auto func = [](int& lptr){lptr++; return lptr; };
	auto cVal = func(bVal);
	auto dVal = func(bVal);
	println(cVal);
	println(dVal);
	println(bVal);
	[cVal, dVal]() {auto eVal = cVal + dVal; println(eVal); }();
	[cVal, &dVal]() {dVal = cVal + dVal; println(dVal); }();
	println(dVal);
	[&]() {auto fVal = aVal + bVal + cVal; cVal++; println(fVal); }();
	println(cVal);
	[=]() {/*aVal++;*/auto fVal = aVal + bVal + cVal; println(fVal); }();
	Point p(11, 13);
	p.outPoint();
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
