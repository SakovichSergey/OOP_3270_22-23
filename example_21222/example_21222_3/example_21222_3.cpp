// example_21222_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <thread>

class timeChart
{
public:
	void operator()(void (*f)(int* mas), int*mas)
	{
		auto start = std::chrono::steady_clock::now();
		f(mas);
		auto finish = std::chrono::steady_clock::now();
		std::cout << "time=" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "mcs\n";
	}
};
void init(int* mas)
{
	for (int i = 0; i < 100000; i++)
		mas[i] = 100000 - i;
}
void quickSort(int* mas, int start, int finish)
{
	int i = start;
	int j = finish - 1;
	int  midVal = mas[(j + i) / 2];
	do {

		while (mas[i] < midVal) i++;
		while (mas[j] > midVal) j--;
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > start)
	{
		quickSort(mas, start, j);
	}
	if (i < finish)
	{
		quickSort(mas, i, finish);
	}
}
void quickThreadSort(int* mas, int start, int finish)
{
	int i = start;
	int j = finish - 1;
	int  midVal = mas[(j + i) / 2];
	do {

		while (mas[i] < midVal) i++;
		while (mas[j] > midVal) j--;
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (i < j)
	{
		std::thread* pool = new std::thread[2];
		pool[0] = std::thread(quickThreadSort, mas, start, j + 1);
		pool[1] = std::thread(quickThreadSort, mas, i - 1, finish);
		if (j > start)
		{
			pool[0].join();
		}
		if (i < finish)
		{
			pool[1].join();
		}
	}
}
int main()
{
	int* mas = new int[100000];
	//timeChart()(init, mas);
	auto start = std::chrono::steady_clock::now();
	init(mas);
	auto finish = std::chrono::steady_clock::now();
	std::cout << "time=" << std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count() << "mcs\n";
	delete[] mas;
	mas = new int[100000];
	std::thread t(init, mas);
	auto start1 = std::chrono::steady_clock::now();
	t.join();
	auto finish1 = std::chrono::steady_clock::now();
	std::cout << "time=" << std::chrono::duration_cast<std::chrono::microseconds>(finish1 - start1).count() << "mcs\n";
	auto start2 = std::chrono::steady_clock::now();
	quickSort(mas, 0, 100000);
	auto finish2 = std::chrono::steady_clock::now();
	std::cout << "time=" << std::chrono::duration_cast<std::chrono::microseconds>(finish2 - start2).count() << "mcs\n";
	delete[] mas;
	mas = new int[100000];
	init(mas);
	auto start3 = std::chrono::steady_clock::now();
	quickThreadSort(mas, 0, 100000);
	auto finish3 = std::chrono::steady_clock::now();
	std::cout << "time=" << std::chrono::duration_cast<std::chrono::microseconds>(finish3 - start3).count() << "mcs\n";

    
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
