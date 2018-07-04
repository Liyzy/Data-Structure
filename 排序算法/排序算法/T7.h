#pragma once
#include <iostream>

template <class T>
void FindMaxMin(T* data, int n)
{
	using namespace std;
	int max = data[0];
	int min = data[0];
	for (int i = 1; i < n; i++)
	{
		if (data[i] < min)
		{
			min = data[i];
			continue;
		}
		if (data[i] > max)
			max = data[i];
	}
	cout << "MAX:" << max << endl;
	cout << "MIN:" << min << endl;
}
