#include<iostream>
#include <string>
using namespace std;

bool Strcmp(string str1, string str2)
{
	bool flag = true;
	if (str1.length() != str2.length())
	{
		cout << "�ַ�������ͬ�����Ȳ��ȣ�\n";
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
			cout << "�ַ�������ͬ��������ͬ�����ݲ�ͬ��\n";
			return false;
		}
		else
		{
			cout << "�ַ�����ͬ��\n";
			return true;
		}
	}
}
int main()
{
	string s, t;
	cout << "�������ַ���s: ";
	cin >> s;
	cout << "�������ַ���t: ";
	cin >> t;
	Strcmp(s, t);
	system("pause");
}