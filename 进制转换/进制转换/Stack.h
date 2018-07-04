#pragma once
template<class T>
class Stack
{
public:
	Stack(int Size)
	{
		maxSize = Size;
		top = -1;
		st = new T[maxSize];
	}
	Stack()
	{
		top = -1;
	}
	bool empty();
	bool push(const T item);
	bool pop();
	bool top();
private:
	int maxSize;
	int top;
	T *st;
};
