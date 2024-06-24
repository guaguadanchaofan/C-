#define  _CRT_SECURE_NO_WARNINGS
#include"BloomFilter.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>


void test1()
{
	guagua::BloomFilter<10> bf;
	std::string arr[] = { "张三","李四","王五","赵六","李华","李明","张1三","张三1" };
	for (auto& e : arr)
	{
		bf.set(e);
	}
	for (auto& e : arr)
	{
		std::cout << bf.test(e) << std::endl;
	}
	std::cout << std::endl;
	srand(time(0));
	for (const auto& s : arr)
	{
		std::cout << bf.test(s + std::to_string(rand())) << std::endl;
	}
}

void test2()
{
	srand(time(0));
	const size_t N = 10000;
	guagua::BloomFilter<N> bf;
	std::vector<std::string> v1;
	std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.set(str);
	}

	// v2跟v1是相似字符串集，但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		url += std::to_string(999999 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.test(str))
		{
			++n2;
		}
	}

	std::cout << "相似字符串误判率:" << (double)n2 / (double)N << std::endl;


	// 不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "zhihu.com";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.test(str))
		{
			++n3;
		}
	}
	std::cout << "不相似字符串误判率:" << (double)n3 / (double)N << std::endl;
}
int main()
{
	//test1();
	//test2();
	return 0;
}