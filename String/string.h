#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>


namespace guagua
{
	class string
	{
	public:

		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}


		//构造函数
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}


		//构造函数 s2(s1) 传统写法
		/*string(const string& s)
		{
			_str = new char[s._capacity + 1];
			_size = s._size;
			_capacity = s._capacity;
			strcpy(_str, s._str);
		}*/


		//交换
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}


		//拷贝构造函数s2(s1)  现代写法
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str);
			//this->swap(tmp);
			swap(tmp);
		}


		//s1=s2(传统写法)
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[]_str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}*/


		//s1=s2(swap写法)
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				swap(tmp);
			}
			return *this;
		}*/


		//s1=s2现代写法
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}


		//返回c字符串首元素地址
		const char* c_str()const
		{
			return _str;
		}


		//返回字符串大小
		size_t size()const
		{
			return _size;
		}


		//返回字符串容量
		size_t capacity()const
		{
			return _capacity;
		}


		//普通对象:可读可写
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}


		//const对象：只读
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}


		//更改容量
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}


		//更改大小
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] ='\0';
			}
			else
			{
				_str[n] = '\0';
				_size = n;
			}
		}


		//字符尾插(单个)
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}


		//字符串尾插(字符串)
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size+len > _capacity)
			{
				reserve(_size+len);
			}
			strcpy(_str+_size, str);
			_size += len;

		}


		//+=重载（字符）
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}


		//+=重载（字符串）
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//插入字符
		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;
			return *this;
		}


		//插入字符串
		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			strncpy(_str + len, str, len);
			_size += len;

			return *this;
		}


		//删除字符
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}


		//查找字符位置
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			while (pos < _size)
			{
				if (_str[pos] == ch)
				{
					return pos;
				}
				pos++;
			}
			return npos;
		}

		//查找字符串位置
		size_t find(const char* str, size_t pos = 0) const
		{
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

		
		//析构函数
		~string()
		{
			delete []_str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1;
	};
}

ostream& operator<< (ostream& out, const string s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		out << s[i];
	}
	/*for (auto ch : s)
	{
		out << ch;
	}*/


	return out;
}

istream& operator>>(istream& in, string& s)
{
	s.clear();
	//char ch = in.get();
	//while (ch != ' ' && ch != '\n')
	//{
	//	s += ch;
	//	//in >> ch;
	//	ch = in.get();
	//}

	char buff[128] = { '\0' };
	size_t i = 0;
	char ch = in.get();
	while (ch != ' ' && ch != '\n')
	{
		if (i == 127)
		{
			// 满了
			s += buff;
			i = 0;
		}

		buff[i++] = ch;

		ch = in.get();
	}

	if (i > 0)
	{
		buff[i] = '\0';
		s += buff;
	}

	return in;
}
