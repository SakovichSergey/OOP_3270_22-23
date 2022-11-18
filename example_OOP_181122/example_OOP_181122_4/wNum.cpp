#include "wNum.h"
#include <iostream>
wNum::wNum(int count)
{
	n = count;
	mas = new int[n];
	for (int i = 0; i < n;i++)
		mas[i] = rand() % 100 + 1;
}

void wNum::elCount()
{
	for (int i = 0; i < n; i++)
	{
		if (mas[i] < 50)
			fEvent();
		else sEvent();
	}
	cnt = 0;
}

void Observer::message1()
{
	std::cout << cnt << " Value is less 50\n"; cnt++;
}

void Observer::message2()
{
	std::cout << cnt << " Value is above 50\n"; cnt++;
}
