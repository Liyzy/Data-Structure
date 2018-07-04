
template <class T>
class Queue
{
public:
	Queue(int size = 100)
	{
		maxSize = size + 1;
		queue = new T[maxSize];
		front = rear = 0;
	}

	void Clear()
	{
		front = rear;
	}

	bool EnQueue(const T item) //入队操作
	{
		if ((rear + 1) % maxSize == front)
		{
			cout << "队列已满，溢出" << endl;
			return false;
		}
		queue[rear] = item;
		rear = (rear + 1) % maxSize;  //rear指向实际队尾的下一个
		return true;
	}

	bool DeQueue()  //删除队首元素，并返回值(参数中加T & item)
	{
		if (front == rear)
		{
			cout << "队列为空\n";
			return false;
		}
		//item = queue[front];
		front = (front + 1) % maxSize;  //front实际队首的位置
		return true;
	}

	bool GetFront(T & item)
	{
		if (front == rear)
		{
			cout << "队列为空\n";
			return false;
		}
		item = queue[front];
		return true;
	}

	bool IfEmpty()
	{
		if (front == rear)
			return false;
		return true;
	}
private:
	int maxSize;   //队列数组大小
	int front;     //队首所在位置下标
	int rear;      //队尾所在位置下标
	T *queue;
};