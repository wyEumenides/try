#pragma once
#include <iostream>
#include <vector>
#include "ComputerRoom.h"
using namespace std;

//�������
class Identity
{
public:
	//�����˵�  ���麯��
	virtual void openMenu() = 0;
	//�û���
	string m_Name;
	//����
	string m_Pwd;
	//������Ϣ����
	vector<ComputerRoom> vCom;
public:
	Identity()
	{
		//��ʼ��������Ϣ
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