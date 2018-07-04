#pragma once
#include<iostream>
using namespace std;

template <class T>
class BinarySearchTree;
//节点定义
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
		BinaryTreeNode<T>* r = NULL)	//带左右孩子节点及数据的初始化函数
	{
		data = dat;
		leftChild = l;
		rightChild = r;
	}

	BinaryTreeNode<T> *getLeftChild() const	//返回左孩子节点
	{
		return leftChild；
	}
	BinaryTreeNode<T> *getRightChild() const    //返回右孩子节点
	{
		return rightChild;
	}
	T getData() const	//返回节点数据
	{
		return data;
	}

	void setLeftChild(BinaryTreeNode<T> *l)	//设置左孩子节点
	{
		leftChild = l;
	}
	void setRightChild(BinaryTreeNode<T> *r)    //设置右孩子节点
	{
		rightChild = r;
	}
	void setData(const T & Dat)	//设置节点数据
	{
		data = Dat;
	}

	bool isLeaf() const	//判断是否为叶子节点,是返回TRUE，不是返回FALSE
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

		//找到新节点的父节点
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

		//找到删除节点及其父节点
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
		//情况一：被删节点度为0
		if (!pointer->leftChild&&!pointer->rightChild)
		{
			if (father->data < key)
				father->rightChild = NULL; 
			else
				father->leftChild = NULL;
			delete pointer;
			return true;
		}
		//情况二：被删节点度为2
		else if (pointer->leftChild&&pointer->rightChild)
		{
			//找左子树中最大值
			BinaryTreeNode<T>* re_pointer = pointer->leftChild;	
			father = NULL;
			while (re_pointer->rightChild)
			{
				father = re_pointer;
				re_pointer = re_pointer->rightChild;
			}

			pointer->data = re_pointer->data;
			
			//删除替死鬼
			if (re_pointer->isLeaf())
			{
				father->rightChild = NULL; //一定为父节点的右孩子
				delete re_pointer;
				return true;
			}
			else
			{
				father->rightChild = re_pointer->leftChild;  //父节点的右孩子用替死鬼左孩子继承
				delete re_pointer; 
				return true;
			}
		}
		//情况二：被删节点度为1
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
