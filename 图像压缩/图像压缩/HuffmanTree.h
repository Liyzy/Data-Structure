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

	bool Left()  //Ҷ�ӽڵ㷵��1�����򷵻�0
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
//��С�Ѷ���
template<class T>
class MinHeap
{
	friend class HuffmanNode;
private:
	T* heapArray;  //��������
	int MaxSize;  //�������
	int CurrentSize;   //��ǰԪ�ظ���
public:
	MinHeap(int cur = 0, int size = 1500) //�˴���sizeӦ�������ص�size
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

	HuffmanNode* DeleteTop(int number = 0)//Ĭ��ɾ��0�Žڵ㣬�����ڵ�
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
		int i = start;   //��ʼ���±�
		int j = 2 * i + 1;
		T temp = heapArray[i];

		while (j < CurrentSize)
		{
			if (j + 1 < CurrentSize&&heapArray[j] > heapArray[j + 1]) //���Һ������Һ��Ӵ�������
				j++;   //j��Ϊ�Һ����±�
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
		while (i >= 0) //���Ǹ��ڵ������ת��
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
		//��colorCode�ṹ��ת��ΪHuffmanNode
		HuffmanNode* colorlistNode = new HuffmanNode[type];
		for (int i = 0; i < type; i++)
		{
			colorlistNode[i].setCode(colorlist[i].code);
			colorlistNode[i].setWight(colorlist[i].wight);
		}
		//��С�ѳ�ʼ��
		MinHeap<HuffmanNode> heap;
		heap.intialize(colorlistNode, type);

		HuffmanNode* parent, *firstChild, *secondChild;
		int difBit = 2;

		//����Huffman��
		for (int i = 0; i < type - 1; i++)
		{
			parent = new HuffmanNode;
			firstChild = new HuffmanNode;
			secondChild = new HuffmanNode;

			firstChild = heap.DeleteTop(); //ȡ��СȨ��
			secondChild = heap.DeleteTop();  // ȡ��СȨ��
			//�ϲ������ڵ㣬�����ڵ�������
			parent->setlchild(firstChild);
			parent->setrchild(secondChild);
			parent->setCode(to_string(difBit).data());
			parent->setWight(firstChild->getWight() + secondChild->getWight());
			heap.Insert(*parent);  //����*parent������

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


