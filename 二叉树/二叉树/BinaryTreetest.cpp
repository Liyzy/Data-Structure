#include<iostream>
#include"BinaryTree.h"

int main()
{
	using namespace std;

	BinaryTree<char> myBinaryTree;
	myBinaryTree.creatBinaryTree();
	BinaryTreeNode<char>* Root = myBinaryTree.getRoot();

	//广序优先遍历
	cout << "广度优先遍历：";
	myBinaryTree.breadthFirstOrder(Root);
	cout << endl;

	//先序遍历
	cout << "前序遍历结果：";
	myBinaryTree.preOrder(Root);
	cout << endl;

	//中序遍历
	cout << "中序遍历结果：";
	myBinaryTree.inOrder(Root);
	cout << endl;

	//后序遍历
	cout << "后序遍历结果：";
	myBinaryTree.postOrder(Root);
	cout << endl;

	//树的总结点数
	cout << "树的总结点数为：" 
		<< myBinaryTree.count_of_jiedian(Root)<<endl;

	//统计不同度的节点个数
	cout << "度为零的结点数为："
		<< myBinaryTree.count_of_degree0(Root) << endl;
	cout << "度为一的结点数为："
		<< myBinaryTree.count_of_degree1(Root) << endl;
	cout << "度为二的结点数为："
		<< myBinaryTree.count_of_degree2(Root) << endl;
	//树的高度
	cout<<"树的高度为："<< myBinaryTree.height_of_tree(Root) << endl;

	//树的最大宽度
	cout << "树的最大宽度为：" << myBinaryTree.maxWidth_of_tree(Root) << endl;

	//树的最大节点元素值
	cout << "最大结点元素为："
		<< myBinaryTree.maxData(Root) << endl;
	//交换每个节点的左右孩子
	myBinaryTree.changeChild(Root);
	cout << "交换孩子后广度优先遍历：";
	myBinaryTree.breadthFirstOrder(Root);
	cout << endl;
	cout << "交换孩子后前序遍历结果：";
	myBinaryTree.preOrder(Root);
	cout << endl;
	cout << "交换孩子后中序遍历结果：";
	myBinaryTree.inOrder(Root);
	cout << endl;
	cout << "交换孩子后后序遍历结果：";
	myBinaryTree.postOrder(Root);
	cout << endl;

	//删除叶子节点
	myBinaryTree.changeChild(Root);
	myBinaryTree.deleteLeaf();
	cout << "删除叶子后广度优先遍历：";
	myBinaryTree.breadthFirstOrder(Root);
	cout << endl;

	//判断是否为完全二叉树
	if (myBinaryTree.isComplete())
		cout << "是完全二叉树！\n";
	if (!myBinaryTree.isComplete())
		cout << "不是完全二叉树！\n";

	//先序中序建立二叉树
	BinaryTree<char> pre_in_tree;
	char pre[8] = { 'a','b','d','f','g','c','e','h' };
	char in[8] =  { 'b','f','d','g','a','c','e','h' };
	BinaryTreeNode<char>* Root1 = pre_in_tree.pre_in_create(pre, in, 8);
	cout << "先序中序构造后序遍历结果：";
	pre_in_tree.postOrder(Root1);
	cout << endl;

	//后序中序建立二叉树
	BinaryTree<char> post_in_tree;
	char post[8] = { 'f','g','d','b','h','e','c','a' };
	BinaryTreeNode<char>* Root2 = post_in_tree.in_post_create(post, in, 8, 8);
	cout << "后序中序构造前序遍历结果：";
	post_in_tree.preOrder(Root2);
	cout << endl;

	system("pause");
}