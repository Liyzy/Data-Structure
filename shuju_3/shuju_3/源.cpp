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
//���
bool Display(LinkNode *p)
{
	if (p == NULL)
	{
		cout << "����Ϊ�գ�";
		return false;
	}
	else
	{
		cout << "����Ϊ��";
		while (p)
		{
			cout << p->data<<" ";
			p = p->next;
		}
		cout << endl;
		return true;
	}
}
//����
LinkNode* Reverse(LinkNode *p)
{
	if (!p)
	{
		cout << "����Ϊ�գ�" << endl;
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
	cout << "�� -1 ��Ϊ���������־\n";
	cout << "����������Ԫ�أ�";
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
	cout << "����";
	LinkNode *reverse = Reverse(first);
	Display(reverse);
	system("pause");
}