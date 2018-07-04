#pragma once
#pragma once
#include <iostream>
#include<queue>
#include<stack>

template<class T>
class BinaryTree;
//�������Ľڵ㶨��
template<class T>
class BinaryTreeNode
{
	friend class BinaryTree<T>;
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

//�������Ķ���
template<class T>
class BinaryTree
{
private:
	BinaryTreeNode<T>* root;
	int floor;
	int Width;
public:
	BinaryTree()
	{
		root = NULL;
	}
	~BinaryTree()
	{
		/* ���д */
	}

	bool isEmpty() const	//�ж��Ƿ�Ϊ����
	{
		if (root == NULL)
			return true;
		return false;
	}
	bool isComplete() const   //�ж��Ƿ�����ȫ������
	{
		bool flag = 0;
		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;
		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			nodeQueue.pop();

			if (pointer->rightChild && !pointer->leftChild) //�ڵ����Һ��Ӷ�û�����򷵻�FALSE
				return false;
			if (pointer->leftChild && !pointer->rightChild) //�ڵ������Ӷ�û�ֺ������α�������һ���ڵ�ΪҶ�ӽڵ�
			{
				BinaryTreeNode<T>* temp = nodeQueue.front();
				if (!temp->isLeaf())
					return false;
			}
			if (flag == 1 && !pointer->isLeaf()) //��һ��Ҷ�ӽڵ�֮���ΪҶ�ӣ����򷵻�FALSE
				return false;
			if (pointer->isLeaf()) //ĳһ�ڵ�ΪҶ�ӣ���flag��1
				flag = 1;

			if (pointer->leftChild)
				nodeQueue.push(pointer->leftChild);
			if (pointer->rightChild)
				nodeQueue.push(pointer->rightChild);
		}
		return true;
	}

	void display(BinaryTreeNode<T> *current) const
	{
		std::cout << current->data << " ";
	}

	void creatBinaryTree()		//����������
	{
		BinaryTreeNode<T>* Node_A = new BinaryTreeNode<T>('A');
		BinaryTreeNode<T>* Node_B = new BinaryTreeNode<T>('B');
		BinaryTreeNode<T>* Node_C = new BinaryTreeNode<T>('C');
		BinaryTreeNode<T>* Node_D = new BinaryTreeNode<T>('D');
		BinaryTreeNode<T>* Node_E = new BinaryTreeNode<T>('E');
		BinaryTreeNode<T>* Node_F = new BinaryTreeNode<T>('F');
		BinaryTreeNode<T>* Node_G = new BinaryTreeNode<T>('G');
		BinaryTreeNode<T>* Node_H = new BinaryTreeNode<T>('H');

		root = Node_A;

		Node_A->setLeftChild(Node_B);
		Node_A->setRightChild(Node_C);
		Node_B->setRightChild(Node_D);
		Node_C->setRightChild(Node_E);
		Node_D->setLeftChild(Node_F);
		Node_D->setRightChild(Node_G);
		Node_E->setRightChild(Node_H);
		/*
				  A
			  B 	  C
				 D	     E
			  F     G	    H
		*/
	}

