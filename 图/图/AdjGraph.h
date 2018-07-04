#pragma once
#include <iostream>
#include <cmath>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>
#include "UFSets.h"
#include "MinHeap.h"

using namespace std;

template <class EdgeType>
class Edge
{
public:
	int start, end;
	int weight;

	Edge()
	{
		start = end = weight = -1;
	}
	Edge(int st, int en, int w)
	{
		start = st;
		end = en;
		weight = w;
	}
	Edge(Edge<EdgeType> & e)
	{
		start = e.start;
		end = e.end;
		weight = e.weight;
	}
	bool operator>(Edge & oneEdge) const
	{
		if (weight > oneEdge.weight)
			return true;
		return false;
	}
	bool operator<(Edge & oneEdge) const
	{
		if (weight < oneEdge.weight)
			return true;
		return false;
	}
};

template <class EdgeType>
class Graph
{
public:
	int vertexNum;  //������
	int edgeNum;   //����
	bool* flag;   //�Ƿ񱻷��ʹ��ı�־

	Graph(int VN)
	{
		vertexNum = VN;
		edgeNum = 0;
		flag = new bool[VN];
		for (int i = 0; i < VN; i++)
			flag[i] = 0;
	}

	~Graph()
	{
		delete[] flag;
	}

	virtual Edge<EdgeType> FirstEdge(int oneVertex) = 0;
	virtual Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge) = 0;

	int GetvertexNum() const
	{
		return vertexNum;
	}
	int GetedgeNum() const
	{
		return edgeNum;
	}
	bool IsEdge(Edge<EdgeType> oneEdge)
	{
		if (oneEdge.weight > 0 && oneEdge.weight <= INT32_MAX&&
			oneEdge.end >= 0 && oneEdge.end < vertexNum&&oneEdge.start >= 0 && oneEdge.start < vertexNum)
			return true;
		return false;
	}
	int StartVertex(Edge<EdgeType> oneEdeg)
	{
		return oneEdeg.start;
	}
	int EndVertex(Edge<EdgeType> oneEdeg)
	{
		return oneEdeg.end;
	}
	int Weight(Edge<EdgeType> oneEdge)
	{
		return oneEdge.weight;
	}
	virtual void setEdge(int start, int end, int weight) = 0;
	virtual void delEdge(int start, int end) = 0;
};

template <class EdgeType>
class AdjGraph :public Graph<EdgeType>
{
private:
	int **matrix;
	int* order;
	int count;
public:
	AdjGraph(int verticesNum) :Graph<EdgeType>(verticesNum)
	{
		int i, j;
		matrix = (int**) new int*[verticesNum];
		for (i = 0; i < verticesNum; i++)
			matrix[i] = new int[verticesNum];

		for (i = 0; i < verticesNum; i++)
			for (j = 0; j < verticesNum; j++)
				matrix[i][j] = 0;
		order = new int[verticesNum];
		for (int i = 0; i < verticesNum; i++)
			order[i] = -1;
		count = 0;
	}

	Edge<EdgeType> FirstEdge(int oneVertex) //���ض���ĵ�һ����
	{
		Edge<EdgeType> tempEdge;
		tempEdge.start = oneVertex;
		for (int i = 0; i < vertexNum; i++)
		{
			if (matrix[oneVertex][i] != 0)
			{
				tempEdge.end = i;
				tempEdge.weight = matrix[oneVertex][i];
				return tempEdge;
			}
		}
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)  //��������ͬ������һ����
	{
		Edge<EdgeType> tempEdge;
		tempEdge.start = oneEdge.start;
		for (int i = oneEdge.end + 1; i < vertexNum; i++)
		{
			if (matrix[tempEdge.start][i] != 0)
			{
				tempEdge.end = i;
				tempEdge.weight = matrix[tempEdge.start][i];
				return tempEdge;
			}
		}
		Edge<EdgeType> nullEdge(-1, -1, 0);
		return nullEdge;
	}
	void setEdge(int st, int en, int w)
	{
		if (st >= vertexNum || en >= vertexNum || st < 0 || en < 0)
		{
			cout << "���ñ�����Խ�磡\n";
			return;
		}
		if (matrix[st][en] == 0)
		{
			edgeNum++;
			matrix[st][en] = w;
		}
		else
		{
			cout << "����ʧ�ܣ�";
			cout << "(" << st << "," << en << ")" << "֮�����бߣ�\n";
		}
	}
	void delEdge(int st, int en)
	{
		if (st >= vertexNum || en >= vertexNum || st < 0 || en < 0)
			cout << "ɾ������Խ�磡\n";
		if (matrix[st][en] != 0)
		{
			edgeNum--;
			matrix[st][en] = 0;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�";
			cout << "(" << st << "," << en << ")" << "֮��û�бߣ�\n";
		}
	}

