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


//�ػ�
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


//��ϣ��
namespace closehash
{

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


//��ϣͰ

namespace buckethash
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode* _next;

		//��ʼ��
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};


	//ǰ������
	template<class K, class T, class Hash, class KeyOfT>
	class HashTable;

	//Ϊʲôconst������û�и��ã�
	template<class K, class T, class Hash, class KeyOfT>
	//������
	struct __HTiterator
	{

		//�����ض���
		typedef HashNode<T> Node;
		typedef __HTiterator<K, T, Hash, KeyOfT> Self;
		typedef HashTable<K, T, Hash, KeyOfT> HT;
		typedef __HTiterator<K, T, Hash, KeyOfT> Iterator;
		Node* _node;
		HT* _ht;

		//��ʼ��
		__HTiterator(const Node* node,const HT* ht)
			:_node(node)
			, _ht(ht)
		{}

		__HTiterator(const Iterator& it)
		{
			_node(it._node);
			_ht(it._ht);
		}
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
			//�����ǰͰ��һ����Ϊ��
			if (_node->_next)
			{
				_node= _node->_next;
			}
			else
			{
				KeyOfT kot;
				Hash hash;
				size_t haxi = Hash(kot(_node->_data)) % _ht->_tables.size();
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

				//����û��Ͱ��
				if (haxi == _ht->_tables.size())
				{
					_node == nullptr;
				}
			}
			return *this;
		}
		template<class K, class T, class Hash, class KeyOfT>
		class HashTable
		{
			typedef HashNode<T> Node;
			template<class K, class T, class Hash, class KeyOfT>
			friend struct __HTiterator;
		public:
			typedef __HTiterator<K, T, Hash, KeyOfT> iterator;

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

				//�������ӿ�����1(����������)
				if (_tables.size() == _n)
				{
					//�����µĹ�ϣͰ
					std::vector<Node*> newht;
					//������������2��
					newht.resize(_tables.size() * 2,nullptr);
					//����ÿ���±�����뵽�±���
					for (size_t i = 0; i < _tables.size(); ++i)
					{
						Node* cur = _tables[i];
						while (cur)
						{
							Node* next = cur->_next;
							size_t haxi = Hash(kot(data)) % newht.size();

							//ͷ�嵽�±�
							cur->_next = newht[haxi];
							newht[haxi] = cur;
							cur = next;
						}
						_tables[i] = nullptr;
					}
					_tables.swap(newht);
				}

				//����ռ��㹻
				size_t haxi = Hash(kot(data)) % _tables.size();
				//ͷ��
				Node* newnode = new Node(data);
				newnode->_next = _tables[haxi];
				_tables[haxi] = newnode;
				++_n;

				return std::make_pair(iterator(newnode, this), true);
			}


			//����
			iterator Find(const K& key)
			{
				KeyOfT kot;
				size_t haxi = Hash(kot(key)) % _tables.size();
				Node* cur = _tables[haxi];
				while (cur)
				{
					if (kot(cur->_data) == key)
					{
						return iterator(cur, this);
					}
					else
					{
						cur = cur->_next;
					}
				}
				return end();
			}

			//ɾ��
			bool Erase(const K& key)
			{
				KeyOfT kot;
				size_t haxi = Hash(key) % _tables.size();
				Node* cur=_tables[haxi];
				Node* prev=nullptr;
				while (cur)
				{
					if (kot(cur->_data) == key)
					{
						if (cur = _tables[haxi])
						{
							_tables[haxi] = cur->_next;
						}
						else
						{
							prev->_next = cur->_next;
						}
						delete cur;
						--_n;
						return true;
					}
					else
					{
						prev = cur;
						cur = cur->_next;
					}
				}
				return false;
			}
		private:
			std::vector<Node*> _tables; //ָ������
			size_t _n = 0;//
		};

	};
}