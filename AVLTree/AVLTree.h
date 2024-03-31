#pragma once
#include<iostream>
#include<utility>
#include <string>

namespace guagua
{
	template<class K,class V>
	struct AVLTreeNode
	{
		std::pair<K, V> _kv;
		struct AVLTreeNode<K,V>* _parent;
		struct AVLTreeNode<K,V>* _left;
		struct AVLTreeNode<K,V>* _right;
		//ƽ������
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
			//���Ϊ���������ڵ����
			if (_root == nullptr)
			{
				_root= new node(kv);
				return true;
			}
			node* parent = nullptr;
			node* cur = _root;
			//�ҵ�kv��Ӧ��λ��
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
			cur = new node * (kv);
			//���ø��ڵ��ҵ�cur�ڵ��λ�ò���
			if (parent->_kv.first < kv.first)
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			//����ƽ������
			while (parent)
			{
				//�����bf--
				if (cur == parent->_left)
				{
					parent->_bf--;
				}
				//���ұ�bf++
				else
				{
					parent->_bf++;
				}
				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{

				}
			}
		}

	private:
		node* _root = nullptr;
	};
}


