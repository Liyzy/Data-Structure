#pragma once
#include<iostream>
#include <string>
#include <stack>
#include <queue>
#include "ColorList.h"
using namespace std;

class HuffmanNode
{
private:
	colorCode mycode;
	HuffmanNode* lchild;
	HuffmanNode* rchild;
public:
	HuffmanNode(HuffmanNode* lc = NULL, HuffmanNode* rc = NULL)
	{
		lchild = lc;
		rchild = rc;
	}
	HuffmanNode(char* sc, float dw, HuffmanNode* lc = NULL, HuffmanNode* rc = NULL)
	{
		mycode.code = sc;
		mycode.wight = dw;
		lchild = lc;
		rchild = rc;
	}
	HuffmanNode(HuffmanNode & h)
	{
		mycode.code = h.mycode.code;
		mycode.wight = h.mycode.wight;
		lchild = h.lchild;
		rchild = h.rchild;
	}

	char* getCode() const
	{
		return mycode.code;
	}
	float getWight() const
	{
		return mycode.wight;
	}
	HuffmanNode* getlchild() const
	{
		return lchild;
	}
	HuffmanNode* getrchild() const
	{
		return rchild;
	}

	void setCode(const char* s)
	{
		for (int i = 0; i < 8; i++)
			mycode.code[i] = s[i];
	}
	void setWight(const float w)
	{
		mycode.wight = w;
	}
	void setlchild(HuffmanNode* l)
	{
		lchild = l;
	}
	void setrchild(HuffmanNode* r)
	{
		rchild = r;
	}

	bool Left()  //叶子节点返回1，否则返回0
	{
		if (lchild == NULL&&rchild == NULL)
			return true;
		return false;
	}

	bool operator<(HuffmanNode & h)
	{
		if (mycode.wight < h.mycode.wight)
			return true;
		return false;
	}
	bool operator>(HuffmanNode & h)
	{
		if (mycode.wight > h.mycode.wight)
			return true;
		return false;
	}
};
//最小堆定义
template<class T>
class MinHeap
{
	friend class HuffmanNode;
private:
	T* heapArray;  //数据数组
	int MaxSize;  //最大容量
	int CurrentSize;   //当前元素个数
public:
	MinHeap(int cur = 0, int size = 1500) //此处的size应大于像素点size
	{
		heapArray = new T[size];
		MaxSize = size;
		CurrentSize = cur;
	}

	void intialize(T* arr, int size)
	{
		CurrentSize = size;
		for (int m = 0; m < CurrentSize; m++)
			heapArray[m] = arr[m];

		int start = CurrentSize / 2 - 1;

		for (; start >= 0; start--)
			shiftDown(start);
	}

	void display() const
	{
		for (int i = 0; i < CurrentSize; i++)
			std::cout << heapArray[i] << "\t";
		std::cout << std::endl;
	}

	bool Insert(const T& value)
	{
		if (CurrentSize + 1 > MaxSize)
			return false;

		heapArray[CurrentSize] = value;
		int i = CurrentSize;
		CurrentSize += 1;
		if (i != 1)
			shiftUp(i);
		return true;
	}

	HuffmanNode* DeleteTop(int number = 0)//默认删除0号节点，即根节点
	{
		if (number > CurrentSize)
			return NULL;

		HuffmanNode* top = new HuffmanNode;
		*top = heapArray[number];
		heapArray[number] = heapArray[CurrentSize - 1];
		CurrentSize -= 1;
		shiftDown(number);
		return top;
	}

	void shiftDown(int start)
	{
		int i = start;   //开始的下标
		int j = 2 * i + 1;
		T temp = heapArray[i];

		while (j < CurrentSize)
		{
			if (j + 1 < CurrentSize&&heapArray[j] > heapArray[j + 1]) //有右孩子且右孩子大于左孩子
				j++;   //j改为右孩子下标
			if (temp > heapArray[j])
			{
				heapArray[i] = heapArray[j];
				heapArray[j] = temp;
				i = j;
				j = 2 * i + 1;
			}
			else
				break;
		}
	}

