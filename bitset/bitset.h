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
			 //�����С����
			 _bits.resize(N / 8 + 1, 0);
		 }

		 //����
		 void set(size_t x)
		 {
			 //�ȼ������Ǹ�����
			 size_t n = x / 8;
			 //�ڼ�������λ��
			 size_t m = x % 8;
			 //��|�������������1Ϊ1��û1Ϊ0������m������λ�ٻ�
			 _bits[n] |= (1 << m);
		 }

		 //����
		 void reset(size_t x)
		 {
			 //�ȼ������Ǹ�����
			 size_t n = x / 8;
			 //�ڼ�������λ��
			 size_t m = x % 8;
			 //��&���룩���������0Ϊ0��û0Ϊ1������m������λ����
			 _bits[n] &= ~(1 << m);
		 }

		 //�ж��Ƿ����
		 bool test(size_t x)
		 {
			 //�ȼ������Ǹ�����
			 size_t n = x / 8;
			 //�ڼ�������λ��
			 size_t m = x % 8;
			 return _bits[n] & (1 << m);
		 }
	 private:
		 std::vector<char> _bits;
	 };
}