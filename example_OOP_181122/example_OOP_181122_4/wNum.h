#pragma once
static int cnt = 0;
class wNum
{
	int n;
	int* mas;
public:
	wNum(int count);
	void (*fEvent)();
	void (*sEvent)();
	void elCount();
};
class Observer
{
public:
	static void message1();
	static void message2();
};
