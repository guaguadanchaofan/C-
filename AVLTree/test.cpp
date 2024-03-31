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
	return 0;
}