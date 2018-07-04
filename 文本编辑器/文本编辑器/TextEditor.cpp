
#include "TextEditor.h"


//末尾插入
void TextEditor::AddText(const string &text) {
	system("CLS");
	article.back() += text;
	Print();
}


//在文本插入
bool TextEditor::InsertText(int x, int y, string& text) {
	system("CLS");
	auto p = article.begin();
	for (int i = 1; p != article.end(); p++, i++)
	{
		if (i == x)
		{
			if (y > (*p).size())
			{
				Print();
				cout << "无效操作" << endl;
				return false;
			}

			(*p).insert(y, text);
			Print();
			return true;
		}
	}
	Print();
	cout << "无效操作" << endl;
	return false;
}

//文本式搜索
void TextEditor::findText(string& text) {

	string temp;
	auto p = article.begin();
	for (; p != article.end(); p++)
	{
		temp += *p;
	}

	queue<int> pos;
	size_t tpos = 0;

	while (1)
	{
		tpos = temp.find(text, tpos + text.size());
		cout << tpos << endl;
		if (tpos == std::string::npos)
			break;
		pos.push(tpos);
	}

	if (pos.empty())
		cout << "无匹配" << endl;
	else
	{
		system("CLS");
		//标记输出
		int count = 0;
		for (auto p = article.begin(); p != article.end(); p++)
		{
			for (int j = 0; j < (*p).size(); )
			{
				if (!pos.empty() && count == pos.front())
				{
					while (count - pos.front() < text.size())
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
							FOREGROUND_GREEN);
						cout << (*p).at(j);
						if (j == (*p).size())
						{
							cout << endl;
							j = 0;
							p++;
						}
						j++;
						count++;
					}
					pos.pop();
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
						FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout << (*p).at(j);
					count++;
					j++;
				}
			}
			cout << endl;
		}
	}

}


//文本式删除
bool TextEditor::DeleteText(int x, int y, int length) {

	system("CLS");
	string temp;
	auto p = article.begin();
	for (int i = 1; p != article.end(); i++, p++)
	{
		if (i == x)
		{
			if (y > ((*p).size()))
			{
				Print();
				cout << "操作无效" << endl;
				return false;
			}

			while ((*p).size() - y < length)
			{
				(*p).erase(y, (*p).size() - y);
				length = length - ((*p).size() - y);
				y = 0;
				p++;
			}
			(*p).erase(y, length);
			Print();
			return true;
		}
	}
	Print();
	cout << "无效操作" << endl;
	return false;
}

//文档字符统计
void TextEditor::WordStat(int ptotal = 0, int pletter = 0, int pdigit = 0,
	int pspace = 0, int oquot = 0)const {
	for (auto p = article.begin(); p != article.end(); p++)
	{
		for (int j = 0; j < (*p).size(); j++)
		{
			ptotal++;
			if ((*p).at(j) >= 48 && (*p).at(j) <= 57)
				pdigit++;
			else if (((*p).at(j) >= 65 && (*p).at(j) <= 90) || ((*p).at(j) >= 97 && (*p).at(j) <= 122))
				pletter++;
			else if ((*p).at(j) == 32 || (*p).at(j) == 0 || (*p).at(j) == 9)
				pspace++;
			else if ((*p).at(j) == 33 || (*p).at(j) == 34 || (*p).at(j) == 39 || (*p).at(j) == 44 || (*p).at(j) == 46 || (*p).at(j) == 58 || (*p).at(j) == 59 || (*p).at(j) == 63)
				oquot++;
		}
	}
	cout << "本文";
	cout << "共有字符" << ptotal << "个；" << endl;
	cout << "字母有" << pletter << "个；" << endl;
	cout << "数字有" << pdigit << "个；" << endl;
	cout << "空格有" << pspace << "个；" << endl;
	cout << "标点有" << oquot << "个。" << endl;
}


void TextEditor::Print() {

	for (auto p = article.begin(); p != article.end(); p++)
	{
		cout << *p << endl;
	}
}

ostream& operator << (ostream& out, TextEditor& editor) {
	for (auto p = editor.article.begin(); p != editor.article.end(); p++)
	{
		out << *p << endl;
	}
	return out;
}

istream& operator >> (istream& in, TextEditor& editor) {
	string temp;
	for (auto p = editor.article.begin(); p != editor.article.end(); p++)
	{
		in >> temp;
		temp += "\n";
		*p = temp;
	}
	return in;
}

TextEditor::TextEditor() {
	cout << "请输入要打开的文档的名字" << endl;
	string name;
	cin >> name;
	this->name = name;
}

TextEditor::~TextEditor() {

}


//编辑列表
void TextEditor::Blank() {

	int choose;
	cout << "请选择操作" << endl;
	cout << "1.查找" << endl;
	cout << "2.末尾编辑" << endl;
	cout << "3.文本内编辑" << endl;
	cout << "4.删除" << endl;
	cout << "5.获取文档名字" << endl;
	cout << "6.文档重命名" << endl;
	cout << "7.统计字符" << endl;
	cout << "8.退出" << endl;
	cin >> choose;
	switch (choose)
	{
	case(1):
	{
		cout << "请输入要查找的单词" << endl;
		string write;
		cin >> write;
		findText(write);
	} break;

	case (2):
	{
		string write;
		cin >> write;
		AddText(write);
	}break;

	case (3):
	{
		cout << "请输入插入的位置" << endl;
		int x, y;
		string text;
		cin >> x >> y;
		cout << "请输入字符串" << endl;
		cin >> text;
		InsertText(x, y, text);
	}break;

	case (4):
	{
		cout << "请输入删除位置和删除长度" << endl;
		int x, y, length;
		cin >> x >> y >> length;
		DeleteText(x, y, length);
	}break;

	case (5):
	{
		cout << GetName() << endl;
	}break;

	case (6):
	{
		cout << "请输入文档新名称" << endl;
		string newname;
		cin >> newname;
		SetName(newname);
	}break;

	case (7):
	{
		WordStat();
	}break;

	case (8):
	{
		WriteFile();
		exit(0);
	}break;

	default: break;
	}
}


