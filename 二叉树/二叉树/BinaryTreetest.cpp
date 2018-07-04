#include<iostream>
#include"BinaryTree.h"

int main()
{
	using namespace std;

	BinaryTree<char> myBinaryTree;
	myBinaryTree.creatBinaryTree();
	BinaryTreeNode<char>* Root = myBinaryTree.getRoot();

	//�������ȱ���
	cout << "������ȱ�����";
	myBinaryTree.breadthFirstOrder(Root);
	cout << endl;

	//�������
	cout << "ǰ����������";
	myBinaryTree.preOrder(Root);
	cout << endl;

	//�������
	cout << "������������";
	myBinaryTree.inOrder(Root);
	cout << endl;

	//�������
	cout << "������������";
	myBinaryTree.postOrder(Root);
	cout << endl;

	//�����ܽ����
	cout << "�����ܽ����Ϊ��" 
		<< myBinaryTree.count_of_jiedian(Root)<<endl;

	//ͳ�Ʋ�ͬ�ȵĽڵ����
	cout << "��Ϊ��Ľ����Ϊ��"
		<< myBinaryTree.count_of_degree0(Root) << endl;
	cout << "��Ϊһ�Ľ����Ϊ��"
		<< myBinaryTree.count_of_degree1(Root) << endl;
	cout << "��Ϊ���Ľ����Ϊ��"
		<< myBinaryTree.count_of_degree2(Root) << endl;
	//���ĸ߶�
	cout<<"���ĸ߶�Ϊ��"<< myBinaryTree.height_of_tree(Root) << endl;

	//���������
	cout << "���������Ϊ��" << myBinaryTree.maxWidth_of_tree(Root) << endl;

	//�������ڵ�Ԫ��ֵ
	cout << "�����Ԫ��Ϊ��"
		<< myBinaryTree.maxData(Root) << endl;
	//����ÿ���ڵ�����Һ���
	myBinaryTree.changeChild(Root);
	cout << "�������Ӻ������ȱ�����";
	myBinaryTree.breadthFirstOrder(Root);
	cout << endl;
	cout << "�������Ӻ�ǰ����������";
	myBinaryTree.preOrder(Root);
	cout << endl;
	cout << "�������Ӻ�������������";
	myBinaryTree.inOrder(Root);
	cout << endl;
	cout << "�������Ӻ������������";
	myBinaryTree.postOrder(Root);
	cout << endl;

	//ɾ��Ҷ�ӽڵ�
	myBinaryTree.changeChild(Root);
	myBinaryTree.deleteLeaf();
	cout << "ɾ��Ҷ�Ӻ������ȱ�����";
	myBinaryTree.breadthFirstOrder(Root);
	cout << endl;

	//�ж��Ƿ�Ϊ��ȫ������
	if (myBinaryTree.isComplete())
		cout << "����ȫ��������\n";
	if (!myBinaryTree.isComplete())
		cout << "������ȫ��������\n";

	//����������������
	BinaryTree<char> pre_in_tree;
	char pre[8] = { 'a','b','d','f','g','c','e','h' };
	char in[8] =  { 'b','f','d','g','a','c','e','h' };
	BinaryTreeNode<char>* Root1 = pre_in_tree.pre_in_create(pre, in, 8);
	cout << "���������������������";
	pre_in_tree.postOrder(Root1);
	cout << endl;

	//����������������
	BinaryTree<char> post_in_tree;
	char post[8] = { 'f','g','d','b','h','e','c','a' };
	BinaryTreeNode<char>* Root2 = post_in_tree.in_post_create(post, in, 8, 8);
	cout << "����������ǰ����������";
	post_in_tree.preOrder(Root2);
	cout << endl;

	system("pause");
}