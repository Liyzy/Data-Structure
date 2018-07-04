#include<iostream>
#include"BinarySearchTree.h"

int main()
{
	using namespace std;
	BinarySearchTree<int> myTree;
	
	int i = 0;
	int data[] = { 400,122,450,250,99,500,110,200,300,105,330,0 };
	while (data[i])
	{
		myTree.Insert(data[i]);
		i++;
	}
	
	if(myTree.Search(110))
		cout << "²éÕÒ³É¹¦£¡\n";
	else
		cout << "²éÕÒÊ§°Ü£¡\n";

	if( myTree.Delete(122) )
		cout << "ÒÑÉ¾³ý£¡\n";
	else
		cout << "É¾³ýÊ§°Ü£¡\n";

	system("pause");
}