	void shiftUp(int i)
	{
		while (i >= 0) //不是根节点就向上转移
		{
			if (heapArray[i] < heapArray[(i - 1) / 2])
			{
				heapArray[i] = heapArray[(i - 1) / 2];
				heapArray[(i - 1) / 2] = heapArray[CurrentSize];
				i = (i - 1) / 2;
			}
			else
				break;
		}
	}
};

class HuffmanTree
{
	friend class HuffmanNode;
private:
	HuffmanNode* root;
public:
	HuffmanTree(colorCode* colorlist, int type)
	{
		//将colorCode结构体转变为HuffmanNode
		HuffmanNode* colorlistNode = new HuffmanNode[type];
		for (int i = 0; i < type; i++)
		{
			colorlistNode[i].setCode(colorlist[i].code);
			colorlistNode[i].setWight(colorlist[i].wight);
		}
		//最小堆初始化
		MinHeap<HuffmanNode> heap;
		heap.intialize(colorlistNode, type);

		HuffmanNode* parent, *firstChild, *secondChild;
		int difBit = 2;

		//建立Huffman树
		for (int i = 0; i < type - 1; i++)
		{
			parent = new HuffmanNode;
			firstChild = new HuffmanNode;
			secondChild = new HuffmanNode;

			firstChild = heap.DeleteTop(); //取最小权重
			secondChild = heap.DeleteTop();  // 取次小权重
			//合并两个节点，将父节点插入堆中
			parent->setlchild(firstChild);
			parent->setrchild(secondChild);
			parent->setCode(to_string(difBit).data());
			parent->setWight(firstChild->getWight() + secondChild->getWight());
			heap.Insert(*parent);  //死在*parent。。。

			root = parent;
			difBit++;
		}
	}

	HuffmanNode* Getroot()
	{
		return root;
	}

	colorCode* keycolorlist(int type)
	{
		queue<HuffmanNode*> myQueue;
		HuffmanNode* pointer = root;
		colorCode* keylist = new colorCode[type];

		if (root == NULL)
			return NULL;
		myQueue.push(root);
		for (int i = 0; i < type; i++)
		{
			while (!myQueue.empty())
			{
				pointer = myQueue.front();
				myQueue.pop();
				if (pointer->Left())
				{
					for (int j = 0; j < 8; j++)
						keylist[i].code[j] = pointer->getCode()[j];
					keylist[i].wight = pointer->getWight();
					keylist[i].key = decode(pointer);
					break;
				}

				if (pointer->getlchild())
					myQueue.push(pointer->getlchild());
				if (pointer->getrchild())
					myQueue.push(pointer->getrchild());
			}
		}
/*		for (int i = 0; i < type; i++)
			cout << keylist[i].code << " " << keylist[i].key << " \t" << keylist[i].wight << endl;
*/
		return keylist;
	}

	string decode(HuffmanNode* child)
	{
		stack<int> KeyStack;
		string Key = "";
		HuffmanNode* parent = findParent(child->getCode());
		while (parent != NULL)
		{
			HuffmanNode* temp = parent;
			parent = findParent(temp->getCode());

			if (temp->getlchild() == child)
				KeyStack.push(0);
			if (temp->getrchild() == child)
				KeyStack.push(1);
			child = temp;
		}
		while (!KeyStack.empty())
		{
			Key += to_string(KeyStack.top());
			KeyStack.pop();
		}
		return Key;
	}

	HuffmanNode* findParent(const char* s)
	{
		queue<HuffmanNode*> myQueue;
		HuffmanNode* pointer = root;

		if (root == NULL)
			return NULL;
		myQueue.push(root);
		while (!myQueue.empty())
		{
			pointer = myQueue.front();
			myQueue.pop();
			if (pointer->getlchild() && pointer->getlchild()->getCode() == s)
				return pointer;
			if (pointer->getrchild() && pointer->getrchild()->getCode() == s)
				return pointer;

			if (pointer->getlchild())
				myQueue.push(pointer->getlchild());
			if (pointer->getrchild())
				myQueue.push(pointer->getrchild());
		}
		return NULL;
	}
};


