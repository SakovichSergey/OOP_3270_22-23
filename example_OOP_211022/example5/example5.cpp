// example5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
template<class T>
void print(T str)
{
	std::cout << str ;
}
template<class T>
void println(T str)
{
	std::cout << str << std::endl;
}
bool myfunction(int i, int j) { return (i > j); }
int main()
{
	std::vector<int> A;
	A.push_back(1);
	println(A[0]);
	println(A.at(0));
	print("Size:");
	println(A.size());
	print("Capasity:");
	println(A.capacity());
	print("Max_Length:");
	println(A.max_size());
	A.resize(10);
	print("Size:");
	println(A.size());
	print("Capasity:");
	println(A.capacity());
	print("Max_Length:");
	println(A.max_size());
	A.push_back(2);
	print("Size:");
	println(A.size());
	print("Capasity:");
	println(A.capacity());
	print("Max_Length:");
	println(A.max_size());
	std::for_each(A.begin(), A.end(), println<int>);
	println("Vector B");
	std::vector<int> B;
	for (int i = 0; i < 10; i++)
		B.push_back(rand() % 10 + 1);
	auto func = [](const std::vector<int> A) {std::for_each(A.begin(), A.end(), println<int>); };
	func(B);
	println("Sort min->max");
	std::sort(B.begin(), B.end());
	func(B);
	println("Sort max->min");
	std::sort(B.begin(), B.end(), myfunction);
	func(B);
	println("Sort min->max");
	std::sort(B.begin(), B.end(), std::less<int>{});
	func(B);
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
