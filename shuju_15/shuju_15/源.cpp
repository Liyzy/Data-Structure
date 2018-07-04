#include <iostream>
#include <queue>
using namespace std;
template <class T>
class Queue
{
public:
	Queue(int size)
	{
		maxSize = size;
		queue = new T[maxSize];
		rear = front = 0;
		tag = 0;
	}
	
	void Clear()
	{
		front = rear;
		tag = 0;
	}

	bool EnQueue(const T item) //��Ӳ���
	{
		if (rear == front && tag == 1)
		{
			cout << "�������������" << endl;
			return false;
		}
		queue[rear + 1] = item;
		rear = (rear + 1) % maxSize;
		tag = 1;
		return true;
	}

	bool DeQueue()  //ɾ������Ԫ�أ�������ֵ(�����м�T & item)
	{
		if (tag == 0)
		{
			cout << "����Ϊ��,û��Ԫ�ؿ���ɾ��\n";
			return false;
		}
		//item = queue[front];
		front = (front + 1) % maxSize;  //frontʵ�ʶ��׵�λ��
		if (front % maxSize == rear)
			tag = 0;
		return true;
	}

	bool GetFront(T & item)
	{
		if (tag == 0)
		{
			cout << "����Ϊ�գ�û�ж��׿��Ի��\n";
			return false;
		}
		item = queue[front + 1];
		return true;
	}
private:
	int maxSize;   //���������С
	int front;     //��������λ���±�
	int rear;      //��β����λ���±�
	bool tag;      //��ʾ�����Ƿ�Ϊ�գ�0��
	T *queue;
};
int main()
{
	char item;
	Queue<char> my_Queue(5);
	my_Queue.EnQueue('a');
	my_Queue.DeQueue();
	my_Queue.EnQueue('b');
	my_Queue.DeQueue();
	my_Queue.EnQueue('c');
	my_Queue.DeQueue();
	my_Queue.EnQueue('d');
	my_Queue.DeQueue();
	//my_Queue.Clear();
	//my_Queue.GetFront(item);
    my_Queue.EnQueue('e');
	my_Queue.GetFront(item);
	cout << item;
	system("pause");
}