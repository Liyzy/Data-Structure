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
	myTree.FindPrint("��¥");
	myTree.FindParentPrint("�������");
    myTree.count("����", "���"); 
	
	system("pause");
}