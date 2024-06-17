#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"HashTable.h"


int main()
{
	closehash::HashTable<int, int> ht;
	int a[] = { 18, 8, 7, 27, 57, 3, 38, 18 };
	for (auto& e : a)
	{
		ht.Insert(std::make_pair(e,e));
	}
	return 0;
}
