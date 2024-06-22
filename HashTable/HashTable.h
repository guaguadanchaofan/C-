#pragma once
#include<vector>



template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};


//特化
template<>
struct HashFunc<std::string>
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


//哈希表
namespace closehash
{

	//枚举哈希表的状态
	enum State
	{
		EMPTY,
		EXIST,
		DELETE,
	};

	//创建哈希数据结构体HashDate<K,V>
	template <class K,class V>
	struct HashDate
	{
		std:: pair<K, V> _kv;
		State _state = EMPTY;
	};

	//
	template <class K, class V,class Hash= HashFunc<K>>
	class HashTable
	{
		//类型重命名成Date
		typedef HashDate<K, V> Date;
	public:

		//构造函数
		HashTable()
			:_n(0)
		{
			//vector扩容
			_tables.resize(10);
		}

		//HashTable的插入
		bool Insert(const std::pair<K, V>& kv)
		{
			//如果没有找到对应的值直接返回
			if (Find(kv.first))
			{
				return false;
			}

			//大于标定负载因子，就需要扩容
			if (_n * 10 / _tables.size() >= 7)
			{
				//创建新的哈希表
				HashTable<K, V> newHT;
				//2倍扩容
				newHT._tables.resize(_tables.size() * 2);

				//遍历存在的插入新的哈希表
				for (auto& e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}
				//
				_tables.swap(newHT._tables);
			}

			//创建仿函数的实例化
			Hash hf;
			//计算哈希映射值
			size_t haxi = hf(kv.first) % _tables.size();
			//查询插入位置
			while (_tables[haxi]._state == EXIST)
			{
				++haxi;
				haxi %= _tables.size();
			}
			//插入哈希表
			_tables[haxi]._kv = kv;
			_tables[haxi]._state = EXIST;
			++_n;
			return true;
		}

		//Find查找
		Date* Find(const K& key)
		{
			Hash hf;
			//计算哈希映射值
			size_t haxi = hf(key) % _tables.size();
			while (_tables[haxi]._state != EMPTY)
			{
				if (_tables[haxi]._kv.first == key 
					&& _tables[haxi]._state == EXIST)
				{
					return &_tables[haxi];
				}
				++haxi;
				haxi %= _tables.size();
			}
			return nullptr;
		}
		//Erase
		bool Erase(const K& key)
		{
			Date* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		std::vector<Date> _tables;
		size_t _n = 0;
	};
}


//哈希桶

namespace buckethash
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode* _next;

		//初始化
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};


	//前置声明
	template<class K, class T, class hash, class KeyOfT>
	class HashTable;

	//为什么const迭代器没有复用？
	template<class K, class T, class hash, class KeyOfT>
	//迭代器
	struct __HTiterator
	{

		//类型重定义
		typedef HashNode<T> Node;
		typedef __HTiterator<K, T, hash, KeyOfT> Self;
		typedef HashTable<K, T, hash, KeyOfT> HT;

		Node* _node;
		HT* _ht;

		//初始化
		__HTiterator(Node* node, HT* ht)
			:_node(node)
			, _ht(ht)
		{}
		T& operator*()
		{
			return _node->_data;
		}
		T& operator->()
		{
			return &_node->_data;
		}

		bool operator !=(const Self& s)const
		{
			return _node != s._node;
		}

		Self& operator++()
		{
			//如果当前桶下一个不为空
			if (_node->_next)
			{
				_node= _node->_next;
			}
			else
			{
				KeyOfT kot;
				hash hash;
				size_t haxi = hash(kot(_node->_data)) % _ht->_tables.size();
				++haxi;
				while (haxi < _ht->_tables.size())
				{
					if (_ht->_tables[haxi])
					{
						_node = _ht->_tables[haxi];
						break;
					}
					else
					{
						++haxi;
					}
				}

				//后面没有桶了
				if (haxi == _ht->_tables.size())
				{
					_node == nullptr;
				}
			}
			return *this;
		}
		template<class K, class T, class hash, class KeyOfT>
		class HashTable
		{
			typedef HashNode<T> Node;
			template<class K, class T, class Hash, class KeyOfT>
			friend struct __HTiterator;
		public:
			typedef __HTiterator<K, T, hash, KeyOfT> iterator;

			HashTable()
				:_n(0)
			{
				_tables.resize(10);
			}
			iterator begin()
			{
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					if (_tables[i])
					{
						return iterator(_tables[i], this);
					}
				}
				return iterator(nullptr,this);
			}

			iterator end()
			{
				return iterator(nullptr, this);
			}

			~HashTable()
			{
				for (size_t i=0;i<_tables.size;++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* Next = cur->_next;
						delete cur;
						cur = Next;
					}
					_tables[i] = nullptr;
				}
			}


			std::pair<iterator,bool> insert(const T& data)
			{
				KeyOfT kot;

				iterator it = Find(kot(data));
				if (it != end())
				{
					return std::make_pair(it, false);
				}

				//负载因子控制在1
				if (_tables.size() == _n)
				{


					closehash::HashTable<K, V, hash> newht;
					newht._tables.resize(_tables.size() * 2);
					/*std::vector<Node*> newht;
					newht.resize(_tables.size() * 2);
					for (size_t i = 0; i < _tables.size(); ++i)
					{
						Node* cur = _tables[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t haxi = hash(kot(cur->_data)) % newht.size();
							
						}
					}*/
				}
			}
		private:
			std::vector<Node*> _tables; //指针数组
			size_t _n = 0;//
		};

	};
}