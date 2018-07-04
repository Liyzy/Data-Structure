#pragma once
#include <iostream>
#include <string>
#include "HuffmanTree.h"
#include "ColorList.h"
using namespace std;

void compress(char* picture, colorCode* keylist)
{
	std::ofstream fout("comp_data.txt", std::ios_base::binary);
	if (fout.is_open())
	{
		for (int i = 0; i < Size; i++)
		{
			char* temp = picture;
			for (int j = 0;; j++)
			{
				if (!strncmp(temp, keylist[j].code, 8))
				{
					fout << keylist[j].key;
					break;
				}
			}
			picture = &picture[8];
		}
		fout.close();
	}
}

void decompress(colorCode* keylist, int type)
{
	string comp;
	std::ifstream fin("comp_data.txt", std::ios_base::binary);
	if (fin.is_open())
	{
		while (!fin.eof())
			fin >> comp;
	}

	std::ofstream fout("decom_data.txt", std::ios_base::binary);
	if (fout.is_open())
	{
		string s = "";
	f:for (unsigned int i = 0; i <= comp.length(); i++)
	{
		s = comp.substr(0, i);
		for (int j = 0; j < type; j++)
			if (s == keylist[j].key)
			{
				fout.write(keylist[j].code, 8);
				comp = comp.substr(i);
				goto f;
			}
	}
	  fout.close();
	}
}