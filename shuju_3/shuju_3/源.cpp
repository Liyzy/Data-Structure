#include <iostream>
using namespace std;
class LinkNode
{
public:
	int data;
	LinkNode *next;
	LinkNode(const int&d1, LinkNode*ptr = 0)
	{
		data = d1;
		next = ptr;
	}
};
//输出
bool Display(LinkNode *p)
{
	if (p == NULL)
	{
		cout << "链表为空！";
		return false;
	}
	else
	{
		cout << "链表为：";
		while (p)
		{
			cout << p->data<<" ";
			p = p->next;
		}
		cout << endl;
		return true;
	}
}
//倒置
LinkNode* Reverse(LinkNode *p)
{
	if (!p)
	{
		cout << "链表为空！" << endl;
		return NULL;
	}
	else
	{
		LinkNode *prev = NULL;
		LinkNode *link = NULL;
		while (p)
		{
			link = p->next;
			p->next = prev;
			prev = p;
			p = link;
		}
		return prev;
	}
}
LinkNode *Creat()
{
	int data;
	cout << "以 -1 作为输入结束标志\n";
	cout << "请输入链表元素：";
	LinkNode *p, *first;
	cin >> data;
	if (data != -1)
	{
		p = new LinkNode(data);
		first = p;
		for (;;)
		{
			cin >> data;
			if (data != -1)
			{
				LinkNode *tp = new LinkNode(data);
				p->next = tp;
				p = tp;
			}
			else
				break;
		}
		return first;
	}
	else
		return NULL;
}
int main()
{
	LinkNode *first = Creat();
	Display(first);
	cout << "倒置";
	LinkNode *reverse = Reverse(first);
	Display(reverse);
	system("pause");
}