#pragma once


//ö��
enum Colour
{
	RED,
	BLACK,
};
template<class K,class V>

//������ڵ�
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

//�������
template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:


	//����
	bool Insert(const std::pair<K,V>& kv)
	{
		//������ڵ�Ϊ�ղ��뵽���ڵ������Ϊ��
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		//�ҵ������λ�� ���浽parent
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
		//���ڵ���뵽�ҵ���λ��
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
		while (parent && parent->_col == RED)
		{
			//�����游�ڵ�
			Node* grandfather = parent->_parent;
			//������ڵ�Ϊ�游�ڵ��������
			if (grandfather->_left == parent)
			{
				//��������ڵ�
				Node* uncle = grandfather->_right;
				//���һ ����ڵ������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					//���ڵ����ڵ���
					parent->_col = uncle->_col = BLACK;
					//�游���
					grandfather->_col = RED;

					//���游�ڵ��cur��parent�ڵ����cur�ĸ��ڵ�
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						//����� �����ڵ㲻���ھͲ�����ÿ��·��ɫ������ͬ
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//�����
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

	//����
	void RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		parent->_right = SubRL;
		if (SubRL)
		{
			SubRL->_parent = parent;
		}
		//�����游�ڵ�
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
	//����
	void RotateR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		parent->_left = SubLR;
		if (SubLR)
		{
			SubLR->_parent = parent;
		}
		//�����游�ڵ�
		Node* ppnode = parent->_parent;
		SubL->_right = parent;
		parent->_parent = SubL;
		//����游�ڵ��ǿգ�Ϊ���ڵ㣩
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

	//����
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