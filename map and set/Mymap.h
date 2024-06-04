#include"RBtree.h"
#pragma once
namespace guagua
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& KV)
			{
				return KV.first;
			}
		};
	public:

		//ÖØÃüÃû
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		const_iterator begin()const
		{
			return _t.begin();
		}

		const_iterator end()const
		{
			return _t.end();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(std::make_pair(key, V()));
			return ret.first->second;
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}
