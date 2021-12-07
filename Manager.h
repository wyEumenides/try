#pragma once
#include <fstream>
#include <vector>
#include <algorithm>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"
class Manager :public Identity
{
public:
	//学生容器
	vector<Student> vStu;
	//教师容器
	vector<Teacher> vTea;
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
public:
	//初始化容器
	void initVector();
	//检测重复
	bool checkRepeat(string id, int type);
	//菜单
	virtual void openMenu();
	//添加账号
	void AddPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约
	void cleanFile();
};

