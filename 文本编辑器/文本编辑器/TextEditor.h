#pragma once
#include <iostream>
#include <list>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <conio.h>

using namespace std;

class TextEditor
{
private:
	list <string> article;   //文章
	int cursor;              //光标位置
	int line;			     //文本行长度
	int offset;			     //偏移量
	int total;
	string name;
public:
	const string& GetName() const;
	void SetName(const string& name);

	void GetCursor();
	void MoveCursor();
	void SetCursor(int Line, int offset);

	void AddText(const string &text);
	void InsertText(string& text);
	bool InsertText(int x, int y, string& text);

	void findText(string& text);

	void DeleteText(int cursor, int length);
	bool DeleteText(int x, int y, int length);

	void WordStat(int ptotal, int pletter, int pdigit,
		int pspace, int oquot)const;

	void DisplayKey(int);
	void DisplayCursor();

	friend ostream& operator << (ostream& out, TextEditor& editor);
	friend istream& operator >> (istream& in, TextEditor& editor);

	void ShortcutKey();
	void WriteFile();
	void getfile();
	void Key();
	void Blank();
	void Print();
	void Help();

	TextEditor();
	~TextEditor();
};






class ArrayString
{
public:
	ArrayString(const int size) {
		maxSize = size;
		arrayString = new string[maxSize];
		curLen = 0;
		position = 0;
	}
	~ArrayString() {
		delete[] arrayString;
	}
	bool Append(const string value) {
		if (curLen >= maxSize)
			return false;
		arrayString[curLen] = value;
		curLen++;
		return true;
	}
	int getMaxSize() {
		return maxSize;
	}
	int getCurSize() {
		return curLen;
	}
	string at(int n) {
		return arrayString[n];
	}
private:
	string *arrayString;
	int maxSize;
	int curLen;
	int position;
};

struct Pos
{
	char name;
	int pos;
};


