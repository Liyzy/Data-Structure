#include <iostream>
#include <ctime>
#include "Sort.h"
#include "T6.h"
#include "T7.h"
#define N 100
using namespace std;

int main()
{
	int* data = new int[N];
	clock_t start, end;
	srand(time(0));
	for (int i = 0; i < N; i++)
		data[i] = rand() % 60000 + 1;
	display(data, N);

	/*cout << "直接插入排序：\n";
	InsertionSort(data, N);
	display(data, N);*/

	/*cout << "折半插入排序：\n";
	BInsertionSort(data, N);
	display(data, N);*/

	/*cout << "冒泡排序：\n";
	start = clock();
	BubbleSort(data, N);
	end = clock();
	cout << "冒泡排序所用时间：" << (double)(end - start) / CLOCKS_PER_SEC << "s.\n";
 	display(data, N);*/

	cout << "快速排序：\n";
	start = clock();
	QuickSort(data, 0, N - 1);
	end = clock();
	cout << "快速排序所用时间：" << (double)(end - start) / CLOCKS_PER_SEC<< "s.\n";
	display(data, N);

	/*cout << "选择排序：\n";
	SelectionSort(data, N);
	display(data, N);*/

	/*cout << "归并排序：\n";
	MergeSort(data, 0, N - 1);
	display(data, N);*/

	/*int data[10] = { 1,-10,-8,3,4,5,6,-5,8,7 };
	display(data, 10);
	SortForint(data, 10);
	display(data, 10);*/

	/*FindMaxMin(data, N);*/

	system("pause");
}