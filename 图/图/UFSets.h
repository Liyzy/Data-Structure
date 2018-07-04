#pragma once
#include <iostream>

class UFSets
{
private:
	int n;   //�ȼ�����Ԫ�ظ���
	int* root;  //i��Ԫ�صĴ���Ԫ
	int* next;  //i��Ԫ�صĺ��
	int* length;  //i��Ԫ��Ϊ����Ԫ��Ԫ�ظ���
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
		else if (length[root[v]] < length[root[u]])   //��v�Ĵ���Ԫ�ĵȼ���ϲ���u�Ĵ���Ԫ�ĵȼ���
		{
			length[root[u]] += length[root[v]];
			length[root[v]] = 0;
			//��v�ȼ����е�Ԫ�ش���Ԫ��Ϊu
			int rt = root[v];
			root[rt] = root[u];
			for (int i = next[rt]; i != rt;)
			{
				root[i] = root[u];
				i = next[i];
			}
			//���������ȼ������Ԫ��ֱ�Ӻ��
			next[root[v]] = next[rt];
			next[rt] = next[root[u]];
		}
		else if (length[root[v]] > length[root[u]]) //ͬ��
		{
			length[root[v]] += length[root[u]];
			length[root[u]] = 0;
			//��u�ȼ����е�Ԫ�ش���Ԫ��Ϊv
			int rt = root[u];
			root[rt] = root[v];
			for (int i = next[rt]; i != rt;)
			{
				root[i] = root[v];
				i = next[i];
			}
			//���������ȼ������Ԫ��ֱ�Ӻ��
			next[root[u]] = next[rt];
			next[rt] = next[root[v]];
		}
	}
};
