#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//class Data
//{
//public:
//	Data(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Data(const Data& d)
//	{
//		_year =d._year;
//		_month =d._month;
//		_day = d._day;
//	}
//	bool operator>(const Data& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//		return false;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	~Data()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Data d1(2023, 12, 20);
//	Data d2(d1);
//	Data d3(2022, 12, 23);
//	d1.print();
//	d2.print();
//	d3.print();
//	cout << (d3 > d2) << endl;
//	return 0;
//}
class Data
{
public:
	int GetmonthDay(int year,int month)
	{
		int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
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
			cout << "ÈÕÆÚ´íÎó" << endl;
		}
	}
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
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
	bool operator==(const Data& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator>=(const Data& d)
	{
		return !(*this < d);
	}
	bool operator<=(const Data& d)
	{
		return !(*this > d);
	}
	bool operator!=(const Data& d)
	{
		return !(*this == d);
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
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
int main()
{
	Data d1(2023, 12, 20);
	Data d2(d1);
	Data d3(2023, 12, 20);
	d1.print();
	d2.print();
	d3.print();
	/*cout << (d1 > d3) << endl;
	cout << (d1 < d3) << endl;
	cout << (d1 == d3) << endl;
	cout << (d1 >= d3) << endl;
	cout << (d1 <= d3) << endl;
	cout << (d1 != d3) << endl;*/
	int i= d1 - d2;
	cout << i << endl;
	return 0;
}