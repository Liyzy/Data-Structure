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

	/*cout << "ֱ�Ӳ�������\n";
	InsertionSort(data, N);
	display(data, N);*/

	/*cout << "�۰��������\n";
	BInsertionSort(data, N);
	display(data, N);*/

	/*cout << "ð������\n";
	start = clock();
	BubbleSort(data, N);
	end = clock();
	cout << "ð����������ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << "s.\n";
 	display(data, N);*/

	cout << "��������\n";
	start = clock();
	QuickSort(data, 0, N - 1);
	end = clock();
	cout << "������������ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC<< "s.\n";
	display(data, N);

	/*cout << "ѡ������\n";
	SelectionSort(data, N);
	display(data, N);*/

	/*cout << "�鲢����\n";
	MergeSort(data, 0, N - 1);
	display(data, N);*/

	/*int data[10] = { 1,-10,-8,3,4,5,6,-5,8,7 };
	display(data, 10);
	SortForint(data, 10);
	display(data, 10);*/

	/*FindMaxMin(data, N);*/

	system("pause");
}