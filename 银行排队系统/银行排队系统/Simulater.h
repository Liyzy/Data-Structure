#pragma once
#include <queue>
#include <list>
#include "BankWindow.h"
#include "User.h"
using namespace std;
class Simulater
{
public:
	Simulater()
	{
		nbw.push_back(NormalBankWindow(1));
		nbw.push_back(NormalBankWindow(2));
		nbw.push_back(NormalBankWindow(3));
		vbw.push_front(VIPBankWindow(4));
		obw.push_front(OfficialBankWindow(5));
	}

	void SimulateCustomEnter()
	{
		int CustomEnterMatrix[7][3] = {
			{3,1,1},
			{5,0,0},
			{0,0,0},
			{5,1,0},
			{0,0,0},
			{0,0,0},
			{0,0,0}
		};


	}
	void SimulateCallCutomer();
	void Simulate();
private:
	queue<NormalUser> NormalUserQueue;
	queue<VIPUser> VIPUserQueue;
	queue<OfficialUser> OfficialUserQueue;
	list<NormalBankWindow> nbw;
	list<VIPBankWindow> vbw;
	list<OfficialBankWindow> obw;
};

