// example4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
template<class T>
class Massiv
{
	T* mas;
	int length;
public:
	Massiv(int Length) :length(Length)
	{
		mas = new T[length];
	}
	~Massiv()
	{
		delete[] mas;
	}
	
	void initMas()
	{
		for (auto i = 0; i < length; i++)
			mas[i] = T();
	}
	void printMas();
};
template<>
void Massiv<int>::initMas()
{
	for (auto i = 0; i < length; i++)
		mas[i] = rand() % 100 + 1;
}
template<>
void Massiv<double>::initMas()
{
	for (auto i = 0; i < length; i++)
		mas[i] = (rand() % 100 + 1)/100.0;
}
template<>
void Massiv<char>::initMas()
{
	for (auto i = 0; i < length; i++)
		mas[i] = (rand() % 26+'A');
}

class point
{
	int x, y;
public:
	point()
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
	}
	friend std::ostream& operator<< (std::ostream& out, const point &p);
};

std::ostream& operator<< (std::ostream& out, const point& p)
{
	out << "Point:" << p.x << "\t" << p.y << "\n";
	return out;
}
int main()
{
	Massiv<int> A(5);
	A.initMas();
	A.printMas();
	Massiv<double> B(5);
	B.initMas();
	B.printMas();
	Massiv<char> C(6);
	C.initMas();
	C.printMas();
	Massiv<point> D(5);
	D.initMas();
	D.printMas();
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
template<class T>
void Massiv<T>::printMas()
{
	for (auto i = 0; i < length; i++)
	{
		std::cout << mas[i] << std::endl;
	}
}

