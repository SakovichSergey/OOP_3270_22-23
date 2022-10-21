// example3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
template<class T>
void print(T str)
{
	std::cout << str;
}
int main()
{
	print("Hello template!\n");
	print(11);
	print("\n");
	print(3.141592);
	auto sTime = std::chrono::steady_clock::now();
	print("\nHello world!\n");
	auto fTime = std::chrono::steady_clock::now();
	print(std::chrono::duration_cast<std::chrono::nanoseconds>(fTime - sTime).count());
	auto sTime1 = std::chrono::steady_clock::now();
	std::cout << "\nHello world\n";
	auto fTime1 = std::chrono::steady_clock::now();
	print(std::chrono::duration_cast<std::chrono::nanoseconds>(fTime1 - sTime1).count());
	auto dVal = 3.141592;
	auto& dPtr = dVal;
	print("\n");
	print(&dVal); print("\n");
	print(&dPtr);
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
