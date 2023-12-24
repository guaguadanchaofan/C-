#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iterator>
#include <stdio.h>
using namespace std;
class Data
{
public:
	int GetmonthDay(int year, int month)
	{
		int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((month == 2) && year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			return 29;
		}
		return arr[month];
	}
	Data(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0 &&
			month >= 1 && month <= 12
			&& day >= 1 && day <= GetmonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期错误" << endl;
		}
	}
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//  >
	bool operator>(const Data& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		return false;
	}
	//  <
	bool operator<(const Data& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}
		return false;
	}
	//  ==
	bool operator==(const Data& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	//  >=
	bool operator>=(const Data& d)
	{
		return !(*this < d);
	}
	//  <=
	bool operator<=(const Data& d)
	{
		return !(*this > d);
	}
	//  !=
	bool operator!=(const Data& d)
	{
		return !(*this == d);
	}
	//  =
	Data& operator=(const Data& d)
	{
		if (*this != d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//  +=
	Data& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= (-day);
		}
		_day += day;
		while (_day > GetmonthDay(_year, _month))
		{
			_day -= GetmonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	//  +
	Data operator+(int day)
	{
		Data tmp = *this;
		tmp += day;
		return tmp;
	}
	// -=
	Data& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += (-day);
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetmonthDay(_year, _month);
		}
		return *this;
	}
	//  -
	Data operator-(int day)
	{
		Data tmp = *this;
		tmp -= day;
		return tmp;
	}
	//  --(前置)
	Data& operator--()
	{
		*this -= 1;
		return *this;
	}
	// --(后置)
	Data& operator--(int)
	{
		*this -= 1;
		return *this;
	}
	//  ++(前置)
	Data& operator++()
	{
		*this += 1;
		return *this;
	}
	//  ++(后置)
	Data& operator++(int)
	{
		*this += 1;
		return *this;
	}
	~Data()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main() {
	int a, b;
	int year, month, day, year1, month1, day1;
	scanf("%4d%2d%2d", &year, &month, &day);
	scanf("%4d%2d%2d", &year1, &month1, &day1);
	Data d1(year, month, day);
	Data d2(year1, month1, day1);
	int count = 0;
	while (d1 != d2)
	{
		d1++;
		count++;
	}
	cout << count + 1 << endl;
}
// 64 位输出请用 printf("%lld")