#pragma once

template<class T>
class StackLinkNode
{
public:
	T data;
	StackLinkNode<T> *next;

	StackLinkNode() {}
	StackLinkNode(const T & dat, StackLinkNode<T> *ptr = 0) 
	{
		data = dat;
		next = ptr;
	}
};

template<class T>
class Stack
{
public:
	Stack(const int siz = 0)
	{
		Size = siz;
		Top = NULL;
	}
	~Stack()
	{
		clear();
	}
	void clear()
	{
		while (Top != NULL)
		{
			StackLinkNode<T> *temp = Top;
			Top = Top->next;
			delete temp;
		}
		Size = 0;
	}
	bool push(const T item)
	{
		StackLinkNode<T> *temp = new StackLinkNode<T>(item, Top);
		Top = temp;
		Size++;
		return true;
	}
	bool pop()
	{
		if (Size == 0)
		{
			std::cout << "栈为空，不能进行出栈操作！\n";
			return false;
		}
		StackLinkNode<T> *temp = Top;
		Top = Top->next;
		delete temp;
		Size--;
		return true;
	}
	bool top(T & item)
	{
		if (Size == 0)
		{
			std::cout << "栈空，无法读取栈顶元素！\n";
			return false;
		}
		item = Top->data;
		return true;
	}
	bool empty()
	{
		if (Size == 0)
			return true;
		return false;
	}
	int size()
	{
		return Size;
	}
	void swap(Stack& x) noexcept
	{
		StackLinkNode<T> *temp_T = x.Top;
		int temp_s = x.Size;

		x.Top = Top;
		Top = temp_T;
		
		x.Size = Size;
		Size = temp_s;
	}
private:
	StackLinkNode<T> *Top;
	int Size;
};
