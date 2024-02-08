#include "vector.h"
#include<iostream>
#include<string>
#include<assert.h>

using namespace std;
using namespace guagua;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	for (auto e : v)
	{
		cout << e<<" ";
	}
	v.reserve(8);
	return 0;
}
