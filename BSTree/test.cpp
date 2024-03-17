#define  _CRT_SECURE_NO_WARNINGS
#include"BSTree.h"


using namespace guagua;
int main()
{
	BSTree<int> B;
	B.Insert(0);
	B.Insert(2);
	B.Insert(1);
	B.Insert(4);
	B.Insert(3);
	int ret=B.Find(6);
	cout << ret << endl;
	B.InOrder();
	B.Erase(3);
	B.InOrder();
	return 0;
}