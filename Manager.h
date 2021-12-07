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
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
public:
	//��ʼ������
	void initVector();
	//����ظ�
	bool checkRepeat(string id, int type);
	//�˵�
	virtual void openMenu();
	//����˺�
	void AddPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ
	void cleanFile();
};

