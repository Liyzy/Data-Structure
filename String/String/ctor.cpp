#include<iostream>
#include<string>
using namespace std;
int main()
{
	string one("Lottery winner£¡");
	cout << one << endl;
	string two(20, '$');
	cout << two << endl;
	string three(one);
	cout << three << endl;
	one += "lihui!";
	two = "Sorry! ";
	string four;
	four = two + one;
	cout << four << endl;
	system("pause");
	return 0;
}
