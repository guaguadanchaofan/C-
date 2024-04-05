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
		//平衡因子
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
			//如果为空树创建节点插入
			if (_root == nullptr)
			{
				_root= new node(kv);
				return true;
			}
			node* parent = nullptr;
			node* cur = _root;
			//找到kv对应的位置
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
			//利用父节点找到cur节点的位置插入
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
			//更新平衡因子
			while (parent)
			{
				//在左边bf--
				if (cur == parent->_left)
				{
					parent->_bf--;
				}
				//在右边bf++
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

		//左单旋
		void RotateL(node* parent)
		{

			//先拿到右子树和右子树的左子树
			node* SubR = parent->_right;
			node* SubRL = SubR->_left;
			//再把右子树的左子树给父子树的的右边
			parent->_right = SubRL;
			//如果右子树的左子树不为null
			if (SubRL)
			{
				SubRL->_parent = parent;
			}
			//保存祖父节点
			node* ppnode = parent->_parent;
			//将拆分的父节点给右子树的左边
			SubR->_left = parent;
			parent->_parent = SubR;
			//如果祖父节点为空，说明父节点就是根节点
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
		//右单旋
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

		//双旋
		void RotateLR(node* parent)
		{
			node* SubL = parent->_left;
			node* SubLR = SubL->_right;
			int bf = SubLR->_bf;
			RotateL(parent->_left);
			RotateR(parent);
			//subLR左子树新增
			if (bf == -1)
			{
				SubL->_bf = 0;
				parent->_bf = 1;
				SubLR->_bf = 0;
			}
			//subLR右子树新增
			else if (bf == 1)
			{
				SubL->_bf = 0;
				parent->_bf = -1;
				SubLR->_bf = 0;
			}
			//subLR自己就是新增
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


