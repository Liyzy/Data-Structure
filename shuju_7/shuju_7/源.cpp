#include <stdio.h>
#include <iostream>
using namespace std;
class Link {
public:
	class Node {
	public:
		int t;
		Node * next;
		Node * front;
		Node(int &tt, Node * f = NULL, Node * nn = NULL) :t(tt), next(nn), front(f)
		{
			if (front) {
				front->next = this;
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
		cin.clear();
		while (cin >> t) {
			Node * node = new Node(t, p);
			p = node;
			++count;
		}
		char c;
		cin.clear();
		while ((c = getchar()) != '\n')
		{
			;
		}
	}
	void show() {
		Node * p = head;
		while (p) {
			cout << p->t << " ";
			p = p->next;
		}
		cout << endl;
	}
	void test()
	{
		typedef Node * N;
		N h1, p1, h2, p2, p3;
		bool flag = true;
		h1 = p1 = head;
		h2 = p2 = p3 = head->next;
		N t = head->next->next;
		while (t != NULL)
		{
			if (flag) {
				p1 = p1->next = t;
				t = t->next;

			}
			else {
				p3 = t;
				t = t->next;
				p3->next = p2;
				p2 = p3;
			}
			flag = !flag;
		}
		p1->next = p2;
		h2->next = NULL;
	}
};

int main() {
	Link list;
	list.creat();
	list.show();
	list.test();
	list.show();
	system("pause");
}
