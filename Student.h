#pragma once
#include "Identity.h"
#include "orderFile.h"
class Student :public Identity
{
public:
	//ѧ��ѧ��
	string m_Id;
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(string id, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//����ԤԼ
	void applyorder();
	//�鿴����ԤԼ
	void showMyorder();
	//�鿴����ԤԼ
	void showAllorder();
	//ȡ���Լ���ԤԼ
	void cancelOrder();
};

