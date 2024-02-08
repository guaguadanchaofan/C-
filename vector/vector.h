#include<iostream>
#include<string>

namespace guagua;
{
  template<class T>
    class vector
    {
      Public:
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
        const_iterator begin()
        {
          return _start;
        }
        const_iterator end()
        {
          return _finish;
        }
        T& operator[](size_t pos)
        {
          assert(pos<size());
          return _start[pos];
        }
        const T& opertor[](size_t pos) const 
        {
          assert(pos<size());
          return _start[pos];
        }
        vector()
          :_start(nullptr)
           ,_finish(nullptr)
           ,_endofstorage(nullptr)
        {}
       //V1(V2)
       //vector(const vector T& v)
       //    :_start(nullptr)
       //     ,_finish(nullptr)
       //     ,_endofstroage(nullptr)
       // {
       // reserve(v.capacity());
       // for(auto &e:v)
       // {
       //   push_back(e);
       // }
       

          V1(V2)

      }
      private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    }
}
