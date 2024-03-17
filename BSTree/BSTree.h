#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>

using namespace std;

namespace guagua
{
	template <class T>
	struct BSTreeNode
	{
		BSTreeNode<T>* _right;
		BSTreeNode<T>* _left;
		T _key;
		BSTreeNode(const T& key)
			:_right(nullptr)
			, _left(nullptr)
			,_key(key)
		{}
	};
	template <class T>
	class BSTree
	{
		typedef BSTreeNode<T> Node;
	public:

		//���캯��
		BSTree()
			:_root(nullptr)
		{}

		//��������
		BSTree(const BSTree<T>& K)
		{
			_root = Copy(K._root);
		}

		//operator= ����
		BSTree& operator=(BSTree<T> K)
		{
			swap(_root, K._root);
			return *this;
		}


		//Copy(�ݹ鿽��)
		Node* Copy(Node* ptr)
		{
			if (ptr == nullptr)
				return nullptr;
			Node* newnode = new Node(ptr->_key);
			newnode->_left = Copy(ptr->_left);
			newnode->_right = Copy(ptr->_right);


			return newnode;
		}


		//����
		bool Insert(const T& key)
		{

			//����
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}
			//�ǿ�
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if(cur->_key>key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}


		//������
		bool Find(const T& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;
				}
			}
			return false;
		}


		//ɾ����
		bool Erase(const T& key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 1����Ϊ��
					// 2����Ϊ��
					// 3�����Ҷ���Ϊ�գ��滻ɾ��
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if(cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left = cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
					{
						Node* cur = _root;
						Node* minright =cur->_right;
						while (minright->_left)
						{
							parent = minright;
							minright = minright->_left;
						}
						cur->_key = minright->_key;
						if (parent->_left == minright)
						{
							parent->_left == minright->_left;
						}
						else
						{
							parent->_right == minright->_right;
						}
						delete minright;
					}
					return true;
				}
			}
			return false;
		}


		//�������
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}


		//�������
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key<<" ";
			_InOrder(root->_right);

		}
		//��������
		~BSTree()
		{

		}
	private:
		Node* _root;
	};
}
