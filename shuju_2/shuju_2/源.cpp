#include<iostream>
using namespace std;
template <class T>
class ArrayList
{
public:
	ArrayList(const int size)
	{
		maxSize = size;
		arrayList = new T[maxSize];
		position = 0;
		curLen = 0;
	}
	ArrayList()
	{
		delete[]arrayList;
	}
	void Append(const T value);//表尾添加元素，表长加一
	T Delete();
	void Delete(const T x);
	void sort();
	bool Delete(const T s, const T t);
	void Display();

private:
	T* arrayList;
	int position;
	int curLen;
	int maxSize;
};
template<class T>
void ArrayList<T>::Append(const T value)
{
	arrayList[position] = value;
	position++;
	curLen++;
	if (curLen > maxSize)
		cout << "顺序表已满！\n";
}
template<class T>
T ArrayList<T>::Delete()
{
	int i, min = 0;
	for (i = 1; i < curLen; i++)
		if (arrayList[i] <= arrayList[min])
		{
			min = i;
		}
	T temp = arrayList[min];
	if (arrayList[maxSize - 1] != temp)
	{
		arrayList[min] = arrayList[maxSize - 1];
		for (i = 0; i < curLen; i++)
			if (arrayList[i] == temp)
				arrayList[i] = arrayList[maxSize - 1];
	}
	else
	{
		for (i = curLen-1; i >= 0; i--)
		{
			if (arrayList[i] != temp)
			{
				arrayList[min] = arrayList[i];
				for (position = 0; position < curLen; position++)
					if (arrayList[position] == temp)
						arrayList[position] = arrayList[i];
				break;
			}
		}
	}
	curLen -= 1;
	return temp;
}
template<class T>
void ArrayList<T>::Delete(const T x)
{
	if (curLen <= 0)
	{
		cout << "顺序表为空！\n";
	}
	for (position = 0; position < curLen; position++)
	{
		if (arrayList[position] == x)
		{
			int temp = position;//记录处理到的当前位置
			for (position; position < curLen; position++)
				arrayList[position] = arrayList[position + 1];
			position = temp-1;
			curLen -= 1;
		}
	}
}
template<class T>
void ArrayList<T>::sort() //选择排序
{
	for (int i = 1; i < curLen; i++)
	{
		int k = i - 1;//待排序列的第一个元素
		for (int j = i; j < curLen; j++)
			if (arrayList[j] < arrayList[k])
				k = j;
		if (k != i - 1)
		{
			T t = arrayList[k];
			arrayList[k] = arrayList[i - 1];
			arrayList[i - 1] = t;
		}
	}
}
template<class T>
bool ArrayList<T>::Delete(const T s, const T t)
{
	if (t<arrayList[0] || s>arrayList[curLen])
	{
		cout << "无效输入！";
		return false;
	}
	if (s <= arrayList[0] && t >= arrayList[curLen])
	{
		cout << "删干净了！";
		return false;
	}
	else
	{
		int counter = 0;
		for (position = 0; position < curLen; position++)
		{
			if (arrayList[position] >= s)
			{
				int temp_p = position;
				while (arrayList[position] <= t)
				{
					position++;
					counter++;
				}
				for (position; position < curLen; position++)
				{
					arrayList[temp_p] = arrayList[position];
					temp_p++;
				}
			}
		}
		curLen -= counter;
		return true;
	}
}
template<class T>
void ArrayList<T>::Display()
{
	for (position = 0; position < curLen; position++)
		cout << arrayList[position] << " ";
}
int main()
{
	int m_size;
	cout << "请输入你要输入的元素个数：";
	cin >> m_size;
	ArrayList<int> arr(m_size);
	int m_value;
	cout << "输入元素：";
	for (int i = 0; i < m_size; i++)
	{
		cin >> m_value;
		arr.Append(m_value);
	}

	int min = arr.Delete();
	cout << "最小元素为：" << min << endl;
	cout << "删除最小元素后为：";
	arr.Display();
	cout << endl;

	cout << "请输入要删除的数字：";
	int m_d;
	cin >> m_d;
	arr.Delete(m_d);
	cout << "删除后为：";
	arr.Display();
	cout << endl;

	arr.sort();
	int m_s, m_t;
	cout << "请输入要删除的范围：";
	cin >> m_s >> m_t;
	if (arr.Delete(m_s, m_t))
	{
		cout << "删除后为：";
		arr.Display();
	}
	cout << endl;
	system("pause");
}