#include "System.h"

void Simulater::customerEnter() {
	for (int i = 0; i < Time; i++)
	{
		for (int j = 0; j < 7; j++)
			cout << customer[i][j] << "\t";
		cout << endl;
	}
}

//模拟叫号
void Simulater::simulateCallCustomer() {

	NormalUser nNone(0, 0, 0, "");
	VIPUser vNone(0, 0, 0, "");
	OfficialUser oNone(0, 0, 0, "");

	NormalWindows norwindows(nNone);
	VIPWindows vipwindows(vNone);
	OfficialWindows offwindows(oNone);

	BankWindows *windows[5];
	for (int i = 0; i < 3; i++)
	{
		windows[i] = &norwindows;
	}
	windows[3] = &vipwindows;
	windows[4] = &offwindows;

	//队列进链表
	int j = 0;
	for (; j< 3; j++)
	{
		if (Nuserq.empty())
			break;
		NormalWindows norwindows(Nuserq.front(), true);
		Nwinl.push_back(norwindows);
		Nuserq.pop();
	}
	customer[Time][4] += (-j);

	if (!Vuserq.empty())
	{
		VIPWindows vipwindows(Vuserq.front(), true);
		Vwinl.push_back(vipwindows);
		Vuserq.pop();
		customer[Time][5] += (-1);
	}

	else
	{
		if (!Nuserq.empty())
		{
			VIPWindows vipwindows(Nuserq.front(), true);
			Vwinl.push_back(vipwindows);
			Nuserq.pop();
			customer[Time][4] += (-1);
		}
	}

	if (!Ouserq.empty())
	{
		OfficialWindows offwindows(Ouserq.front(), true);
		Owinl.push_back(offwindows);
		Ouserq.pop();
		customer[Time][6] += (-1);
	}
	else
	{
		if (!Nuserq.empty())
		{
			OfficialWindows offwindows(Nuserq.front(), true);
			Owinl.push_back(offwindows);
			Nuserq.pop();
			customer[Time][4] += (-1);
		}
	}

	//输出
	auto f = Nwinl.begin();
	for (int i = 0; i < 3 && f != Nwinl.end(); i++, f++)
	{
		windows[i] = &(*f);
	}
	if (!Vwinl.empty())
		windows[3] = &(*(Vwinl.begin()));
	if (!Owinl.empty())
		windows[4] = &(*(Owinl.begin()));

	for (int i = 0; i < 5; i++)
	{
		windows[i]->HandleUser();
	}
	Nwinl.clear();
	Vwinl.clear();
	Owinl.clear();
}

//模拟客户进入
void Simulater::simulateCustomerEnter() {

	int NorNum, VipNum, OffNum;

	NorNum = rand() % 6 + 0;
	VipNum = rand() % 2 + 0;
	OffNum = rand() % 2 + 0;
	customer[Time][0] = Time * 2;
	customer[Time][1] = NorNum;
	customer[Time][2] = VipNum;
	customer[Time][3] = OffNum;
	customer[Time][4] = NorNum;
	customer[Time][5] = VipNum;
	customer[Time][6] = OffNum;
	if (Time > 0)
	{
		customer[Time][4] += customer[Time - 1][4];
		customer[Time][5] += customer[Time - 1][5];
		customer[Time][6] += customer[Time - 1][6];
	}

	srand((unsigned)time(NULL));
	for (int k = 0; k < NorNum; k++)
	{
		int id = rand() % 1000 + 1;
		NormalUser n_user(id, 2 * Time, 4, "Noraml", false);
		Nuserq.push(n_user);
	}

	for (int k = 0; k < VipNum; k++)
	{
		int id = rand() % 1000 + 1;
		VIPUser v_user(id, Time, 4, "Vip");
		Vuserq.push(v_user);
	}

	for (int k = 0; k < OffNum; k++)
	{
		int id = rand() % 1000 + 1;
		OfficialUser o_user(id, Time, 4, "Official");
		Ouserq.push(o_user);
	}
}

void Simulater::simulater() {
	int time_end;
	cout << "请输入时间段" << endl;
	cin >> time_end;
	srand(unsigned(time(NULL)));

	//  进入银行的人
	Time = 0;
	for (; Time <= time_end / 2; Time++)
	{
		simulateCustomerEnter();
		if (Time % 2 == 0)
		{
			simulateCallCustomer();
			cout << "\n----------------------------------------------------------" << endl;
		}
		Sleep(200);
	}
}


list <int>::iterator operator +(list <int>::iterator op, int i) {
	int j;
	for (j = 0; j<i; j++)
	{
		op++;
	}
	return op;
}