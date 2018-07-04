#pragma once
#include <iostream>
#include <algorithm>

template <class T>
void display(T* data, int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << endl;
}
//直接插入排序
template <class T>
void InsertionSort(T* data, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		T temp = data[i];
		j = i - 1;
		while (j >= 0 && data[j] > temp)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = temp;
	}
}

//折半插入排序
template<class T>
void BInsertionSort(T* data, int n)
{
	int left, right, mid, p;
	for (p = 1; p < n; p++)
	{
		T temp = data[p];
		left = 0;
		right = p - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (data[mid] > temp)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int i = p - 1; i >= left; i--)
			data[i + 1] = data[i];
		data[left] = temp;
	}
}

//冒泡排序
template<class T>
void BubbleSort(T* data, int n)
{
	int i, j;
	bool flag = 0; //标记是否在一趟排序中发生了交换
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
			if (data[j] < data[j - 1])
			{
				flag = 1;
				T temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		if (flag == 0)
			return;
	}
}

//快速排序
	//分割策略1
template<class T>
int Partition_1(T* data, int left, int right)
{
	T pivot = data[left];
	while (left < right)
	{
		while (left < right && data[left] < pivot)
			left++;
		while (left < right && data[right] > pivot)
			right--;
		if (left < right)
			swap(data[left], data[right]);
	}
	swap(data[right], pivot);
	return right;
}
//分割策略2
template<class T>
int Partition_2(T* data, int left, int right)
{
	T pivot = data[left];
	while (left < right)
	{
		while (left<right && data[right]>pivot)
			right--;
		data[left] = data[right];
		while (left < right && data[left] <= pivot)
			left++;
		data[right] = data[left];
	}
	if(left==right)
		data[left] = pivot;
	return left;
}
template <class T>
void QuickSort(T* data, int left, int right)
{
	if (left < right)
	{
		int p = Partition_1(data, left, right);
		QuickSort(data, left, p - 1);
		QuickSort(data, p + 1, right);
	}
}

//选择排序
template<class T>
void SelectionSort(T* data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int mix = i;
		for (int j = i + 1; j < n; j++)
			if (data[j] < data[mix])
				mix = j;
		swap(data[i], data[mix]);
	}
}

//归并排序
	//归并两个有序表
template <class T>
void Merge(T* data, int start, int mid, int end)
{
	int len1 = mid - start + 1;
	int len2 = end - mid;
	T* left = new T[len1];
	T* right = new T[len2];
	int i, j, k;
	//复制数据
	for (i = 0; i < len1; i++)
		left[i] = data[start + i];
	for (i = 0; i < len2; i++)
		right[i] = data[mid + 1 + i];
	//依次选择最小的元素插入到原序列中
	j = k = 0;
	for (i = start; i < end; i++)
	{
		if (j == len1 || k == len2)
			break;
		if (left[j] <= right[k])
			data[i] = left[j++];
		else
			data[i] = right[k++];
	}
	while (j < len1)
		data[i++] = left[j++];
	while (k < len2)
		data[i++] = right[k++];
	delete[]left;
	delete[]right;
}
template<class T>
void MergeSort(T* data, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(data, start, mid);
		MergeSort(data, mid + 1, end);
		Merge(data, start, mid, end);
	}
}