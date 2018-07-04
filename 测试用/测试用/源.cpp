#include <stdio.h>
#include <Windows.h>

//最大数
void Max(int a[])
{
	int i;
	int max = a[0];
	for (i = 0; i < 9; i++)
		if (a[i] > max)
			max = a[i];
	printf("最大数是%d,下标是", max);
	for (i = 0; i < 10; i++)
		if (a[i] == max)
			printf("%d ", i);
}

//最小数
void Min(int a[])
{
	int i;
	int min = a[0];
	for (i = 0; i < 9; i++)
		if (a[i] < min)
			min = a[i];
	printf("最小数是%d,下标是", min);
	for (i = 0; i < 10; i++)
		if (a[i] == min)
			printf("%d ", i);
}
int main()
{
	int arr[10];
	int i;
	//输入10个数
	for(i=0;i<10;i++)
		scanf("%d", &arr[i]);
	Max(arr);
	printf("\n");
	Min(arr);
	system("pause");
}

