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
	int vertexNum;  //顶点数
	int edgeNum;   //边数
	bool* flag;   //是否被访问过的标志

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

	Edge<EdgeType> FirstEdge(int oneVertex) //返回顶点的第一条边
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
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)  //返回有相同起点的下一条边
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
			cout << "设置边输入越界！\n";
			return;
		}
		if (matrix[st][en] == 0)
		{
			edgeNum++;
			matrix[st][en] = w;
		}
		else
		{
			cout << "设置失败！";
			cout << "(" << st << "," << en << ")" << "之间已有边！\n";
		}
	}
	void delEdge(int st, int en)
	{
		if (st >= vertexNum || en >= vertexNum || st < 0 || en < 0)
			cout << "删除输入越界！\n";
		if (matrix[st][en] != 0)
		{
			edgeNum--;
			matrix[st][en] = 0;
		}
		else
		{
			cout << "删除失败！";
			cout << "(" << st << "," << en << ")" << "之间没有边！\n";
		}
	}

	void DisplayGraph()
	{
		cout << "   ";
		for (int i = 0; i < vertexNum; i++)  //输出列标
			cout << i << "  ";
		cout << endl;

		for (int i = 0; i < vertexNum; i++)
		{
			cout << i << "  ";    //输出横标

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
		//初始化标志位
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
		//初始化标志位
		for (int i = 0; i < vertexNum; i++)
			flag[i] = 0;

		for (int i = 0; i < vertexNum; i++)
		{
			if (flag[i] == 0)
			{
				vertexQueue.push(i);
				flag[i] = 1;   //只要压入队列中就视为已经访问
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
						flag[j] = 1;	//只要压入栈中就视为已经访问
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
				if (set.Find(v) != set.Find(u))  //代表元不同，不连通
				{
					set.Union(v, u);
					e_num++;
					cout << v << "->" << u << "=" << temp.weight << endl;
				}
			}
			else
				cout << "不存在最小生成子图！\n";
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
		for (i = 0; i < n; i++)  //标志位为0需要考虑，为1不需要考虑
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
			for (j = 0; j < n; j++)     //找到最短路径
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
					if (adj[i][v] != INT32_MAX&& adj[v][j] != INT32_MAX &&adj[i][j] > (adj[i][v] + adj[v][j]))  //溢出问题
					{
						adj[i][j] = adj[i][v] + adj[v][j];
						path[i][j] = v;
					}
	}

	bool FindCircle()  //寻找图中是否存在回路
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
		//cout << "不存在回路！\n";
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