	BinaryTreeNode<T> *getRoot() const		//���ظ��ڵ�
	{
		return root;
	}
	BinaryTreeNode<T> *getParent(BinaryTreeNode<T> *current) const		//���ظ��ڵ�
	{
		/* ���д */
	}
	BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode<T> *current) const	//�������ֵܽڵ�
	{
		/* ���д */
	}
	BinaryTreeNode<T> *getRightSibling(BinaryTreeNode<T> *current) const	//�������ֵܽڵ�
	{
		/* ���д */
	}

	void breadthFirstOrder(BinaryTreeNode<T> *Root)	//������ȱ�����RootΪ���ڵ������
	{
		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = Root;

		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			display(pointer);
			nodeQueue.pop();
			if (pointer->leftChild)
				nodeQueue.push(pointer->leftChild);
			if (pointer->rightChild)
				nodeQueue.push(pointer->rightChild);
		}
	}
	void preOrder(BinaryTreeNode<T> *Root)	//���������RootΪ���ڵ������
	{

		/*	//�ݹ��㷨
		if (Root != NULL)
		{
		display(Root);
		preOrder(Root->leftChild);
		preOrder(Root->rightChild);
		}
		*/

		//�ǵݹ��㷨
		using std::stack;

		stack<BinaryTreeNode<T>*> nodeStack;
		BinaryTreeNode<T>* pointer = Root;

		while (!nodeStack.empty() || pointer)
		{
			if (pointer)
			{
				display(pointer);
				if (pointer->rightChild)
					nodeStack.push(pointer->rightChild);
				pointer = pointer->leftChild;
			}
			else
			{
				pointer = nodeStack.top();
				nodeStack.pop();
			}
		}
	}
	void inOrder(BinaryTreeNode<T> *Root)		//���������RootΪ���ڵ������
	{
		/*	//�ݹ鷽��
		if (Root != NULL)
		{
		inOrder(Root->leftChild);
		display(Root);
		inOrder(Root->rightChild);
		}
		*/
		//�ǵݹ��㷨
		using std::stack;

		stack<BinaryTreeNode<T>*> nodeStack;
		BinaryTreeNode<T>* pointer = Root;

		while (!nodeStack.empty() || pointer)
		{
			if (pointer)
			{
				nodeStack.push(pointer);
				pointer = pointer->leftChild;
			}
			else
			{
				pointer = nodeStack.top();
				display(pointer);
				pointer = pointer->rightChild;
				nodeStack.pop();
			}
		}
	}
	void postOrder(BinaryTreeNode<T> *Root)	//���������RootΪ���ڵ������
	{
		/*	//�ݹ鷽��
		if (Root != NULL)
		{
		postOrder(Root->leftChild);
		postOrder(Root->rightChild);
		display(Root);
		}
		*/

		/*	//�α��ǵݹ��㷨
		using std::stack;

		stack<BinaryTreeNode<T>*> nodeStack;
		BinaryTreeNode<T>* pointer = Root;
		BinaryTreeNode<T>* pre = Root;

		while (!nodeStack.empty() || pointer)
		{
		while (pointer->leftChild != NULL)
		{
		nodeStack.push(pointer);
		pointer = pointer->leftChild;
		}
		while (pointer != NULL && (pointer->rightChild == NULL || pointer->rightChild == pre))
		{
		display(pointer);
		pre = pointer;
		if (nodeStack.empty())
		return;
		pointer = nodeStack.top();
		nodeStack.pop();
		}
		nodeStack.push(pointer);
		pointer = pointer->rightChild;
		}
		*/

		//���Ϸ���
		using std::stack;

		stack<BinaryTreeNode<T>*> nodeStack;

		BinaryTreeNode<T>* pointer = Root;
		BinaryTreeNode<T>* tempNode = NULL;  //ջ��Ԫ��
		BinaryTreeNode<T>* justNode = NULL;	 //�ոշ��ʹ���Ԫ��

		while (pointer || !nodeStack.empty())
		{
			if (pointer)
			{
				nodeStack.push(pointer);
				pointer = pointer->leftChild;
			}
			else  //pointer=NULL��ת��ջ�� �ǿ�δ���ʹ� ���Һ���
			{
				while (!nodeStack.empty())
				{
					tempNode = nodeStack.top();
					if (tempNode->rightChild && tempNode->rightChild != justNode)
					{
						pointer = tempNode->rightChild;
						break;
					}
					else
					{
						display(tempNode);
						justNode = tempNode;
						nodeStack.pop();
					}
				}
			}
		}
	}
	int count_of_jiedian(BinaryTreeNode<T>* Root) const		//����ڵ��ܸ���
	{
		//�ǵݹ��㷨
/*		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;

		int count = 0;
		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			count++;
			nodeQueue.pop();
			if (pointer->leftChild)
				nodeQueue.push(pointer->leftChild);
			if (pointer->rightChild)
				nodeQueue.push(pointer->rightChild);
		}
		return count;
*/

//�ݹ��㷨
		int Count_left = 0;
		int Count_right = 0;

		if (Root == NULL)
			return 0;
		if (Root->leftChild)
			Count_left = count_of_jiedian(Root->leftChild);
		if (Root->rightChild)
			Count_right = count_of_jiedian(Root->rightChild);
		return Count_left + Count_right + 1;
	}
	int count_of_degree0(BinaryTreeNode<T>* Root) const //Ҷ�ӽڵ���
	{
		static int count0 = 0;

		if (Root == NULL)
			return 0;
		if (Root->leftChild == NULL&&Root->rightChild == NULL)
			count0++;
		count_of_degree0(Root->leftChild);
		count_of_degree0(Root->rightChild);
		return count0;
	}
	int count_of_degree1(BinaryTreeNode<T>* Root) const //��Ϊһ�Ľڵ���
	{
		static int count1 = 0;

		if (Root == NULL)
			return 0;
		if ((Root->leftChild == NULL&&Root->rightChild) || (Root->leftChild&&Root->rightChild == NULL))
			count1++;
		count_of_degree1(Root->leftChild);
		count_of_degree1(Root->rightChild);

		return count1;
	}
	int count_of_degree2(BinaryTreeNode<T>* Root) const //��Ϊ���Ľڵ���
	{
		static int count2 = 0;

		if (Root == NULL)
			return 0;
		if (Root->leftChild&&Root->rightChild)
			count2++;
		count_of_degree2(Root->leftChild);
		count_of_degree2(Root->rightChild);

		return count2;
	}
	int height_of_tree(BinaryTreeNode<T>* Root) const  //���ĸ߶�
	{
		//�ǵݹ��㷨
/*		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;

		int height = 0;

		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			nodeQueue.push(NULL);  //ÿ����֮����Null����
			nodeQueue.pop();
			while (pointer)
			{
				if (pointer->leftChild)
					nodeQueue.push(pointer->leftChild);
				if (pointer->rightChild)
					nodeQueue.push(pointer->rightChild);
				pointer = nodeQueue.front();
				nodeQueue.pop();
			}
			height++;
		}
		std::cout << "���ĸ߶�Ϊ��" << height << std::endl;
*/
//�ݹ��㷨
		static int leftHeight = 0;
		static int rightHeight = 0;
		if (!Root)
			return 0;
		else
		{
			leftHeight = height_of_tree(Root->leftChild);
			rightHeight = height_of_tree(Root->rightChild);
		}
		return leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);
	}
	int maxWidth_of_tree(BinaryTreeNode<T>* Root) const  //���������
	{
    	using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;

		int width;
		int maxWidth = 0;

		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			width = 0;
			pointer = nodeQueue.front();
			nodeQueue.push(NULL);  //ÿ����֮����Null����
			nodeQueue.pop();
			while (pointer)
			{
				if (pointer->leftChild)
					nodeQueue.push(pointer->leftChild);
				if (pointer->rightChild)
					nodeQueue.push(pointer->rightChild);
				pointer = nodeQueue.front();
				nodeQueue.pop();
				width++; //ÿpopһ�Σ�Ԫ�ظ�����һ
			}
			maxWidth = maxWidth > width ? maxWidth : width;
		}
		std::cout << "���������Ϊ��" << maxWidth << std::endl;
		return maxWidth;
	}

	T maxData(BinaryTreeNode<T>* Root) const //���нڵ����ݵ����ֵ
	{
		//�ǵݹ��㷨
/*		T maxData = root->data;

		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;

		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			maxData = maxData > pointer->data ? maxData : pointer->data;
			nodeQueue.pop();
			if (pointer->leftChild)
				nodeQueue.push(pointer->leftChild);
			if (pointer->rightChild)
				nodeQueue.push(pointer->rightChild);
		}
		std::cout << "�������ڵ�Ԫ��Ϊ��" << maxData << std::endl;
*/
//�ݹ��㷨
		T Maxdata = 'A';
		if (Maxdata < Root->data)
			Maxdata = Root->data;
		if (Root == NULL)
			return 0;
		if (Root->leftChild)
			Maxdata = maxData(Root->leftChild);
		if (Root->rightChild)
			Maxdata = maxData(Root->rightChild);
		return Maxdata;
	}
	void changeChild(BinaryTreeNode<T>* Root) //����ÿ���ڵ�����Һ���
	{
		//�ǵݹ�ʵ��
/*		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;
		BinaryTreeNode<T>* tempNode = NULL;

		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			//�������ӽڵ�
			tempNode = pointer->leftChild;
			pointer->leftChild = pointer->rightChild;
			pointer->rightChild = tempNode;

			nodeQueue.pop();
			if (pointer->leftChild)
				nodeQueue.push(pointer->leftChild);
			if (pointer->rightChild)
				nodeQueue.push(pointer->rightChild);
		}
*/
//�ݹ�ʵ��
		BinaryTreeNode<T>* tempNode = NULL;
		if (!Root)
			return;
		else
		{
			tempNode = Root->leftChild;
			Root->leftChild = Root->rightChild;
			Root->rightChild = tempNode;
		}
		changeChild(Root->leftChild);
		changeChild(Root->rightChild);
	}

	void deleteLeaf() //ɾ��Ҷ�ӽڵ�
	{
		//�ǵݹ��㷨
/*		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;
		BinaryTreeNode<T>* parentNode = NULL;

		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			nodeQueue.pop();
			if (pointer->leftChild && pointer->leftChild->isLeaf()) //���Ӵ�����ΪҶ�ӣ���ɾ������pointer����ָ�����ÿ�
			{
				BinaryTreeNode<T>* tempNode = pointer->leftChild;
				delete tempNode;
				pointer->setLeftChild(NULL);
			}
			if (pointer->rightChild && pointer->rightChild->isLeaf()) //�Һ��Ӵ�����ΪҶ�ӣ���ɾ������pointer�Һ���ָ�����ÿ�
			{
				BinaryTreeNode<T>* tempNode = pointer->rightChild;
				delete tempNode;
				pointer->setRightChild(NULL);
			}
			if (pointer->leftChild && !pointer->leftChild->isLeaf())
				nodeQueue.push(pointer->leftChild);
			if (pointer->rightChild && !pointer->rightChild->isLeaf())
				nodeQueue.push(pointer->rightChild);
		}
*/
//�ݹ��㷨
		deleteLeftLogic(root);

	}
	bool deleteLeftLogic(BinaryTreeNode<T>* p)
	{
		if (p->leftChild)
			if (deleteLeftLogic(p->leftChild))
				p->leftChild = 0;
		if (p->rightChild)
		{
			if (deleteLeftLogic(p->rightChild))
				p->rightChild = 0;
			return false;
		}
		if (p->leftChild == 0 && p->rightChild == 0)
		{
			delete p;
			return true;
		}
	}
	void deleteBinary(BinaryTreeNode<T> *Root);		//ɾ����RootΪ���ڵ������

	BinaryTreeNode<T>* pre_in_create(T* pre, T* in, int n)  //����������������
	{
		if (n == 0)
			return NULL;

		BinaryTreeNode<T>* rt;
		rt = new BinaryTreeNode<T>;
		rt->data = pre[0];
		//�ҵ����ڵ��������е�λ��
		int count = 0;
		while (pre[0] != in[count])
			count++;

		pre = pre + 1;
		rt->leftChild = pre_in_create(pre, in, count);
		pre = pre + count;
		in = in + count + 1;
		rt->rightChild = pre_in_create(pre, in, n - count - 1);
		return rt;
	}
	BinaryTreeNode<T>* in_post_create(T* post, T* in, int n, int m)  //����������������
	{
		if (n == 0)
			return NULL;

		BinaryTreeNode<T> *rt;
		rt = new BinaryTreeNode<T>;
		rt->data = post[n - 1];

		int count = 0;
		while (in[count] != post[n - 1])
			count++;

		rt->leftChild = in_post_create(post, in, count, count);

		in = in + count + 1;
		post = post + count;
		rt->rightChild = in_post_create(post, in, n - count - 1, m - count - 1);
		return rt;
	}
};



/*	void count_of_du() const //ͳ�ƶ�Ϊ0��1��2�Ľڵ����
{
//�ǵݹ��㷨
using std::queue;
queue< BinaryTreeNode<T>* > nodeQueue;
BinaryTreeNode<T>* pointer = root;

int count0 = 0;
int count1 = 0;
int count2 = 0;

if (pointer)
nodeQueue.push(pointer);
while (!nodeQueue.empty())
{
pointer = nodeQueue.front();

if (pointer->leftChild && pointer->rightChild)
count2++;
else if (!pointer->leftChild && !pointer->rightChild)
count0++;
else
count1++;

nodeQueue.pop();
if (pointer->leftChild)
nodeQueue.push(pointer->leftChild);
if (pointer->rightChild)
nodeQueue.push(pointer->rightChild);
}
std::cout << "��Ϊ0�Ľڵ����Ϊ��" << count0 << std::endl;
std::cout << "��Ϊ1�Ľڵ����Ϊ��" << count1 << std::endl;
std::cout << "��Ϊ2�Ľڵ����Ϊ��" << count2 << std::endl;
}
*/

