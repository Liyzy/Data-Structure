#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <string.h>
#include <time.h>
#define Size 10000

//�ṹ��code��¼��ɫ����Ȩ��
struct colorCode
{
	char* code = new char[8];
	std::string key;
	float wight;
};

//����ͼƬ�ļ�,���躬��500�����ص㣬��4000λ
void create()
{
	std::ofstream fout("data.txt",std::ios_base::binary);
	if (fout.is_open())
	{
		srand(time(0));
		for (int i = 0; i < Size * 8; i++)
		{
			int n = rand() % 100 + 0;
			fout << n % 2;
		}
		fout.close();
	}
}

//ͼƬ�ļ����
char* picturePrint()
{
	char* data = new char[Size * 8];
	std::ifstream fin("data.txt",std::ios_base::binary);
	if (fin.is_open())
		fin.getline(data, Size * 8 + 1);
	return data;
}

//ͳ�Ƶõ���ɫ��������ɫ�����Ȩ��
colorCode* ColorList(char* picture, int & colorType)
{
	using namespace std;

	char ori_colorlist[Size][8];
	string s[Size];
	for (int i = 0; i < Size; i++)
		for (int j = i * 8; j < Size * 8; j++)
		{
			ori_colorlist[i][j % 8] = picture[j];
			if (j % 8 == 7)
				break;
		}
	/*	for (int i = 0; i < 500; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << ori_colorlist[i][j];
			cout << endl;
		}
	*/
	//�õ������ظ�Ԫ�ص���ɫ��
	colorType = 1;
	char colorlist[Size][8] = { '\0' };
	for (int k = 0; k < 8; k++)  //��һ����ɫһ������ɫ����
		colorlist[0][k] = ori_colorlist[0][k];

	for (int i = 0; i < Size; i++)
	{
		bool flag = 0;
		//����ɫ���в���
		for (int j = 0; j < colorType; j++)
		{
			if (strncmp(colorlist[j], ori_colorlist[i], 8) == 0)  //ע��ȽϺ����������̶����ȣ�����
			{
				flag = 1; // �ҵ�һ������flag��1
				break;
			}
		}
		if (flag == 1)
			continue;
		else    //û��һ���ģ���ӽ���ɫ�������һ
		{
			for (int k = 0; k < 8; k++)
				colorlist[colorType][k] = ori_colorlist[i][k];
			colorType += 1;
		}
	}
	/*
			for (int i = 0; i<Size && colorlist[i][0] != '\0'; i++)
			{
				for (int j = 0; j < 8; j++)
					cout << colorlist[i][j];
				cout << endl;
			}
	*/
	//������ɫ����ÿ����ɫ��Ȩ��
	int times[Size] = { 0 };
	for (int i = 0; i < colorType; i++)
	{
		int count = 0;
		for (int j = 0; j < Size; j++)
		{
			if (!strncmp(ori_colorlist[j], colorlist[i], 8)) //��ȣ�����ִ�����һ������������
			{
				count++;
				continue;
			}
		}
		times[i] = count;
	}
	/*
		for (int i = 0; i < Size && times[i] != 0; i++)
		{
			cout << times[i] << " ";
			if (i % 10 == 9)
				cout << endl;
		}
	*/
	colorCode* Code = new colorCode[colorType];
	for (int i = 0; i < colorType; i++)
	{
		for (int j = 0; j < 8; j++)
			Code[i].code[j] = colorlist[i][j];
		Code[i].wight = times[i] / (float)Size;
	}
/*
			for (int i = 0; i < colorType ; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << Code[i].code[j];
			cout << "\t" << Code[i].wight << endl;
		}
*/
		return Code;
	}

//��ӡ��ɫ��
void PrintColorList(const colorCode* colorlist,const int type)
{
	for (int i = 0; i < type; i++)
	{
		for (int j = 0; j < 8; j++)
			std::cout << colorlist[i].code[j];
		std::cout << "\t" << colorlist[i].wight << std::endl;
	}
}



