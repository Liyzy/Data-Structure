#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int num,X;
	cout << "������Ҫת�������֣�";
	cin >> num;
	cout << "������Ҫת��Ϊ�Ľ��ƣ�";
	cin >> X;
	void Exchange(int num, int X);
	Exchange(num, X);
	system("pause");
}

void Exchange(int num,int X)
{
	stack<int> result;
	while (num > X)
	{
		result.push(num%X);
		num = num / X;
	}
	result.push(num);
	while (! result.empty())
	{
		int temp;
		temp = result.top();
		cout << temp;
		result.pop();
	}
}