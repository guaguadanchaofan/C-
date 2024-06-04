#include"RBtree.h"
#pragma once
namespace guagua
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

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

		pair<iterator, bool> insert(const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(key);
			return pair<iterator, bool>(ret.first, ret.second);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}
