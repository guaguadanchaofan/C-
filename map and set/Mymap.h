
#include<utility>
#include"RBtree.h"

namespace guagua
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<K, V>& KV)
			{
				return KV.first;
			}
		};
	public:
		typedef typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, std::pair<const K, V>, MapKeyOfT>::const_itertor const_iterator;
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}
