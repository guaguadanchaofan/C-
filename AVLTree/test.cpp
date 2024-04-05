#define  _CRT_SECURE_NO_WARNINGS
#include"AVLTree.h"
using namespace std;
int main()
{
	guagua::AVLTree<int, string> vk;
	vk.Insert(pair<int, string>(2, "two"));
	vk.Insert(pair<int, string>(3, "three"));
	vk.Insert(pair<int, string>(4, "four"));
	vk.Insert(pair<int, string>(5, "five"));
	vk.Insert(pair<int, string>(6, "five"));
	vk.Insert(pair<int, string>(7, "five"));
	vk.Insert(pair<int, string>(8, "five"));
	vk.Insert(pair<int, string>(9, "five"));
	vk.Insert(pair<int, string>(10, "five"));
	vk.Insert(pair<int, string>(11, "five"));
	vk.Inorder();
	return 0;
}