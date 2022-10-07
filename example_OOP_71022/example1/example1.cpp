// example1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void firstFunc(int* ptr) //legacy
{
	*ptr += 1;
	//return *ptr * 2;
}
void secondFunc(int value[25000])
{
	for (int i = 0; i < 25000; i++)
		value[i] = i;
	std::cout << value[24999] << "\t" << &value << std::endl;
}

int main()
{
	//int three;
	int value = 3, anyVal = 5;
	int* someValue = &value;
	*someValue = 10;
	std::cout << value << "\t" << &value << std::endl;
	std::cout << someValue << "\t" << &someValue << std::endl;
	firstFunc(someValue);
	std::cout << someValue << "\t" << &someValue << "\t" << value << "\t" << &value << std::endl;
	int val[25000];
	for (int i = 0; i < 25000; i++)
		val[i] = 0;
	secondFunc(val);
	const int* ptr;// указатель на неизменяемое значение
	ptr = &value;
	std::cout << *ptr << std::endl;
	//*ptr = *ptr + 1; //E0137
	ptr = &anyVal;
	std::cout << *ptr << std::endl;
	int* const ptr2 = &value; // неизменяемый указатель на изменяемое значение
	std::cout << *ptr2 << std::endl;
	*ptr2 = *ptr2 + 1;
	std::cout << value << std::endl;
	//ptr2 = &anyVal;//E0137
	const int* const ptr3 = &value;//неизменяемый указатель на неизменяемое значение
	//ptr3 = &anyVal;//E0137
	//*ptr3 = *ptr3 + 1;//E0137
	
	/* C++98:
		lvalue = rvalue;
		lvalue - '}'
		rvalue - ';'
	*/
	//lvalue     //rvalue
	int x   =    2 + 3;
	//three = 3;
	/*
	C++11
				gvalue		rvalue
		lvalue		xvalue		prvalue
		&value - lvalue reference;
		&&value - rvalue reference;
		
	*/
	int&& refVal{ 42 };

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
