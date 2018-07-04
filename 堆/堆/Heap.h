#pragma once

#include<iostream>
template<class T>
class MinHeap
{
private:
	T* heapArray;  //数据数组
	int MaxSize;  //最大容量
	int CurrentSize;   //当前元素个数
public:
	MinHeap(int cur = 0, int size = 100)
	{
		heapArray = new T[size];
		MaxSize = size;
		CurrentSize = cur;
	}

	void intialize(T* arr, int size)
	{
		CurrentSize = size;
		for (int m = 0; m < CurrentSize; m++)
			heapArray[m] = arr[m];

		int start = CurrentSize / 2 - 1;

		for (; start >= 0; start--)
			shiftDown(start);
	}

	void display() const
	{
		for (int i = 0; i < CurrentSize; i++)
			std::cout << heapArray[i] << "\t";
		std::cout << std::endl;
	}

	bool Insert(const T& value)
	{
		if (CurrentSize + 1 > MaxSize)
			return false;

		heapArray[CurrentSize] = value;
		int i = CurrentSize;
		CurrentSize += 1;

		shiftUp(i);
		return true;
	}

	bool DeleteTop(int number=0)//默认删除0号节点，即根节点
	{
		if (number > CurrentSize)
			return false;

		heapArray[number] = heapArray[CurrentSize - 1];
		CurrentSize -= 1;
		shiftDown(number);
		shiftUp(number);
		return true;
	}

	void shiftDown(int start)
	{
		int i = start;   //开始的下标
		int j = 2 * i + 1;
		T temp = heapArray[i];

		while (j < CurrentSize)
		{
			if (j + 1 < CurrentSize&&heapArray[j] > heapArray[j + 1]) //有右孩子且右孩子大于左孩子
				j++;   //j改为右孩子下标
			if (temp > heapArray[j])
			{
				heapArray[i] = heapArray[j];
				heapArray[j] = temp;
				i = j;
				j = 2 * i + 1;
			}
			else
				break;
		}
	}

	void shiftUp(int i)
	{
		while (i >= 0) //不是根节点就向上转移
		{
			if (heapArray[i] < heapArray[(i - 1) / 2])
			{
				T temp = heapArray[i];
				heapArray[i] = heapArray[(i - 1) / 2];
				heapArray[(i - 1) / 2] = temp;
				i = (i - 1) / 2;
			}
			else
				break;
		}
	}
	bool Empty()
	{
		if (CurrentSize == 0)
			return true;
		return false;
	}

	T GetTop()
	{
		return heapArray[0];
	}
};