	void DisplayGraph()
	{
		cout << "   ";
		for (int i = 0; i < vertexNum; i++)  //����б�
			cout << i << "  ";
		cout << endl;

		for (int i = 0; i < vertexNum; i++)
		{
			cout << i << "  ";    //������

			for (int j = 0; j < vertexNum; j++)
				cout << matrix[i][j] << "  ";
			cout << endl;
		}
	}

	void Visit(int vertex)
	{
		cout << vertex << "  ";
		order[count] = vertex;
	}

	void DFS(int v)
	{
		flag[v] = 1;
		Visit(v);
		count++;
		for (Edge<EdgeType> e = FirstEdge(v); IsEdge(e); e = NextEdge(e))
			if (flag[e.end] == 0)
				DFS(e.end);
	}
	void DFSTraverse()
	{
		//��ʼ����־λ
		for (int i = 0; i < vertexNum; i++)
			flag[i] = 0;

		for (int i = 0; i < vertexNum; i++)
			if (flag[i] == 0)
				DFS(i);
	}
	void BFSTraverse()
	{
		using std::queue;
		queue<int> vertexQueue;
		//��ʼ����־λ
		for (int i = 0; i < vertexNum; i++)
			flag[i] = 0;

		for (int i = 0; i < vertexNum; i++)
		{
			if (flag[i] == 0)
			{
				vertexQueue.push(i);
				flag[i] = 1;   //ֻҪѹ������о���Ϊ�Ѿ�����
			}
			while (!vertexQueue.empty())
			{
				int temp = vertexQueue.front();
				Visit(temp);
				vertexQueue.pop();

				for (int j = 0; j < vertexNum; j++)
					if (matrix[temp][j] != 0 && flag[j] == 0)
					{
						vertexQueue.push(j);
						flag[j] = 1;	//ֻҪѹ��ջ�о���Ϊ�Ѿ�����
					}
			}
		}
	}

	int Prim()
	{
		int i, j;
		int sum = 0;

		int* lowCost = new int[vertexNum];
		int* neighbor = new int[vertexNum];

		for (i = 0; i < vertexNum; i++)
			for (j = 0; j < vertexNum; j++)
				if (matrix[i][j] == 0)
					matrix[i][j] = INT32_MAX;

		for (i = 1; i < vertexNum; i++)
		{
			lowCost[i] = matrix[0][i];
			neighbor[i] = 0;
		}
		neighbor[0] = -1;

		for (i = 1; i < vertexNum; i++)
		{
			int min = INT32_MAX;
			int v = -1;
			for (j = 1; j < vertexNum; j++)
			{
				if (lowCost[j] < min&&lowCost[j] != -1 && neighbor[j] != -1)
				{
					min = lowCost[j];
					v = j;
				}
			}
			cout << neighbor[v] << "->" << v << "=" << min << endl;
			sum += min;
			lowCost[v] = -1;
			for (j = 1; j < vertexNum; j++)
			{
				if (matrix[v][j] < lowCost[j])
				{
					lowCost[j] = matrix[v][j];
					neighbor[j] = v;
				}
			}
		}
		return sum;
	}
	void Kruskal()
	{
		int n = vertexNum;
		UFSets set(n);
		MinHeap<Edge<EdgeType>> H;
		for (int i = 0; i < n; i++)
			for (Edge<EdgeType> edge = FirstEdge(i); IsEdge(edge); edge = NextEdge(edge))
				if (edge.start < edge.end)
					H.Insert(edge);
		int e_num = 0;
		Edge<EdgeType> temp;
		while (e_num < n - 1)
		{
			if (!H.Empty())
			{
				temp = H.GetTop();
				H.DeleteTop();
				int v = temp.start;
				int u = temp.end;
				if (set.Find(v) != set.Find(u))  //����Ԫ��ͬ������ͨ
				{
					set.Union(v, u);
					e_num++;
					cout << v << "->" << u << "=" << temp.weight << endl;
				}
			}
			else
				cout << "��������С������ͼ��\n";
		}
	}
	bool operator<(Edge<EdgeType> & e)
	{
		if (e.weight < weight)
			return false;
		return true;
	}
	bool operator>(Edge<EdgeType> & e)
	{
		if (e.weight > weight)
			return false;
		return true;
	}

