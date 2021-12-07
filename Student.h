#pragma once
#include "Identity.h"
#include "orderFile.h"
class Student :public Identity
{
public:
	//学生学号
	string m_Id;
	//默认构造
	Student();
	//有参构造
	Student(string id, string name, string pwd);
	//菜单界面
	virtual void openMenu();
	//申请预约
	void applyorder();
	//查看自身预约
	void showMyorder();
	//查看所有预约
	void showAllorder();
	//取消自己的预约
	void cancelOrder();
};

