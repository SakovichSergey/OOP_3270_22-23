// example_OOP_21222_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <future>
int addValue(int fVal, int sVal)
{
	return fVal + sVal;
}
void addValueB(int fVal, int sVal, int* res)
{
	*res = addValue(fVal, sVal);
}
int main()
{
	std::cout << addValue(2, 3) << "\n";
	auto val1 = std::async(std::launch::async, addValue, 3, 5);
	std::cout << val1.get() << "\n";

	std::atomic<int> val2{ 0 };
	std::thread th1([&val2]() {val2 = addValue(5, 7); });
	th1.join();
	std::cout << val2 << "\n";

	std::packaged_task<int(int, int)> task(addValue);
	auto val3 = task.get_future();
	std::thread th2(std::move(task), 7, 11);
	th2.join();
	std::cout << val3.get() << "\n";

	int* val4 = new int();
	std::thread th3(addValueB, 11, 13, std::ref(val4));
	th3.join();
	std::cout << *val4 << "\n";
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
