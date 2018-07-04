#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <string.h>
#include <time.h>
#define Size 10000

//结构体code记录颜色及其权重
struct colorCode
{
	char* code = new char[8];
	std::string key;
	float wight;
};

//生成图片文件,假设含有500个像素点，即4000位
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

//图片文件输出
char* picturePrint()
{
	char* data = new char[Size * 8];
	std::ifstream fin("data.txt",std::ios_base::binary);
	if (fin.is_open())
		fin.getline(data, Size * 8 + 1);
	return data;
}

//统计得到颜色表，包括颜色种类和权重
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
	//得到不含重复元素的颜色表
	colorType = 1;
	char colorlist[Size][8] = { '\0' };
	for (int k = 0; k < 8; k++)  //第一种颜色一定在颜色表中
		colorlist[0][k] = ori_colorlist[0][k];

	for (int i = 0; i < Size; i++)
	{
		bool flag = 0;
		//在颜色表中查找
		for (int j = 0; j < colorType; j++)
		{
			if (strncmp(colorlist[j], ori_colorlist[i], 8) == 0)  //注意比较函数！！！固定长度！！！
			{
				flag = 1; // 找到一样的则将flag置1
				break;
			}
		}
		if (flag == 1)
			continue;
		else    //没有一样的，添加进颜色表，种类加一
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
	//计算颜色表中每种颜色的权重
	int times[Size] = { 0 };
	for (int i = 0; i < colorType; i++)
	{
		int count = 0;
		for (int j = 0; j < Size; j++)
		{
			if (!strncmp(ori_colorlist[j], colorlist[i], 8)) //相等，则出现次数加一，继续向后查找
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

//打印颜色表
void PrintColorList(const colorCode* colorlist,const int type)
{
	for (int i = 0; i < type; i++)
	{
		for (int j = 0; j < 8; j++)
			std::cout << colorlist[i].code[j];
		std::cout << "\t" << colorlist[i].wight << std::endl;
	}
}



