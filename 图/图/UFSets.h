#pragma once
#include <iostream>

class UFSets
{
private:
	int n;   //等价类中元素个数
	int* root;  //i号元素的代表元
	int* next;  //i号元素的后继
	int* length;  //i号元素为代表元的元素个数
public:
	UFSets(int size)
	{
		n = size;
		root = new int[n];
		next = new int[n];
		length = new int[n];
		for (int i = 0; i < n; i++)
		{
			root[i] = i;
			next[i] = i;
			length[i] = 1;
		}
	}
	int Find(int v)
	{
		return root[v];
	}

	void Union(int v, int u)
	{
		if (root[u] == root[v])
			return;
		else if (length[root[v]] < length[root[u]])   //把v的代表元的等价类合并到u的代表元的等价类
		{
			length[root[u]] += length[root[v]];
			length[root[v]] = 0;
			//将v等价类中的元素代表元改为u
			int rt = root[v];
			root[rt] = root[u];
			for (int i = next[rt]; i != rt;)
			{
				root[i] = root[u];
				i = next[i];
			}
			//交换两个等价类代表元的直接后继
			next[root[v]] = next[rt];
			next[rt] = next[root[u]];
		}
		else if (length[root[v]] > length[root[u]]) //同上
		{
			length[root[v]] += length[root[u]];
			length[root[u]] = 0;
			//将u等价类中的元素代表元改为v
			int rt = root[u];
			root[rt] = root[v];
			for (int i = next[rt]; i != rt;)
			{
				root[i] = root[v];
				i = next[i];
			}
			//交换两个等价类代表元的直接后继
			next[root[u]] = next[rt];
			next[rt] = next[root[v]];
		}
	}
};
