#pragma once
class User
{
public:
	User(int id, int Level, int isWait = 0)
	{
		this->id = id;
		this->isWait = isWait;
		this->Level = Level;
	}
	void GetServed()
	{
		isWait = 0;
	}
    int GetLevel()
	{
		return Level;
	}
private:
	int id;
	int Level;  //优先级别
	int isWait; //等待为1，办理中为0
};

class NormalUser :public User
{
public:
	NormalUser(int id, int isWait = 0):User(id,isWait, 1){}
};
class VIPUser :public User
{
	VIPUser(int id, int isWait = 0) :User(id, isWait, 2){}
};
class OfficialUser :public User
{
	OfficialUser(int id, int isWait=0):User(id,isWait,2){}
};

