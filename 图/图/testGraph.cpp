#include <iostream>
#include "AdjGraph.h"

int main()
{
	using namespace std;

	AdjGraph<int> myGraph(6);

	myGraph.setEdge(0, 1, 6);   //Prim及Kruskal算法用图
	myGraph.setEdge(1, 0, 6);
	myGraph.setEdge(0, 2, 1);
	myGraph.setEdge(2, 0, 1);
	myGraph.setEdge(0, 3, 5);
	myGraph.setEdge(3, 0, 5);
	myGraph.setEdge(1, 4, 3);
	myGraph.setEdge(4, 1, 3);
	myGraph.setEdge(4, 2, 6);
	myGraph.setEdge(2, 4, 6);
	myGraph.setEdge(4, 5, 6);
	myGraph.setEdge(5, 4, 6);
	myGraph.setEdge(5, 2, 4);
	myGraph.setEdge(2, 5, 4);
	myGraph.setEdge(3, 5, 2);
	myGraph.setEdge(5, 3, 2);
	myGraph.setEdge(2, 3, 5);
	myGraph.setEdge(3, 2, 5);
	myGraph.setEdge(2, 1, 5);
	myGraph.setEdge(1, 2, 5);

	myGraph.DisplayGraph();

	cout << "DFS:";
	myGraph.DFSTraverse();
	cout << endl << "BFS:";
	myGraph.BFSTraverse();
	cout << endl;

	cout <<"最短路径权重和："<< myGraph.Prim();

//	myGraph.Kruskal();    //Kruskal算法测试

	//myGraph.setEdge(0, 1, 12); //Floyd算法测试及Dijkstra算法测试
	//myGraph.setEdge(0, 2, 10);
	//myGraph.setEdge(0, 4, 30);
	//myGraph.setEdge(0, 5, 100);
	//myGraph.setEdge(1, 2, 5);
	//myGraph.setEdge(2, 3, 50);
	//myGraph.setEdge(3, 5, 10);
	//myGraph.setEdge(4, 3, 20);
	//myGraph.setEdge(4, 5, 60);

	//int** adj=new int* [6];  
	//for (int i = 0; i < 6; i++)
	//	adj[i] = new int[6];
	//int** path = new int*[6];
	//for (int i = 0; i < 6; i++)
	//	path[i] = new int[6];
	//myGraph.Floyd(adj, path);
	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 0; j < 6; j++)
	//	{
	//		if (adj[i][j] != INT32_MAX)
	//			cout << adj[i][j] << "\t";
	//		else
	//			cout << "0\t";
	//	}
	//	cout << endl;
	//}
	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 0; j < 6; j++)
	//		cout << path[i][j] << "  ";
	//	cout << endl;
	//}

	//int* Path = new int[6];
	//int* dis = new int[6];
	//myGraph.Dijkstra(0, Path, dis);
	//cout << "Path:";
	//for (int i = 1; i < 6; i++)
	//	cout << Path[i] << " ";
	//cout << endl;
	//cout << "Distance:";
	//for (int i = 1; i < 6; i++)
	//	cout << dis[i] << " ";
	//cout << endl;

	//myGraph.setEdge(0, 1, 12); //寻找回路测试图
	//myGraph.setEdge(0, 2, 10);
	//myGraph.setEdge(0, 4, 30);
	//myGraph.setEdge(0, 5, 100);
	//myGraph.setEdge(1, 2, 5);
	//myGraph.setEdge(2, 3, 50);
	//myGraph.setEdge(3, 5, 10);
	//myGraph.setEdge(4, 3, 20);
	//myGraph.setEdge(4, 5, 60);
	//myGraph.setEdge(5, 2, 90);
	//if (myGraph.FindCircle())
	//	cout << "存在回路！\n";
	//else
	//	cout<< "不存在回路！\n";

	system("pause");
}