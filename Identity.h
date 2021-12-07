#pragma once
#include <iostream>
#include <vector>
#include "ComputerRoom.h"
using namespace std;

//抽象基类
class Identity
{
public:
	//操作菜单  纯虚函数
	virtual void openMenu() = 0;
	//用户名
	string m_Name;
	//密码
	string m_Pwd;
	//机房信息容器
	vector<ComputerRoom> vCom;
public:
	Identity()
	{
		//初始化机房信息
		ifstream ifs;
		ifs.open(COMPUTER_FILE, ios::in);
		ComputerRoom com;
		while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
		{
			vCom.push_back(com);
		}
		ifs.close();
	}
};