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
		cout << "���ҳɹ���\n";
	else
		cout << "����ʧ�ܣ�\n";

	if( myTree.Delete(122) )
		cout << "��ɾ����\n";
	else
		cout << "ɾ��ʧ�ܣ�\n";

	system("pause");
}