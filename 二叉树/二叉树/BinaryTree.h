#pragma once
#pragma once
#include <iostream>
#include<queue>
#include<stack>

template<class T>
class BinaryTree;
//二叉树的节点定义
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

//二叉树的定义
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
		/* 最后写 */
	}

	bool isEmpty() const	//判断是否为空树
	{
		if (root == NULL)
			return true;
		return false;
	}
	bool isComplete() const   //判断是否是完全二叉树
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

			if (pointer->rightChild && !pointer->leftChild) //节点有右孩子而没左孩子则返回FALSE
				return false;
			if (pointer->leftChild && !pointer->rightChild) //节点有左孩子而没又孩子则层次遍历的下一个节点为叶子节点
			{
				BinaryTreeNode<T>* temp = nodeQueue.front();
				if (!temp->isLeaf())
					return false;
			}
			if (flag == 1 && !pointer->isLeaf()) //第一个叶子节点之后均为叶子，否则返回FALSE
				return false;
			if (pointer->isLeaf()) //某一节点为叶子，则flag置1
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

	void creatBinaryTree()		//建立二叉树
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

	BinaryTreeNode<T> *getRoot() const		//返回根节点
	{
		return root;
	}
	BinaryTreeNode<T> *getParent(BinaryTreeNode<T> *current) const		//返回父节点
	{
		/* 最后写 */
	}
	BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode<T> *current) const	//返回左兄弟节点
	{
		/* 最后写 */
	}
	BinaryTreeNode<T> *getRightSibling(BinaryTreeNode<T> *current) const	//返回右兄弟节点
	{
		/* 最后写 */
	}

	void breadthFirstOrder(BinaryTreeNode<T> *Root)	//广度优先遍历以Root为根节点的子树
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
	void preOrder(BinaryTreeNode<T> *Root)	//先序遍历以Root为根节点的子树
	{

		/*	//递归算法
		if (Root != NULL)
		{
		display(Root);
		preOrder(Root->leftChild);
		preOrder(Root->rightChild);
		}
		*/

		//非递归算法
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
	void inOrder(BinaryTreeNode<T> *Root)		//中序遍历以Root为根节点的子树
	{
		/*	//递归方法
		if (Root != NULL)
		{
		inOrder(Root->leftChild);
		display(Root);
		inOrder(Root->rightChild);
		}
		*/
		//非递归算法
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
	void postOrder(BinaryTreeNode<T> *Root)	//后序遍历以Root为根节点的子树
	{
		/*	//递归方法
		if (Root != NULL)
		{
		postOrder(Root->leftChild);
		postOrder(Root->rightChild);
		display(Root);
		}
		*/

		/*	//课本非递归算法
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

		//课上方法
		using std::stack;

		stack<BinaryTreeNode<T>*> nodeStack;

		BinaryTreeNode<T>* pointer = Root;
		BinaryTreeNode<T>* tempNode = NULL;  //栈顶元素
		BinaryTreeNode<T>* justNode = NULL;	 //刚刚访问过的元素

		while (pointer || !nodeStack.empty())
		{
			if (pointer)
			{
				nodeStack.push(pointer);
				pointer = pointer->leftChild;
			}
			else  //pointer=NULL，转到栈中 非空未访问过 的右孩子
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
	int count_of_jiedian(BinaryTreeNode<T>* Root) const		//计算节点总个数
	{
		//非递归算法
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

//递归算法
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
	int count_of_degree0(BinaryTreeNode<T>* Root) const //叶子节点数
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
	int count_of_degree1(BinaryTreeNode<T>* Root) const //度为一的节点数
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
	int count_of_degree2(BinaryTreeNode<T>* Root) const //度为二的节点数
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
	int height_of_tree(BinaryTreeNode<T>* Root) const  //树的高度
	{
		//非递归算法
/*		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;

		int height = 0;

		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			nodeQueue.push(NULL);  //每两层之间用Null隔开
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
		std::cout << "树的高度为：" << height << std::endl;
*/
//递归算法
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
	int maxWidth_of_tree(BinaryTreeNode<T>* Root) const  //树的最大宽度
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
			nodeQueue.push(NULL);  //每两层之间用Null隔开
			nodeQueue.pop();
			while (pointer)
			{
				if (pointer->leftChild)
					nodeQueue.push(pointer->leftChild);
				if (pointer->rightChild)
					nodeQueue.push(pointer->rightChild);
				pointer = nodeQueue.front();
				nodeQueue.pop();
				width++; //每pop一次，元素个数加一
			}
			maxWidth = maxWidth > width ? maxWidth : width;
		}
		std::cout << "树的最大宽度为：" << maxWidth << std::endl;
		return maxWidth;
	}

	T maxData(BinaryTreeNode<T>* Root) const //树中节点数据的最大值
	{
		//非递归算法
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
		std::cout << "树的最大节点元素为：" << maxData << std::endl;
*/
//递归算法
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
	void changeChild(BinaryTreeNode<T>* Root) //交换每个节点的左右孩子
	{
		//非递归实现
/*		using std::queue;
		queue< BinaryTreeNode<T>* > nodeQueue;
		BinaryTreeNode<T>* pointer = root;
		BinaryTreeNode<T>* tempNode = NULL;

		if (pointer)
			nodeQueue.push(pointer);
		while (!nodeQueue.empty())
		{
			pointer = nodeQueue.front();
			//交换孩子节点
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
//递归实现
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

	void deleteLeaf() //删除叶子节点
	{
		//非递归算法
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
			if (pointer->leftChild && pointer->leftChild->isLeaf()) //左孩子存在且为叶子，则删除并将pointer左孩子指针域置空
			{
				BinaryTreeNode<T>* tempNode = pointer->leftChild;
				delete tempNode;
				pointer->setLeftChild(NULL);
			}
			if (pointer->rightChild && pointer->rightChild->isLeaf()) //右孩子存在且为叶子，则删除并将pointer右孩子指针域置空
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
//递归算法
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
	void deleteBinary(BinaryTreeNode<T> *Root);		//删除以Root为根节点的子树

	BinaryTreeNode<T>* pre_in_create(T* pre, T* in, int n)  //先序中序建立二叉树
	{
		if (n == 0)
			return NULL;

		BinaryTreeNode<T>* rt;
		rt = new BinaryTreeNode<T>;
		rt->data = pre[0];
		//找到根节点在中序中的位置
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
	BinaryTreeNode<T>* in_post_create(T* post, T* in, int n, int m)  //后序中序建立二叉树
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



/*	void count_of_du() const //统计度为0、1、2的节点个数
{
//非递归算法
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
std::cout << "度为0的节点个数为：" << count0 << std::endl;
std::cout << "度为1的节点个数为：" << count1 << std::endl;
std::cout << "度为2的节点个数为：" << count2 << std::endl;
}
*/