	void Dijkstra(int s, int* path, int* dis)
	{
		int n = vertexNum;
		int i, j, k;

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (matrix[i][j] == 0)
					matrix[i][j] = INT32_MAX;

		int* flag = new int[n];
		for (i = 0; i < n; i++)  //��־λΪ0��Ҫ���ǣ�Ϊ1����Ҫ����
			flag[i] = 0;
		flag[s] = 1;

		for (i = 0; i < n; i++)
		{
			dis[i] = matrix[s][i];
			path[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			int min = INT32_MAX;
			for (j = 0; j < n; j++)     //�ҵ����·��
				if (flag[j] == 0 && dis[j] < min)
				{
					min = dis[j];
					k = j;
				}
			flag[k] = 1;
			for (int m = 0; m < n; m++)
				if (matrix[k][m] != INT32_MAX&&min != INT32_MAX&&flag[m] == 0 && dis[m] > (matrix[k][m] + min))
				{
					dis[m] = matrix[k][m] + min;
					path[m] = k;
				}
		}
	}
	void Floyd(int** adj, int** path)
	{
		int n = vertexNum;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] == 0)
					matrix[i][j] = INT32_MAX;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				path[i][j] = i;
				adj[i][j] = matrix[i][j];
			}

		for (int v = 0; v < n; v++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (adj[i][v] != INT32_MAX&& adj[v][j] != INT32_MAX &&adj[i][j] > (adj[i][v] + adj[v][j]))  //�������
					{
						adj[i][j] = adj[i][v] + adj[v][j];
						path[i][j] = v;
					}
	}

	bool FindCircle()  //Ѱ��ͼ���Ƿ���ڻ�·
	{
		//int n = vertexNum;
		//DFSTraverse();
		////system("cls");
		//for (int i = 0; i < n; i++)
		//{
		//	for (Edge<EdgeType> e = FirstEdge(order[i]); IsEdge(e); e = NextEdge(e))
		//	{
		//		for (int j = 0; j < i; j++)
		//		{
		//			if (e.end == order[j])
		//			{
		//				for (int k = j; k <= i && j <= i; k++)
		//				{
		//					if (IsEdge())
		//						cout << order[k] << " ";
		//					else
		//						j++;
		//				}
		//				return true;
		//			}
		//		}
		//	}
		//}
		//cout << "�����ڻ�·��\n";
		//return false;

		int n = vertexNum;
		int k;
		for (int i = 0; i < n; i++)
		{
			count = 0;
			DFS(i);
			for (int j = 0; j < n; j++)
				flag[j] = 0;
			for (k = 0; k < n; k++)
				if (order[k] == -1)
					break;
			if (matrix[order[k - 1]][i] != 0)
			{
				int m = 0;
				while (order[m] != -1)
				{
					cout << order[m] << " ";
					m++;
				}
				return true;
			}
			for (int i = 0; i < n; i++)
				order[i] = -1;
		}
		return false;
	}
};