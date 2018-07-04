#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct HosNode
{
	int num; //该内容在节点中的数量
	string name;
};

class Tree;
class TreeNode
{
	friend class Tree;
private:
	HosNode m_hosNode;
	TreeNode* lchild;
	TreeNode* nextSibling;
public:
	TreeNode(string s, int n = 1, TreeNode* lc = NULL, TreeNode* ns = NULL)
	{
		m_hosNode.name = s;
		m_hosNode.num = n;
		lchild = lc;
		nextSibling = ns;
	}

	~TreeNode()
	{
		delete &m_hosNode;
		delete lchild;
		delete nextSibling;
	}

	HosNode getValue()
	{
		return m_hosNode;
	}
	TreeNode* getlchild()
	{
		return lchild;
	}
	TreeNode* getnextSibling()
	{
		return nextSibling;
	}

	void setValue(string s, int n)
	{
		m_hosNode.name = s;
		m_hosNode.num = n;
	}
	void setlchild(TreeNode* lc)
	{
		lchild = lc;
	}
	void setnextSibling(TreeNode* ns)
	{
		nextSibling = ns;
	}

	void print()
	{
		cout << m_hosNode.name << "*" << m_hosNode.num << endl;
	}
};

class Tree
{
private:
	TreeNode* root;
public:
	Tree(TreeNode* rt = NULL)
	{
		root = rt;
	}

	~Tree()
	{

	}

	void Create()
	{
		TreeNode* Node17 = new TreeNode("面板", 1);
		TreeNode* Node16 = new TreeNode("插口", 2, NULL, Node17);
		TreeNode* Node15 = new TreeNode("坐便器", 1);
		TreeNode* Node14 = new TreeNode("洗面盆", 1, NULL, Node15);
		TreeNode* Node13 = new TreeNode("病床", 2);
		TreeNode* Node12 = new TreeNode("插座", 4, Node16, Node13);
		TreeNode* Node11 = new TreeNode("卫生间", 1, Node14, Node12);
		TreeNode* Node10 = new TreeNode("库房", 5);
		TreeNode* Node9 = new TreeNode("病房", 21, Node11);
		TreeNode* Node8 = new TreeNode("走廊连接", 1, Node10);
		TreeNode* Node7 = new TreeNode("长走廊", 2, Node9, Node8);
		TreeNode* Node6 = new TreeNode("沙发", 2);
		TreeNode* Node5 = new TreeNode("电视", 1, NULL, Node6);
		TreeNode* Node4 = new TreeNode("配楼", 4, Node7);
		TreeNode* Node3 = new TreeNode("中央大厅", 1, Node5, Node4);
		TreeNode* Node2 = new TreeNode("楼层", 10, Node3);
		TreeNode* Node1 = new TreeNode("医院", 1, Node2);

		root = Node1;
	}

	TreeNode* getRoot() const
	{
		return root;
	}

	void levelOrder() const //转换后二叉树的层次遍历
	{
		using std::queue;

		queue<TreeNode*> myQueue;
		TreeNode* pointer = root;

		if (root == NULL)
			return;
		myQueue.push(root);
		while (!myQueue.empty())
		{
			pointer = myQueue.front();
			myQueue.pop();
			pointer->print();

			if (pointer->lchild)
				myQueue.push(pointer->lchild);
			if (pointer->nextSibling)
				myQueue.push(pointer->nextSibling);
		}
	}
	void preOrder(TreeNode* Root) const
	{
		if (Root == NULL)
			return;

		Root->print();
		preOrder(Root->lchild);
		preOrder(Root->nextSibling);
	}
	void inOrder(TreeNode* Root) const
	{
		if (Root == NULL)
			return;

		inOrder(Root->lchild);
		Root->print();
		inOrder(Root->nextSibling);
	}

	TreeNode* FindwithName(const string s) const
	{
		using std::queue;

		queue<TreeNode*> myQueue;
		TreeNode* pointer = root;

		if (root == NULL)
			return NULL;
		myQueue.push(root);
		while (!myQueue.empty())
		{
			pointer = myQueue.front();
			myQueue.pop();
			if (pointer->m_hosNode.name == s)
				return pointer;

			if (pointer->lchild)
				myQueue.push(pointer->lchild);
			if (pointer->nextSibling)
				myQueue.push(pointer->nextSibling);
		}
		return NULL;
	}
	TreeNode* FindParent(const string s) const
	{
		using std::queue;

		queue<TreeNode*> myQueue;
		TreeNode* pointer = root;
		TreeNode* father = NULL;

		if (root == NULL)
			return NULL;
		myQueue.push(root);
		while (!myQueue.empty())
		{
			pointer = myQueue.front();
			myQueue.pop();
			if (pointer->lchild && pointer->lchild->m_hosNode.name == s)
				return pointer;
			if (pointer->lchild && pointer->lchild->m_hosNode.name != s)
			{
				TreeNode* temp = pointer->lchild;
				while (temp->nextSibling)
				{
					if (temp->nextSibling->m_hosNode.name == s)
						return pointer;
					temp = temp->nextSibling;
				}
			}

			if (pointer->lchild)
				myQueue.push(pointer->lchild);
			if (pointer->nextSibling)
				myQueue.push(pointer->nextSibling);
		}
		return NULL;
	}
	void FindPrint(const string s) const
	{
		TreeNode* temp = FindwithName(s);
		if (temp)
		{
			temp->print();
			if (temp->lchild)
			{
				temp = temp->lchild; //孩子节点
				cout << " ";
				temp->print();
				temp = temp->nextSibling;  //孩子节点的兄弟节点
				while (temp)
				{
					cout << " ";
					temp->print();
					temp = temp->nextSibling;
				}
			}
		}
		else
			cout << "该医院不存在" << s << "结构！\n";
	}
	void FindParentPrint(const string s) const
	{
		//检验该结构是否存在，不存在直接跳出
		if (!FindwithName(s))
		{
			cout << s << "结构不存在！\n";
			return;
		}

		TreeNode* temp = FindParent(s);
		if (temp)
		{
			cout << s << "结构的父结构为：\n";
			temp->print();
		}
		else
			cout << s << "结构不存在父结构！\n";
	}


	void count(const string s_f, const string s_c) const
	{
		if (s_f == s_c) //包含自身则为一个
		{
			cout << "为同一个结构！\n";
			return;
		}

		int number = 1;
		TreeNode* father = FindParent(s_c);
		TreeNode* child = FindwithName(s_c);

		while (father)
		{
			if (father->m_hosNode.name == s_f)
			{
				cout << s_f << "结构中包含" << number*(child->m_hosNode.num) << "个" << s_c << "结构\n";
				return;
			}
			else
			{
				number *= child->m_hosNode.num;
				child = father;
				father = FindParent(child->m_hosNode.name);
			}
		}
		cout << s_f << "结构中不存在" << s_c << "结构" << endl;
	}

	friend ostream & operator<<(ostream & out, const HosNode & hosNode);
};

ostream & operator<<(ostream & out, const HosNode & hosNode)
{
	out << hosNode.name << ":" << hosNode.num << endl;
	return out;
}