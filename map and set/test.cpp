#define  _CRT_SECURE_NO_WARNINGS

#include "Mymap.h"
#include "Myset.h"
int main()
{
	guagua::map<int, int> m;
	m.insert(make_pair(1, 11));
	m.insert(make_pair(2, 22));
	m.insert(make_pair(3, 33));
	m.insert(make_pair(4, 44));
	guagua::map<int,int>::iterator it1 = m.begin();
	while (it1 != m.end())
	{
		cout << it1->second << endl;
		++it1;
	}

	guagua::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	guagua::set<int>::iterator it2=s.begin();
	while (it2 != s.end())
	{
		cout << *it2 << endl;
		++it2;
	}
	return 0;
}