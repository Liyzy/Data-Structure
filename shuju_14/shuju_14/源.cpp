#include <iostream>
#include "Queue.h"
using namespace std;
struct link
{
	Queue <int> * q;
	struct link * next;
};
int main()
{
	Queue <int> Q[10];
	int n, i, count = 0;
	int item = -1;
    link * front, *l1, *l2;
	cout << "请输入0-9以内（包括0和9）的数字：";
	cin >> n;
	while (n >= 0 && n <= 9)
	{
		Q[n].EnQueue(n);
		cin >> n;
	}
	front = l2 = new link;
	for (i = 0; i<10; i++)
	{
		if (Q[i].IfEmpty())
		{
			count++;
			l1 = l2;
			l1->q = &Q[i];
			l2 = new link;
			l1->next = l2;
		}
	}
	l1->next = NULL;
	delete l2;
	l1 = front;
	for (i = 0; i<count; i++)
	{
		if (l1->q->IfEmpty())
		{
			l1->q->GetFront(item);
			cout << "队列" << item << ":  ";
		}
		while (l1->q->IfEmpty())
		{
		    l1->q-> GetFront(item);
			cout << item << " ";
			l1->q->DeQueue();
		}
		cout << endl;
		l1 = l1->next;
	}
	system("pause");
}
