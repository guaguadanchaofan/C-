#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

#include"string.h"

//void test1()
//{
//	guagua::string s1 = "hello";
//	guagua::string s2;
//	s2 = s1;
//	cout << s2[1] << endl;
//	s2[1] = 'w';
//	cout << s2[1] << endl;
//	
//
//}
//void test2()
//{
//	guagua::string s1 = "hello";
//	guagua::string s2;
//	
//	s2.reserve(10);
//	s2.resize(10, 'x');
//	cout << s2.c_str() << endl;
//
//}
//void test3()
//{
//	guagua::string s1 = "hello";
//	guagua::string s2;
//
//	s2.reserve(10);
//	s2.resize(10, 'x');
//	s2.append("hello");
//	//cout << s2.c_str() << endl;
//	//s2.push_back('N');
//	//cout << s2.c_str() << endl;
//	s2 += ' ';
//	cout << s2.c_str() << endl;
//	s2 += "world";
//	cout << s2.c_str() << endl;
//}
//void test4()
//{
//	guagua::string s1 = "hello";
//	guagua::string s2(s1);
//
//	s2.insert(2, 's');
//	cout << s2.c_str() << endl;
//	s2.erase(2, 's');
//	cout << s2.c_str() << endl;
//}
void test5()
{
	guagua::string s1 = "hello";
	guagua::string s2(s1);

	/*s2.insert(2, 's');
	cout << s2.c_str() << endl;
	s2.erase(2, 1);
	cout << s2.c_str() << endl;
	cout << s2.find("e") << endl;
	cout << s2.find("ello") << endl;*/
	cout << s1 << endl;;


}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}