#pragma once
#include<iostream>
using namespace std;

template <class T>
class BinarySearchTree;
//�ڵ㶨��
template<class T>
class BinaryTreeNode
{
	friend class BinarySearchTree<T>;
private:
	T data;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;
public:
	BinaryTreeNode() {}
	BinaryTreeNode(const T & dat, BinaryTreeNode<T>* l = NULL,
		BinaryTreeNode<T>* r = NULL)	//�����Һ��ӽڵ㼰���ݵĳ�ʼ������
	{
		data = dat;
		leftChild = l;
		rightChild = r;
	}

	BinaryTreeNode<T> *getLeftChild() const	//�������ӽڵ�
	{
		return leftChild��
	}
	BinaryTreeNode<T> *getRightChild() const    //�����Һ��ӽڵ�
	{
		return rightChild;
	}
	T getData() const	//���ؽڵ�����
	{
		return data;
	}

	void setLeftChild(BinaryTreeNode<T> *l)	//�������ӽڵ�
	{
		leftChild = l;
	}
	void setRightChild(BinaryTreeNode<T> *r)    //�����Һ��ӽڵ�
	{
		rightChild = r;
	}
	void setData(const T & Dat)	//���ýڵ�����
	{
		data = Dat;
	}

	bool isLeaf() const	//�ж��Ƿ�ΪҶ�ӽڵ�,�Ƿ���TRUE�����Ƿ���FALSE
	{
		if (leftChild == NULL && rightChild == NULL)
			return true;
		return false;
	}
};

template <class T>
class BinarySearchTree
{
private:
	BinaryTreeNode<T>* root;
public:
	BinarySearchTree() { root = NULL; }
	bool Search(T key) const
	{
		BinaryTreeNode<T>* pointer = root;
		while (pointer)
		{
			if (pointer->data == key)
				return true;
			else if (pointer->data > key)
				pointer = pointer->leftChild;
			else
				pointer = pointer->rightChild;
		}
		return false;
	}

	void Insert(const T & value)
	{
		BinaryTreeNode<T>* pointer = root;
		BinaryTreeNode<T>* father = NULL;

		//�ҵ��½ڵ�ĸ��ڵ�
		while (pointer)
		{
			if (pointer->data > value)
			{
				father = pointer;
				pointer = pointer->leftChild;
			}
			else if (pointer->data < value)
			{
				father = pointer;
				pointer = pointer->rightChild;
			}
		}

		if (root == NULL)
		    root = new BinaryTreeNode<T>(value);
		else if (father->data > value)
			father->leftChild = new BinaryTreeNode<T>(value);
		else
			father->rightChild = new BinaryTreeNode<T>(value);

	}

	bool Delete(const T & key)  
	{
		if (root == NULL)
			return false;

		BinaryTreeNode<T>* pointer = root;
		BinaryTreeNode<T>* father = NULL;

		//�ҵ�ɾ���ڵ㼰�丸�ڵ�
		while (pointer)
		{
			if (pointer->data > key)
			{
				father = pointer;
				pointer = pointer->leftChild;
			}
			else if (pointer->data < key)
			{
				father = pointer;
				pointer = pointer->rightChild;
			}
			else 
				break;
		}
		//���һ����ɾ�ڵ��Ϊ0
		if (!pointer->leftChild&&!pointer->rightChild)
		{
			if (father->data < key)
				father->rightChild = NULL; 
			else
				father->leftChild = NULL;
			delete pointer;
			return true;
		}
		//���������ɾ�ڵ��Ϊ2
		else if (pointer->leftChild&&pointer->rightChild)
		{
			//�������������ֵ
			BinaryTreeNode<T>* re_pointer = pointer->leftChild;	
			father = NULL;
			while (re_pointer->rightChild)
			{
				father = re_pointer;
				re_pointer = re_pointer->rightChild;
			}

			pointer->data = re_pointer->data;
			
			//ɾ��������
			if (re_pointer->isLeaf())
			{
				father->rightChild = NULL; //һ��Ϊ���ڵ���Һ���
				delete re_pointer;
				return true;
			}
			else
			{
				father->rightChild = re_pointer->leftChild;  //���ڵ���Һ��������������Ӽ̳�
				delete re_pointer; 
				return true;
			}
		}
		//���������ɾ�ڵ��Ϊ1
		else
		{
			if (father->data < key)
				father->rightChild = pointer->leftChild ? pointer->leftChild : pointer->rightChild;
			else
				father->leftChild = pointer->leftChild ? pointer->leftChild : pointer->rightChild;
			delete pointer;
			return true;
		}
	}
};
