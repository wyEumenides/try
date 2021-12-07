#pragma once
#include "Identity.h"
#include <fstream>
#include "orderFile.h"
class Teacher :public Identity
{
public:
	//职工号
	string m_EmpId;
	//默认构造
	Teacher();
	//有参构造
	Teacher(string empId, string name, string pwd);
	//菜单界面
	virtual void openMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
};

