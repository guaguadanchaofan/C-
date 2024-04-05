#pragma once
#include<iostream>
#include<utility>
#include <string>
#include<assert.h>
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
			cur = new node(kv);
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
					if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
					}
				}
				else
				{
					assert(false);
				}
			}
			return true;
		}

		//����
		void RotateL(node* parent)
		{

			//���õ�����������������������
			node* SubR = parent->_right;
			node* SubRL = SubR->_left;
			//�ٰ������������������������ĵ��ұ�
			parent->_right = SubRL;
			//�������������������Ϊnull
			if (SubRL)
			{
				SubRL->_parent = parent;
			}
			//�����游�ڵ�
			node* ppnode = parent->_parent;
			//����ֵĸ��ڵ�������������
			SubR->_left = parent;
			parent->_parent = SubR;
			//����游�ڵ�Ϊ�գ�˵�����ڵ���Ǹ��ڵ�
			if (ppnode == nullptr)
			{
				_root = SubR;
				_root->_parent = nullptr;
			}
			else
			{
				if (ppnode->_left == parent)
				{
					ppnode->_left = SubR;
				}
				else
				{
					ppnode->_right = SubR;
				}
				SubR->_parent = ppnode;
			}
			parent->_bf = SubR->_bf = 0;
		}
		//�ҵ���
		void RotateR(node* parent)
		{
			node* SubL = parent->_left;
			node* SubLR = SubL->_right;
			parent->_left = SubLR;
			if (SubLR)
			{
				SubLR->_parent = parent;
			}
			node* ppnode = parent->_parent;
			SubL->_right = parent;
			parent->_parent = SubL;
			if (ppnode == nullptr)
			{
				_root = SubL;
				_root->_parent = nullptr;
			}
			else
			{
				if (ppnode->_left == parent)
				{
					ppnode->_left = SubL;
				}
				else
				{
					ppnode->_right = SubL;
				}
				SubL->_parent = ppnode;
			}
			parent->_bf = SubL->_bf = 0;
		}

		//˫��
		void RotateLR(node* parent)
		{
			node* SubL = parent->_left;
			node* SubLR = SubL->_right;
			int bf = SubLR->_bf;
			RotateL(parent->_left);
			RotateR(parent);
			//subLR����������
			if (bf == -1)
			{
				SubL->_bf = 0;
				parent->_bf = 1;
				SubLR->_bf = 0;
			}
			//subLR����������
			else if (bf == 1)
			{
				SubL->_bf = 0;
				parent->_bf = -1;
				SubLR->_bf = 0;
			}
			//subLR�Լ���������
			else if (bf == 0)
			{
				SubL->_bf= 0;
				parent->_bf = 0;
				SubLR->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
		void RotateRL(node* parent)
		{
			node* SubR = parent->_right;
			node* SubRL = SubR->_left;
			int bf = SubRL->_bf;
			RotateR(parent->_right);
			RotateL(parent);
			if (bf == -1)
			{
				SubR->_bf = 0;
				parent->_bf = 1;
				SubRL->_bf = 0;
			}
			else if (bf == 1)
			{
				SubR->_bf = 0;
				parent->_bf = -1;
				SubRL->_bf = 0;
			}
			else if (bf == 0)
			{
				SubR->_bf = 0;
				parent->_bf = 0;
				SubRL->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
		void Inorder()
		{
			_Inorder(_root);
		}
		void _Inorder(node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_Inorder(root->_left);
			std::cout << root->_kv.first << ":" << root->_kv.second << std::endl;
			_Inorder(root->_right);
		}

		int Height(node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			int lh = Height(root->_left);
			int rh = Height(root->_right);
			return lh > rh ? lh + 1 : rh + 1;
		}

	private:
		node* _root = nullptr;
	};
}


