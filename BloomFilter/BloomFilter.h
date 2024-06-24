#pragma once
#include<bitset>

namespace guagua
{

	struct APHash
	{
		size_t operator()(const std::string& key)
		{
			unsigned int hash = 0;
			int i = 0;

			for (auto ch : key)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ (ch) ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ (ch) ^ (hash >> 5)));
				}

				++i;
			}

			return hash;
		}
	};


	struct BKDRHash
	{
		size_t operator()(const std::string& key)
		{
			size_t hash = 0;
			for (auto ch : key)
			{
				hash *= 131;
				hash += ch;
			}
			return hash;
		}
	};



	struct JSHash
	{
		size_t operator()(const std::string& key)
		{
			size_t hash = 1315423911;
			for (auto ch : key)
			{
				hash ^= ((hash << 5) + ch + (hash >> 2));
			}
			return hash;
		}
	};


	struct DJBHash
	{
		size_t operator()(const std::string& key)
		{
			unsigned int hash = 5381;

			for (auto ch : key)
			{
				hash += (hash << 5) + ch;
			}

			return hash;
		}
	};
	//N为最多储存得数据个数
	//X为存储一个数据，开辟的位数
	template<size_t N
		,size_t X=4
		,class K=std::string,
		class HashFunc1= APHash,
		class HashFunc2 = BKDRHash,
		class HashFunc3 = DJBHash,
		class HashFunc4 = JSHash>
	class BloomFilter
	{
	public:


		void set(const K& key)
		{
			size_t hash1 = APHash()(key) % (N * X);
			size_t hash2 = BKDRHash()(key) % (N * X);
			size_t hash3 = DJBHash()(key) % (N * X);
			size_t hash4 = JSHash()(key) % (N * X);
			_BF.set(hash1);
			_BF.set(hash2);
			_BF.set(hash3);
			_BF.set(hash4);
		}


		bool test(const K& key)
		{
			size_t hash1 = APHash()(key) % (N * X);
			if (!_BF.test(hash1))
			{
				return false;
			}
			size_t hash2 = BKDRHash()(key) % (N * X);
			if (!_BF.test(hash2))
			{
				return false;
			}
			size_t hash3 = DJBHash()(key) % (N * X);
			if (!_BF.test(hash3))
			{
				return false;
			}
			size_t hash4 = JSHash()(key) % (N * X);
			if (!_BF.test(hash4))
			{
				return false;
			}
			return true;
		}


	private:
		std::bitset<N* X> _BF;
	};
}
