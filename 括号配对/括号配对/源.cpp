#include<iostream>
#include <stack>
using namespace std;
int main()
{
	stack<char> test;
	bool flag = 0;
	int counter = 0;
	char c;
	char str[100] = {0};
	cout << "ÇëÊäÈë×Ö·û´®£¬°´#½áÊø\n";
	while (cin >> c && c != '#')
	{
		str[counter] = c;
		counter++;
	}
	for (counter = 0; str[counter] != '#'; counter++)
	{
		if (str[counter] == '{' || str[counter] == '[' || str[counter] == '(')
		{
			test.push(str[counter]);
		}
		if ((str[counter] == '}' || str[counter] == ']' || str[counter] == ')') && !test.empty())
		{
			char tempc;
			tempc = test.top();
			if (str[counter] == tempc)
				test.pop();
			else
			{
				flag = 1;
				cout << "À¨ºÅ²»Æ¥Åä£¡";
				break;
			}
		}
	}
	if (!flag)
		cout << "À¨ºÅ¾ùÆ¥Åä¡£";
	system("pause");
}