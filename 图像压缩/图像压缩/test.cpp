#include <iostream>
#include <string>
#include "ColorList.h"
#include "HuffmanTree.h"
#include "Compressor.h"

using namespace std;

int main()
{
	create();

	colorCode* colorlist;
	int colortype = 0;
	char* picture;

	picture = picturePrint();
	colorlist = ColorList(picture, colortype);
	//PrintColorList(colorlist, colortype);

	HuffmanTree Tree(colorlist,colortype);

	colorCode* KeyColorList;
	KeyColorList = Tree.keycolorlist(colortype);

	compress(picture, KeyColorList);
	decompress(KeyColorList, colortype);

	system("pause");
}