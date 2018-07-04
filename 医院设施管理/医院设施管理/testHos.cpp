#include<iostream>
#include "Hos_Structure.h"

int main()
{
	using namespace std;

	Tree myTree;

	myTree.Create();
	//myTree.levelOrder();
	//myTree.preOrder(myTree.getRoot());
	//myTree.inOrder(myTree.getRoot());
	myTree.FindPrint("配楼");
	myTree.FindParentPrint("中央大厅");
    myTree.count("病床", "面板"); 
	
	system("pause");
}