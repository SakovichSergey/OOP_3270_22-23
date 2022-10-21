// example6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>
template<class T>
void print(T str)
{
	std::cout << str;
}
template<class T>
void println(T str)
{
	std::cout << str << std::endl;
}
int main()
{
	std::map<int, int> N;
	int n = rand() % 100;
	print("size:"); println(n);
	for (auto i = 0; i < n; i++)
	{
		int t = rand() % 10;
		N[t] = i;
	}
	println("Out map");
	std::map<int, int> ::iterator I;
	int k = 0;
	for (I = N.begin(); I != N.end(); I++)
	{
		std::cout << k << " \t Key:" << I->first << " \t Value:" << I->second << std::endl;
		k++;
	}
	k = 0;
	println("Out map");
	for (I = N.begin(); I != N.end(); I++)
	{
		std::cout << k << " \t Key:" << I->first << " \t Value:" << I->second << std::endl;
		k++;

	}
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
