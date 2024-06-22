#pragma once
#include"HashTable.h"

namespace guagua
{
	template<class K,class V,class Hash=HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<const K, V> kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename buckethash::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::iterator iterator;


		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}
		bool insert(const std::pair<K, V>& kv)
		{
			return _ht.insert(kv);
		}

	private:
		buckethash::HashTable<const K, std::pair<K, V>, MapKeyOfT, Hash> _ht;
	};
	void test_map1()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", ""));
		dict.insert(make_pair("left", ""));
		dict.insert(make_pair("right", ""));

		for (auto& kv : dict)
		{
			//kv.first += 'x';
			kv.second += 'y';

			cout << kv.first << ":" << kv.second << endl;
		}
	}
}
