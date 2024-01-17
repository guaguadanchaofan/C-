#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>


namespace guagua
{
	class string
	{
	public:

		//������
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}


		//���캯��
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}


		//���캯�� s2(s1) ��ͳд��
		/*string(const string& s)
		{
			_str = new char[s._capacity + 1];
			_size = s._size;
			_capacity = s._capacity;
			strcpy(_str, s._str);
		}*/


		//����
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}


		//�������캯��s2(s1)  �ִ�д��
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str);
			//this->swap(tmp);
			swap(tmp);
		}


		//s1=s2(��ͳд��)
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


		//s1=s2(swapд��)
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				swap(tmp);
			}
			return *this;
		}*/


		//s1=s2�ִ�д��
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}


		//����c�ַ�����Ԫ�ص�ַ
		const char* c_str()const
		{
			return _str;
		}


		//�����ַ�����С
		size_t size()const
		{
			return _size;
		}


		//�����ַ�������
		size_t capacity()const
		{
			return _capacity;
		}


		//��ͨ����:�ɶ���д
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}


		//const����ֻ��
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}


		//��������
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


		//���Ĵ�С
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


		//�ַ�β��(����)
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


		//�ַ���β��(�ַ���)
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


		//+=���أ��ַ���
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}


		//+=���أ��ַ�����
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		//�����ַ�
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


		//�����ַ���
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


		//ɾ���ַ�
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


		//�����ַ�λ��
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

		//�����ַ���λ��
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

		
		//��������
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
			// ����
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
