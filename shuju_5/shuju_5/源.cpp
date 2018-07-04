#include <iostream>
using namespace std;
class LinkNode
{
public:
	int data;
	LinkNode *next;
	LinkNode(){}
	LinkNode(const int&d1, LinkNode*ptr = 0)
	{
		data = d1;
		next = ptr;
	}
};
//归并链表
LinkNode * Combine(LinkNode *p1, LinkNode *p2)
{
	LinkNode *p3, *first3;
	first3 = new LinkNode;
	first3->next = p1;
	p3 = first3;

	while (p1 && p2)
	{
		if (p1->data <= p2->data)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;

	return first3->next;
}
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
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
		return true;
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
	LinkNode *first3;
	LinkNode *first1 = Creat();
	Display(first1);
	LinkNode *first2 = Creat();
	Display(first2);
	first3 = Combine(first1, first2);
	cout<<"合并";
	Display(first3);
	system("pause");
}