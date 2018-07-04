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
//求平均值
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
//求节点个数
int _Number(LinkNode *p)
{
	if (!p->next)
		return 1;
	else
		return _Number(p->next) + 1;
}
//找最大值
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
	int max, nodeNumber;
	double average;
	LinkNode *first = Creat();
	Display(first);
	max = _Max(first);
	cout <<"最大值为："<< max <<endl;
	nodeNumber = _Number(first);
	cout<<"节点数为："<<nodeNumber<<endl;
	average = _Average(first, nodeNumber);
	cout << "平均值为：" << average << endl;
	system("pause");
}