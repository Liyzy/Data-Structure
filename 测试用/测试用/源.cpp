#include <stdio.h>
#include <Windows.h>

//�����
void Max(int a[])
{
	int i;
	int max = a[0];
	for (i = 0; i < 9; i++)
		if (a[i] > max)
			max = a[i];
	printf("�������%d,�±���", max);
	for (i = 0; i < 10; i++)
		if (a[i] == max)
			printf("%d ", i);
}

//��С��
void Min(int a[])
{
	int i;
	int min = a[0];
	for (i = 0; i < 9; i++)
		if (a[i] < min)
			min = a[i];
	printf("��С����%d,�±���", min);
	for (i = 0; i < 10; i++)
		if (a[i] == min)
			printf("%d ", i);
}
int main()
{
	int arr[10];
	int i;
	//����10����
	for(i=0;i<10;i++)
		scanf("%d", &arr[i]);
	Max(arr);
	printf("\n");
	Min(arr);
	system("pause");
}

