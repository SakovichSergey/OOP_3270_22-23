#pragma once
class owningexample
{
public:
	owningexample(int i, int j);
	~owningexample();
	int GetIValue();
	void SetIValue(int i);
private:
	int I;
protected:
	int J;
};
class owner :protected owningexample
{
public:
	owner(int i, int j);
	~owner();
	int GetJValue();
	void SetJValue(int j);
	void PrintValue();
	void InputIValue();
};
