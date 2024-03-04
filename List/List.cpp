#define  _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include<iostream>
#include<string>


using namespace std;
using namespace guagua;


int main()
{
	list<int> it1;
	it1.push_back(1);
	it1.push_back(2);
	it1.push_back(3);
	it1.push_back(4);
	it1.push_back(5);
	it1.push_back(6);
	it1.push_front(7);
	it1.pop_back();
	it1.pop_front();
	list<int>::iterator it = it1.begin();
	while (it != it1.end())
	{
		cout << *it << " ";
		++it;
	}
	return 0;
}