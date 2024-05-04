#pragma once


//枚举
enum Colour
{
	RED,
	BLACK,
};
template<class K,class V>

//红黑树节点
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	std::pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		,_col(RED)
	{}
};

//红黑树类
template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:


	//插入
	bool Insert(const std::pair<K,V>& kv)
	{
		//如果根节点为空插入到根节点把他变为黑
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		//找到插入的位置 保存到parent
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_kv.first>kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_col = RED;
		//将节点插入到找到的位置
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
		//更改平衡因子
		while (parent && parent->_col == RED)
		{
			//保存祖父节点
			Node* grandfather = parent->_parent;
			//如果父节点为祖父节点的左子树
			if (grandfather->_left == parent)
			{
				//保存叔叔节点
				Node* uncle = grandfather->_right;
				//情况一 叔叔节点存在且为红
				if (uncle && uncle->_col == RED)
				{
					//父节点跟叔节点变黑
					parent->_col = uncle->_col = BLACK;
					//祖父变红
					grandfather->_col = RED;

					//将祖父节点给cur，parent节点等于cur的父节点
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						//情况二 如果叔节点不存在就不满足每条路黑色数量相同
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//情况三
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else //(parent==grandfather->right)
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = parent->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = RED;
						grandfather->_col = BLACK;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;

		return true;
	}

	//左旋
	void RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		parent->_right = SubRL;
		if (SubRL)
		{
			SubRL->_parent = parent;
		}
		//保存祖父节点
		Node* ppnode = parent->_parent;
		SubR->_left = parent;
		parent->_parent = SubR;

		if (ppnode == nullptr)
		{
			_root = SubR;
			SubR->_parent = nullptr;
		}
		else
		{
			if (ppnode->_right == parent)
			{
				ppnode->_right = SubR;
			}
			else
			{
				ppnode->_left = SubR;
			}
			SubR->_parent = ppnode;
		}
	}
	//右旋
	void RotateR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		parent->_left = SubLR;
		if (SubLR)
		{
			SubLR->_parent = parent;
		}
		//保存祖父节点
		Node* ppnode = parent->_parent;
		SubL->_right = parent;
		parent->_parent = SubL;
		//如果祖父节点是空（为根节点）
		if (ppnode == nullptr)
		{
			_root = SubL;
			SubL->_parent = nullptr;
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

	}

	//遍历
	void Inorder()
	{
		_Inorder(_root);
	}
	void _Inorder(Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		_Inorder(_root->_left);
		std::cout << _root->_kv.first << ":" << _root->_kv.second << std::endl;
		_Inorder(_root->_right);
	}
private:
	Node* _root = nullptr;
};