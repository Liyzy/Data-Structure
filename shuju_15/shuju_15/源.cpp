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

	bool EnQueue(const T item) //入队操作
	{
		if (rear == front && tag == 1)
		{
			cout << "队列已满，溢出" << endl;
			return false;
		}
		queue[rear + 1] = item;
		rear = (rear + 1) % maxSize;
		tag = 1;
		return true;
	}

	bool DeQueue()  //删除队首元素，并返回值(参数中加T & item)
	{
		if (tag == 0)
		{
			cout << "队列为空,没有元素可以删除\n";
			return false;
		}
		//item = queue[front];
		front = (front + 1) % maxSize;  //front实际队首的位置
		if (front % maxSize == rear)
			tag = 0;
		return true;
	}

	bool GetFront(T & item)
	{
		if (tag == 0)
		{
			cout << "队列为空，没有队首可以获得\n";
			return false;
		}
		item = queue[front + 1];
		return true;
	}
private:
	int maxSize;   //队列数组大小
	int front;     //队首所在位置下标
	int rear;      //队尾所在位置下标
	bool tag;      //表示队列是否为空（0）
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