#pragma once
#include<vector>


namespace guagua
{
	 template<size_t N>
	 class bitset
	 {
	 public:
		 bitset()
		 {
			 //数组大小设置
			 _bits.resize(N / 8 + 1, 0);
		 }

		 //设置
		 void set(size_t x)
		 {
			 //先计算在那个数组
			 size_t n = x / 8;
			 //在计算具体得位置
			 size_t m = x % 8;
			 //用|（或）运算符（有1为1，没1为0）左移m个比特位再或
			 _bits[n] |= (1 << m);
		 }

		 //重置
		 void reset(size_t x)
		 {
			 //先计算在那个数组
			 size_t n = x / 8;
			 //在计算具体得位置
			 size_t m = x % 8;
			 //用&（与）运算符（有0为0，没0为1）左移m个比特位再与
			 _bits[n] &= ~(1 << m);
		 }

		 //判断是否存在
		 bool test(size_t x)
		 {
			 //先计算在那个数组
			 size_t n = x / 8;
			 //在计算具体得位置
			 size_t m = x % 8;
			 return _bits[n] & (1 << m);
		 }
	 private:
		 std::vector<char> _bits;
	 };
}