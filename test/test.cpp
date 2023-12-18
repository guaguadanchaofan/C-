#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Time
{
private:
	int _d;
	int _e;
};


class num
{
public:
	void print()
	{
		cout << _a << _b << _c << endl;
	}
private:
	int _a;
	int _b;
	int _c;
	Time t1;
};
int main()
{
	num n1;
	n1.print();
}