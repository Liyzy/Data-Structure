#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void NaiveStrMatching(const string &T, const string &P)
{
	size_t p = 0;
	size_t t = 0;
	size_t i = 0;
	size_t P_len = P.size();
	size_t T_len = T.size();
	size_t pos[100] = { 0 };
	if (T_len < P_len) //ģʽ���ĳ��ȱ�Ŀ�괮��
		cout << "�޶�Ӧ���Ӵ���\n";
flag:while (p < P_len && t < T_len)
{
	if (T[t] == P[p])
	{
		p++;
		t++;
	}
	else
	{
		t = t - p + 1;
		p = 0;
	}
}
	 if (p >= P_len)
	 {
		 pos[i] = t - P_len + 1;
		 i++;
		 p = 0;
		 goto flag;
	 }
	 if (pos[0] != 0)
	 {
		 size_t i = 0;
		 while (pos[i] != 0)
		 {
			// cout << pos[i] << "  ";
			 i++;
		 }
		 cout << pos[i-1];
	 }
	 else
		 cout << "�޶�Ӧ���Ӵ���\n";
}

int main()
{
	string T = "lihuiliweilihuilihui";
	string P = "lihui";
	NaiveStrMatching(T, P);
	system("pause");
}