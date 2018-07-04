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
//��ƽ��ֵ
double _Average(LinkNode *p,int number)
{
	if (!p->next)
		return ((double)p->data) / number;
	else
	{
		double temp = _Average(p->next, number);
		return temp + ((double)p->data) / number;
	}
}
//��ڵ����
int _Number(LinkNode *p)
{
	if (!p->next)
		return 1;
	else
		return _Number(p->next) + 1;
}
//�����ֵ
int _Max(LinkNode *p)
{
	if (!p->next)
		return p->data;
	else
	{
		int temp = _Max(p->next);
		return p->data >= temp ? p->data : temp;
	}
}
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
	int max, nodeNumber;
	double average;
	LinkNode *first = Creat();
	Display(first);
	max = _Max(first);
	cout <<"���ֵΪ��"<< max <<endl;
	nodeNumber = _Number(first);
	cout<<"�ڵ���Ϊ��"<<nodeNumber<<endl;
	average = _Average(first, nodeNumber);
	cout << "ƽ��ֵΪ��" << average << endl;
	system("pause");
}