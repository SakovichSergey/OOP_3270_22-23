// example_OOP_181122_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
std::string sumOfStringsNumber(std::string str1, std::string str2);
int main()
{
	std::string str0 = "Hello world\n";
    std::cout << str0;
	std::string str1 = "";
	str1 += "Hello";
	str1 += " world";
	str1 +="2\n";
	std::cout << str1;
	auto  str3 = str0;
	str3.at(0) = 'R';
	std::cout << str3;
	for(auto I : str3)
		std::cout << I << "\n";
	std::string str4 = "9234567898765432123456789";
	std::string str5 = "1234567898765432123456789";
	std::cout << sumOfStringsNumber(str4, str5)<<"\n";
	std::string str6 = "hello_world";
	size_t count = str6.find("_");
	std::cout << count << "\n";
	std::cout << str6.substr(0, count) << " "<< str6.substr(count+1);
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

std::string sumOfStringsNumber(std::string str1, std::string str2)
{
	int length = (str1.length() >= str2.length()) ? str1.length() : str2.length();
	int perenos = 0;
	std::string result = "";
	for (int i = 0; i < length; i++)
	{
		int fval = str1.at(length-1-i) - '0';
		int sval = str2.at(length-1-i) - '0';
		if(fval>=0 && fval <10)
			if (sval >= 0 && sval < 10)
			{
				int res = fval + sval+perenos;
				perenos = res / 10;
				result += (res % 10)+'0';
			}
	}
	if (perenos == 1) result += '1';
	std::string tmp = "";
	for (int i = 0; i < result.length(); i++)
	{
		tmp += result[(result.length()-1) - i];
	}
	return tmp;
}
