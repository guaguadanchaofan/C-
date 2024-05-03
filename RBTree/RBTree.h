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
		cur->_col = red;
		if(parent->_kv.first<kv.)
	}
private:
	Node* _root = nullptr;
};