#pragma once
#include "User.h"
#include <iostream>
class BankWindow
{
public:
	BankWindow(int id, bool isBusy = 0, User *client = NULL)
	{
		this->id = id;
		this->isBusy = isBusy;
		this->client = client;
	}
	void HandleUser();
private:
	bool isBusy;
	int id;
	User *client;
};
class NormalBankWindow :public BankWindow
{
public:
	void HandleUser();
	NormalBankWindow(int id, bool isBusy = 0, User *client = NULL):BankWindow(id,isBusy,client){}
};
class OfficialBankWindow :public BankWindow
{
public:
	void HandleUser();
	OfficialBankWindow(int id, bool isBusy = 0, User *client = NULL) :BankWindow(id, isBusy, client) {}
};
class VIPBankWindow :public BankWindow
{
public:
	void HandleUser();
	VIPBankWindow(int id, bool isBusy = 0, User *client = NULL) :BankWindow(id, isBusy, client) {}
};