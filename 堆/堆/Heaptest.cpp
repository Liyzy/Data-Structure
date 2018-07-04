#include<iostream>
#include"Heap.h"
int main()
{
	using namespace std;

	int arr[] = { 20,12,35,15,10,80,30,17,2,1 };
	MinHeap<int> myHeap;
	myHeap.intialize(arr, 10);
	myHeap.display();

	myHeap.Insert(18);
	myHeap.display();

	myHeap.DeleteTop(9);
	myHeap.display();

	cout << myHeap.Empty() << endl;

	system("pause");
}