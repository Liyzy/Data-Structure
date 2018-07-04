#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct HosNode
{
	int num; //�������ڽڵ��е�����
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
		TreeNode* Node17 = new TreeNode("���", 1);
		TreeNode* Node16 = new TreeNode("���", 2, NULL, Node17);
		TreeNode* Node15 = new TreeNode("������", 1);
		TreeNode* Node14 = new TreeNode("ϴ����", 1, NULL, Node15);
		TreeNode* Node13 = new TreeNode("����", 2);
		TreeNode* Node12 = new TreeNode("����", 4, Node16, Node13);
		TreeNode* Node11 = new TreeNode("������", 1, Node14, Node12);
		TreeNode* Node10 = new TreeNode("�ⷿ", 5);
		TreeNode* Node9 = new TreeNode("����", 21, Node11);
		TreeNode* Node8 = new TreeNode("��������", 1, Node10);
		TreeNode* Node7 = new TreeNode("������", 2, Node9, Node8);
		TreeNode* Node6 = new TreeNode("ɳ��", 2);
		TreeNode* Node5 = new TreeNode("����", 1, NULL, Node6);
		TreeNode* Node4 = new TreeNode("��¥", 4, Node7);
		TreeNode* Node3 = new TreeNode("�������", 1, Node5, Node4);
		TreeNode* Node2 = new TreeNode("¥��", 10, Node3);
		TreeNode* Node1 = new TreeNode("ҽԺ", 1, Node2);

		root = Node1;
	}

	TreeNode* getRoot() const
	{
		return root;
	}

	void levelOrder() const //ת����������Ĳ�α���
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
				temp = temp->lchild; //���ӽڵ�
				cout << " ";
				temp->print();
				temp = temp->nextSibling;  //���ӽڵ���ֵܽڵ�
				while (temp)
				{
					cout << " ";
					temp->print();
					temp = temp->nextSibling;
				}
			}
		}
		else
			cout << "��ҽԺ������" << s << "�ṹ��\n";
	}
	void FindParentPrint(const string s) const
	{
		//����ýṹ�Ƿ���ڣ�������ֱ������
		if (!FindwithName(s))
		{
			cout << s << "�ṹ�����ڣ�\n";
			return;
		}

		TreeNode* temp = FindParent(s);
		if (temp)
		{
			cout << s << "�ṹ�ĸ��ṹΪ��\n";
			temp->print();
		}
		else
			cout << s << "�ṹ�����ڸ��ṹ��\n";
	}


	void count(const string s_f, const string s_c) const
	{
		if (s_f == s_c) //����������Ϊһ��
		{
			cout << "Ϊͬһ���ṹ��\n";
			return;
		}

		int number = 1;
		TreeNode* father = FindParent(s_c);
		TreeNode* child = FindwithName(s_c);

		while (father)
		{
			if (father->m_hosNode.name == s_f)
			{
				cout << s_f << "�ṹ�а���" << number*(child->m_hosNode.num) << "��" << s_c << "�ṹ\n";
				return;
			}
			else
			{
				number *= child->m_hosNode.num;
				child = father;
				father = FindParent(child->m_hosNode.name);
			}
		}
		cout << s_f << "�ṹ�в�����" << s_c << "�ṹ" << endl;
	}

	friend ostream & operator<<(ostream & out, const HosNode & hosNode);
};

ostream & operator<<(ostream & out, const HosNode & hosNode)
{
	out << hosNode.name << ":" << hosNode.num << endl;
	return out;
}