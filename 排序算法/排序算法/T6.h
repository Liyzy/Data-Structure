#pragma once
#include <iostream>
#include <algorithm>

void SortForInt(int* data, int n)
{
	using namespace std;
	int left = 0, right = n - 1;
	while (left < right)
	{
		while (left < right && data[left] < 0)
			left++;
		while (left < right && data[right]>0)
			right--;
		if (left < right)
			swap(data[left], data[right]);
	}
}
