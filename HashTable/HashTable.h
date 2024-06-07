#pragma once
#include<vector>




namespace guagua
{
	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
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