
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

	bool EnQueue(const T item) //��Ӳ���
	{
		if ((rear + 1) % maxSize == front)
		{
			cout << "�������������" << endl;
			return false;
		}
		queue[rear] = item;
		rear = (rear + 1) % maxSize;  //rearָ��ʵ�ʶ�β����һ��
		return true;
	}

	bool DeQueue()  //ɾ������Ԫ�أ�������ֵ(�����м�T & item)
	{
		if (front == rear)
		{
			cout << "����Ϊ��\n";
			return false;
		}
		//item = queue[front];
		front = (front + 1) % maxSize;  //frontʵ�ʶ��׵�λ��
		return true;
	}

	bool GetFront(T & item)
	{
		if (front == rear)
		{
			cout << "����Ϊ��\n";
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
	int maxSize;   //���������С
	int front;     //��������λ���±�
	int rear;      //��β����λ���±�
	T *queue;
};