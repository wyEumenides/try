#pragma once
#include "Identity.h"
#include <fstream>
#include "orderFile.h"
class Teacher :public Identity
{
public:
	//ְ����
	string m_EmpId;
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(string empId, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
};

