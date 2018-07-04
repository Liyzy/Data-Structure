#pragma once
//银行叫号系统
//时间，窗口类型，用户类型，用户到达场景矩阵
//simulater模拟器
//二维数组CustomerEnterMatrix[][3]
//其中3个元素表示三类用户在时间t时的数量
//

#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>
#include <string>
using namespace std;

//用户基类
class User
{
public:
	virtual void gerSeverd() = 0;
};

//用户
class NormalUser : public User
{
private:
	int id;
	bool isWait;
	int ArriveTime;
	int ServeTime;
	string type;
public:
	NormalUser() {}
	NormalUser(int id, int ArriveTime, int ServeTime, string type, bool isWait = false) {
		this->id = id;
		this->isWait = isWait;
		this->ArriveTime = ArriveTime;
		this->ServeTime = ServeTime;
		this->type = type;
	}
	void gerSeverd() {
		cout << "id为" << id << "的" << type << "客户正在办理业务" << endl;
	}
};

class VIPUser : public User
{
private:
	int id;
	bool isWait;
	int ArriveTime;
	int ServeTime;
	string type;
public:
	VIPUser() {}
	VIPUser(int id, int ArriveTime, int ServeTime, string type, bool isWait = false) {
		this->id = id;
		this->isWait = isWait;
		this->ArriveTime = ArriveTime;
		this->ServeTime = ServeTime;
		this->type = type;
	}
	void gerSeverd() {
		cout << "id为" << id << "的" << type << "客户正在办理业务" << endl;
	}
};

class OfficialUser : public User
{
private:
	int id;
	bool isWait;
	int ArriveTime;
	int ServeTime;
	string type;
public:
	OfficialUser() {}
	OfficialUser(int id, int ArriveTime, int ServeTime, string type, bool isWait = false) {
		this->id = id;
		this->isWait = isWait;
		this->ArriveTime = ArriveTime;
		this->ServeTime = ServeTime;
		this->type = type;
	}
	void gerSeverd() {
		cout << "id为" << id << "的" << type << "客户正在办理业务" << endl;
	}
};

//银行窗口基类
class BankWindows
{
public:
	virtual void HandleUser() = 0;
};


//窗口
class NormalWindows : public BankWindows
{
private:
	bool busy;
	string type;
	NormalUser client;
public:
	NormalWindows() {}
	NormalWindows(NormalUser client, bool busy = false) {
		this->busy = busy;
		this->type = "NormalWindows: ";
		this->client = client;
	}
	void HandleUser() {
		cout << type;
		if (busy)
		{
			client.gerSeverd();
		}
		else
			cout << "空闲中" << "\t";
	}
};

class VIPWindows : public BankWindows
{
private:
	bool busy;
	string type;
	User *client;
	int vip;
public:
	VIPWindows() {}
	VIPWindows(VIPUser v_client, bool busy = false) {
		this->busy = busy;
		this->type = "VIPWindows: ";
		this->client = &v_client;
		vip = 1;
	}
	VIPWindows(NormalUser n_client, bool busy = false) {
		this->busy = busy;
		this->type = "VIPWindows: ";
		this->client = &n_client;
		vip = 0;
	}
	void HandleUser() {
		cout << type;
		if (busy)
		{
			client->gerSeverd();
		}
		else
			cout << "空闲中" << "\t";
	}
};

class OfficialWindows : public BankWindows
{
private:
	bool busy;
	string type;
	User *client;
	int off;
public:
	OfficialWindows() {}
	OfficialWindows(OfficialUser o_client, bool busy = false) {
		this->busy = busy;
		this->type = "OfficialWindows: ";
		this->client = &o_client;
		off = 1;
	}
	OfficialWindows(NormalUser n_client, bool busy = false) {
		this->busy = busy;
		this->type = "OfficallWindows: ";
		this->client = &n_client;
		off = 0;
	}
	void HandleUser() {
		cout << type;
		if (busy)
		{
			client->gerSeverd();
		}
		else
			cout << "空闲中" << "\t";
	}
};


//模拟器
class Simulater
{
private:
	int customer[7][100];
	int Time;
	queue<NormalUser> Nuserq;
	queue<VIPUser> Vuserq;
	queue<OfficialUser> Ouserq;

	list<NormalWindows> Nwinl;
	list<VIPWindows> Vwinl;
	list<OfficialWindows> Owinl;
public:
	void customerEnter();
	void simulateCustomerEnter();
	void simulateCallCustomer();
	void simulater();
};



list <int>::iterator operator +(list <int>::iterator op, int i);
