#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"bitset.h"

using namespace std;

void test_bitset()
{
	guagua::bitset<200> set;
	int a[] = { 3, 5, 6, 7, 8, 9, 33, 55, 67, 3, 3, 3, 5, 9, 33 };
	for (auto e : a)
	{
		set.set(e);
	}
	cout << set.test(3) << endl;
	set.reset(3);
	cout << set.test(3) << endl;
	cout << set.test(88) << endl;
	cout << set.test(88) << endl;
	cout << set.test(99) << endl << endl;
}
int main()
{

	test_bitset();
	return 0;
}