//进入的第一个页面
void TextEditor::Help() {
	Print();
	cout << "操作请输入E" << endl;
	char ch;
	cin >> ch;
	if (ch == 'E')
	{
		while (1)
		{
			Blank();
		}
	}

	else
	{
		while (1)
		{
			Key();
		}
	}
}



//得到光标当前的位置
void TextEditor::GetCursor() {
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &pBuffer);
	line = pBuffer.dwCursorPosition.Y;
	offset = pBuffer.dwCursorPosition.X;
}

void TextEditor::DisplayCursor() {
	cout << line << "\t";
	cout << offset << endl;
}

//设置光标位置
void TextEditor::SetCursor(int Line, int Offset) {
	CONSOLE_SCREEN_BUFFER_INFO	 csbiInfo;
	HANDLE	 hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = Line;
	csbiInfo.dwCursorPosition.Y = Offset;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
//将光标移动到指定位置
void TextEditor::MoveCursor() {
	CONSOLE_SCREEN_BUFFER_INFO	 csbiInfo;
	HANDLE	 hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = offset;
	csbiInfo.dwCursorPosition.Y = line;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

//键盘式插入
void TextEditor::InsertText(string& text) {
	GetCursor();
	auto p = article.begin();
	for (int i = 0; i < (*p).size(); i++)
	{
		(*p).insert(offset, text);
	}
}

//按键设置
void TextEditor::Key() {
	char key = getchar();

	switch (key)
	{
		//上下右左24-27
	case 24:
	{
		if (line == 0)
			break;
		line -= 1;
		MoveCursor();
	} break;
	case 25:
	{
		if (line == article.size())
			break;
		line += 1;
		MoveCursor();
	}break;
	case 26:
	{
		offset += 1;
		MoveCursor();
	} break;
	case 27:
	{
		if (offset == 0)
			break;
		offset -= 1;
		MoveCursor();

	} break;
	case 32:
	{
		string temp = " ";
		InsertText(line, offset, temp);
		system("cls");
		Print();
		offset += 1; 		//空格
		MoveCursor();
	}break;
	case 9:
	{
		string temp = "    ";
		InsertText(line, offset, temp);
		system("cls");
		Print();
		offset += 4;		//Tab
		MoveCursor();
	}break;
	case 13:
	{
		string temp = "\n";
		InsertText(line, offset, temp);
		system("cls");
		Print();
		line += 1;
		offset = 0;   //Enter
		MoveCursor();
	}break;
	case 'B':
	{
		system("cls");
		Blank();
	}break;
	default:
	{
		/*string k(key);
		InsertText(line, offset, k);*/

	}break;
	}
}



void TextEditor::DisplayKey(int key) {
	switch (key)
	{
	case 72:  //上键
	{
		if (line == 0)
			break;
		line -= 1;
		DisplayCursor();
	} break;
	case 80:  //下键
	{
		if (line == article.size())
			break;
		line += 1;
		DisplayCursor();
	}break;
	case 77:  //右键
	{
		offset += 1;
		DisplayCursor();
	} break;
	case 75:   //左键
	{
		if (offset == 0)
			break;
		offset -= 1;
		DisplayCursor();
	} break;
	default:break;
	}
}

void getfile() {
	ifstream fin;
	fin.open("Test.cpp");
	if (fin.is_open() == false)
	{
		cerr << "找不到文件\n";
		exit(EXIT_FAILURE);
	}
	string oldname;
	string item, text;
	int count = -1;
	while (fin)
	{
		getline(fin, item);
		text += item;
		count++;
	}

	//文件打开并写入
	fin.clear();			//已经到文件尾了要先clear();
	fin.seekg(0);			//重新回到文件头
	item.clear();

	ArrayString TxtArray(count);
	for (int i = 0; i < count; i++)
	{
		getline(fin, item);
		TxtArray.Append(item);
	}
	fin.close();
}

//得到文件名
const string& TextEditor::GetName() const {
	return name;
}

//重命名
void TextEditor::SetName(const string& setname) {
	//重命名	
	rename(name.c_str(), setname.c_str());
	name = setname;
}

//文件写入
void TextEditor::WriteFile() {
	int i, j, k;
	ofstream ofile;               //定义输出文件
	ofile.open(name);     //作为输出文件打开

						  //文件写入
	for (auto p = article.begin(); p != article.end(); p++)
	{
		ofile << *p << endl;
	}
	ofile.close();                //关闭文件
}

//文件打开
void TextEditor::getfile() {

	ifstream fin;
	fin.open(name);
	if (fin.is_open() == false)
	{
		cerr << "找不到文件。\n";
		exit(EXIT_FAILURE);
	}
	string item;
	while (fin)
	{
		getline(fin, item);
		article.push_back(item);
	}
	fin.close();
}