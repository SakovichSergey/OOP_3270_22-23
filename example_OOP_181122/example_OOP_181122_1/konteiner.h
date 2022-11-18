#pragma once
#include<iostream>
template<class T>
class konteiner
{
	int n;
	T* mas;
public:
	konteiner(int count);
	~konteiner();
	void print();
	void quickSort(int start, int finish);
};

template<class T>
inline konteiner<T>::konteiner(int count)
{
	n = count;
	mas = new T[n];
	if(typeid(mas) == typeid(int*))
			for (auto i = 0; i < n; i++)
			{
				mas[i] = rand() % 10;
			}
	else if(typeid(mas) == typeid(double*))
			for (auto i = 0; i < n; i++)
			{
				mas[i] = 1.0*(rand() % 10)/(rand()%10+1);
			}
	else if (typeid(mas) == typeid(char*))
	{
		int grow = 'z' - 'A';
		for (auto i = 0; i < n; i++)
		{
			mas[i] = rand() % grow + 'A';
		}
	}
	else
	{
		delete[] mas;
		mas = nullptr;
	}
}

template<class T>
inline konteiner<T>::~konteiner()
{
	delete[] mas;
}

template<class T>
inline void konteiner<T>::print()
{
	if(mas != nullptr)
	for (auto i = 0; i < n; i++)
	{
		std::cout << mas[i] << "\t";
	}
	std::cout << "\n";
}

template<class T>
inline void konteiner<T>::quickSort(int start, int finish)
{
	int i = start;
	int j = finish - 1;
	T  midVal = mas[(j + i) / 2];
	do {

		while (mas[i] < midVal) i++;
		while (mas[j] > midVal) j--;
		if (i <= j) {
			T tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > start) quickSort(start, j + 1);
	if (i < finish) quickSort(i, finish);
}
