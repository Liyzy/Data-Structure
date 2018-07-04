#include <iostream>
#include <stack>
using namespace std;

int Get_isp(char op)  //栈内运算符优先级
{
	switch (op)
	{
	case'#':return 0;
	case'+':return 3;
	case'-':return 3;
	case'*':return 5;
	case'/':return 5;
	case'(':return 1;
	case')':return 8;
	}
}
int Get_icp(char op)  //栈外运算符优先级
{
	switch (op)
	{
	case'#':return 0;
	case'+':return 2;
	case'-':return 2;
	case'*':return 4;
	case'/':return 4;
	case'(':return 8;
	case')':return 1;
	}
}
int main()
{
	stack<char> OPTR;//操作符栈
	stack<char> OPND;//数据栈
	char c;
	cout << "请输入计算表达式，按#结束:";
	char str[100] = { 0 };
	int counter = 0, i;
	while (cin >> c && c != '#')
	{
		str[counter] = c;
		counter++;
	}
	OPTR.push('#');
	for (i = 0; i <= counter; i++)
	{
		if (str[i] > 47 && str[i] < 59)
			OPND.push(str[i] - 48);
		else
		{
		flag:	if (Get_icp(str[i]) > Get_isp(OPTR.top()))
				{
					OPTR.push(str[i]);
					continue;
				}
				if (Get_icp(str[i]) == Get_isp(OPTR.top()))
				{
					OPTR.pop();
					continue;
				}
				if (Get_icp(str[i]) < Get_isp(OPTR.top()))
				{
					char temp_op;
					temp_op = OPTR.top();
					OPTR.pop();
					char data1, data2, data;
					data1 = OPND.top();
					OPND.pop();
					data2 = OPND.top();
					OPND.pop();
					switch (temp_op)
					{
					case'+':
						data = data1 + data2;
						break;
					case'-':
						data = data2 - data1;
						break;
					case'*':
						data = data1 * data2;
						break;
					case'/':
						data = data2 / data1;
						break;
					}
					OPND.push(data);
					goto flag;
				}
		}
	}

	int result;
	result = OPND.top();
	cout << result;
	system("pause");
}