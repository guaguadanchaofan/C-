#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"RBTree.h"



int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int, int> RB;
	for (int i =0;i < 8;i++)
	{
		RB.Insert(std::make_pair(a[i], a[i]));
	}
	RB.Insert(std::make_pair(1, 1));
	RB.Inorder();
	std::cout<<RB.Isblance()<<std::endl;
	return 0;
}