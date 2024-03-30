#pragma once
#include<iostream>
#include<utility>
namespace guagua
{
	template<class K,class V>
	struct AVLTreeNode
	{
		std::pair<K, V> _kv;
		struct AVLTreeNode<K,V>* _parent;
		struct AVLTreeNode<K,V>* _left;
		struct AVLTreeNode<K,V>* _right;
		//Æ½ºâÒò×Ó
		int _bf;

		AVLTreeNode(const std::pair<K,V>& kv)
			: _parent(nullptr)
			, _left(nullptr)
			, _right(nullptr)
			, _bf(0)
			, _kv(kv)
			{}
	};
	template<class K,class V>
	class AVLTree
	{
		typedef AVLTreeNode<K,V> node;
	public:
		bool Insert(const std::pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root= new node(kv);
				return true;
			}
			node* parent = nullptr;
			node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
		}
	private:
		node* _root;
	};
}


