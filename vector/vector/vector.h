#pragma once


namespace guagua
{
    template<class T>
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator begin()const
        {
            return _start;
        }
        const_iterator end()const
        {
            return _finish;
        }

        //[]重载
        T& operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }
        //const[]重载
        const T& operator[](size_t pos) const
        {
            assert(pos < size());
            return _start[pos];
        }
        //构造函数
        vector()
            : _start(nullptr)
            , _finish(nullptr)
            , _endofstorage(nullptr)
        {}
        //V1(V2)拷贝构造
        vector(const vector <T>& v)
            : _start(nullptr)
            , _finish(nullptr)
            , _endofstorage(nullptr)
        {
            reserve(v.capacity());
            for (auto& e : v)
            {
                push_back(e);
            }

        }
        //vector<int>  v1(10,1)
        //vector<string> v2(10,'A')
        vector(size_t n, const T& v = T())
            :_start(nullptr)
            , _finish(nullptr)
            ,_endofstorage(nullptr)
        {
            reserve(n);
            for (int i = 0; i < n; i++)
            {
                push_back(v);
            }
        }
        size_t capacity()
        {
            return _endofstorage - _start;
        }
        size_t size()
        {
            return _finish - _start;
        }

        void push_back(const T& val)
        {
            if (_finish == _endofstorage)
            {
                size_t newcapacity = capacity() == 0 ? 2 : (_finish - _start) * 2;
                reserve(newcapacity);
            }
            *_finish = val;
            ++_finish;
        }
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t oldsize = size();
                T* tmp = new T[n];
                if (_start)
                {
                    for (size_t i = 0; i < oldsize; i++)
                    {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = tmp + oldsize;
                _endofstorage = tmp + n;
            }
        }
        void resize(size_t n, T val= T())
        {
            if (n > capacity())
            {
                reserve(n);
            }
            if (n > size())
            {
                while (_finish < _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }
            else
            {
                _finish = _start + n;
            }
        }
        ~vector()
        {
            delete[] _start;
            _start = _finish = _endofstorage = nullptr;
        }
    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };
};
