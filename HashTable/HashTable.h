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
	//ö�ٹ�ϣ���״̬
	enum State
	{
		EMPTY,
		EXIST,
		DELETE,
	};

	//������ϣ���ݽṹ��HashDate<K,V>
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
		//������������Date
		typedef HashDate<K, V> Date;
	public:

		//���캯��
		HashTable()
			:_n(0)
		{
			//vector����
			_tables.resize(10);
		}

		//HashTable�Ĳ���
		bool Insert(const std::pair<K, V>& kv)
		{
			//���û���ҵ���Ӧ��ֱֵ�ӷ���
			if (Find(kv.first))
			{
				return false;
			}

			//���ڱ궨�������ӣ�����Ҫ����
			if (_n * 10 / _tables.size() >= 7)
			{
				//�����µĹ�ϣ��
				HashTable<K, V> newHT;
				//2������
				newHT._tables.resize(_tables.size() * 2);

				//�������ڵĲ����µĹ�ϣ��
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

			//�����º�����ʵ����
			Hash hf;
			//�����ϣӳ��ֵ
			size_t haxi = hf(kv.first) % _tables.size();
			//��ѯ����λ��
			while (_tables[haxi]._state == EXIST)
			{
				++haxi;
				haxi %= _tables.size();
			}
			//�����ϣ��
			_tables[haxi]._kv = kv;
			_tables[haxi]._state = EXIST;
			++_n;
			return true;
		}

		//Find����
		Date* Find(const K& key)
		{
			Hash hf;
			//�����ϣӳ��ֵ
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