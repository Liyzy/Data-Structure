//规定 * 代表合取; + 代表析取; ! 表示非。
//规定命题均由大写字母表示。
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//分割析取范式成为基本积
char** m_strtok(char str0[])
{
	char* buf;
	int i = 0;
	int counter = 0;
	while (str0[i] != 0)
	{
		if (str0[i] == '+')
			counter++;
		i++;
	}
	char** p = new char*[counter + 1];
	p[0] = strtok_s(str0, "+", &buf);
	i = 0;
	while (p[i])
	{
		i++;
		p[i] = strtok_s(NULL, "+", &buf);
	}
	return p;
}

//求命题集合
char* gather(char str[])
{
	int i = 0;
	int counter = 0;
	char statement[26] = { 0 };
	while (str[i] != 0)
	{
		bool judge(char c, char state[]);
		if (64 < str[i] && str[i] < 91 && judge(str[i], statement))
		{
			statement[counter] = str[i];
			counter++;
		}
		i++;
	}
	return statement;
}

//判断一个命题是否在命题集合中:在返回false,不在返回True。
bool judge(char c, char state[])
{
	int i = 0;
	while (state[i] != 0)
	{
		if (c == state[i])
			return false;
		i++;
	}
	return true;
}

//添加项
void distribute(char** p, char* state)
{
	int i;
	int j;
	int k;
	string str[100] = { 0 };
	char temp[10] = { 0 };
	string ans[100] = { 0 };
	for (i = 0; p[i] != 0; i++)
	{
		str[i] = p[i];
		ans[i] = p[i];
	}
	for (i = 0; p[i] != "0"; i++)
	{
		int counter = 0;
		for (j = 0; state[j] != 0; j++)
		{
			if (judge(state[j], gather(p[i])))
			{
				temp[counter++] = state[j];
			}
		}
		for (k = 0; k < pow(2, counter); k++)
		{
			for (j = 0; j < counter; j++)
				ans[k] = ans[k] + "*" + temp[j];
		}
	}
	for (i = 0; ans[i] != "0"; i++)
		cout << ans[i] << "+";
}
int main()
{
	char str0[100];
	char str1[100];
	cout << "请输入析取范式:\n";
	cin >> str0;
	for (int i = 0; i < 100; i++)
		str1[i] = str0[i];
	char** p = m_strtok(str0);
	char* statement = gather(str1);
	distribute(p, statement);
	system("pause");
}
