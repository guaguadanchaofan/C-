#pragma once
#include"HashTable.h"

namespace bit
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		hash_bucket::HashTable<K, const K, SetKeyOfT, Hash> _ht;
	};

	void test_set1()
	{
		unordered_set<int> us;
		us.insert(3);
		us.insert(1);
		us.insert(5);
		us.insert(15);
		us.insert(45);
		us.insert(7);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			//*it += 100;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}