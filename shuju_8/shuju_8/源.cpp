#include<stdio.h>
#include <iostream>
using namespace std;
class Link {
public:
	class Node {
	public:
		int t;
		Node * next;
		Node * frontp;
		Node(int &tt, Node * f = NULL, Node * nn = NULL) :t(tt), next(nn), frontp(f) 
		{
			if (frontp)
			{
				frontp->next = this;
			}
		}
	};
	int count;
	Node * head;
public:
	void creat() {
		int t;
		cout << "输入链表元素，按E结束输入" << endl;
		cin >> t;
		head = new Node(t);
		Node * p = head;
		++count;
		while (cin >> t) {
			Node * node = new Node(t, p);
			p = node;
			++count;
		}
		char c;
		cin.clear();
		while ((c = getchar()) != '\n');
		p->next = head;
		head->frontp = p;
	}
	void show() {
		Node * p = head;
		for (; p->next != head; p = p->next) {
			cout << p->t << " ";
		}
		cout << p->t << endl;
	}
	void test() 
	{
		int x;
		cout << "输入要删除的数据：" << endl;
		cin >> x;
		for (Node * p = head; p->next != head; p = p->next) 
		{
			head = head->next;
			if (p->t == x) 
			{
				Node * f = p->frontp;
				f->next = p->next;
				p->next->frontp = f;
				delete p;
				count--;
				return;
			}
		}
		cout << "没有" << endl;
	}
};
int main() {

	Link list;
	list.creat();
	list.test();
	list.show();
	system("pause");
}
