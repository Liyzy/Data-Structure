#include<iostream>
#include <string>
using namespace std;

bool Strcmp(string str1, string str2)
{
	bool flag = true;
	if (str1.length() != str2.length())
	{
		cout << "字符串不相同，长度不等！\n";
		return false;
	}
	else
	{
		for (int i = 0; i < str1.length(); i++)
		{
			if (str1[i] == str2[i])
				continue;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "字符串不相同，长度相同，内容不同！\n";
			return false;
		}
		else
		{
			cout << "字符串相同！\n";
			return true;
		}
	}
}
int main()
{
	string s, t;
	cout << "请输入字符串s: ";
	cin >> s;
	cout << "请输入字符串t: ";
	cin >> t;
	Strcmp(s, t);
	system("pause");
}