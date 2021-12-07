#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
#include "globalFile.h"


using namespace std;
//������ʦ����
void teacherMenu(Identity*& teacher);
//����ѧ���ӽ���
void studentMenu(Identity*& student);
//�������Ա�ӽ���
void managerMenu(Identity*& manager);
//��¼���� 
void LoginIn(string fileName, int type);



int main()
{
	int select = 0;
	while (true)
	{
		cout << "====================== ��ӭ�������ǲ��ͻ���ԤԼϵͳ===================== " << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|	    1.ѧ������          |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|	    2.�� ʦ             |\n";
		cout << "\t\t|                               |\n"; 
		cout << "\t\t|	    3.�� �� Ա          |\n";
		cout << "\t\t|                               |\n"; 
		cout << "\t\t|	    0.�� ��             |\n";
		cout << "\t\t|                               |\n"; 
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;
		switch (select)
		{
		case 1: //ѧ����� 
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //��ʦ��� 
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //����Ա��� 
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //�˳�ϵͳ 
			cout << "��ӭ�´�ʹ��" << endl;
			system("cls");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	system("cls");
	return 0;
}

//��ʦ�˵� 
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//��ʦ�˵� 
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;
		string select;
		cin >> select;
		if (select == "1")
		{
			//�鿴����ԤԼ 
			tea->showAllOrder();
		}
		else if (select == "2")
		{
			//���ԤԼ 
			tea->validOrder();
		}
		else if (select == "0")
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "ѡ�����,������ѡ��!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//����ѧ���ӽ���
void studentMenu(Identity*& student)
{
	while (true)
	{
		//�����Ӳ˵�
		student->openMenu();
		//������ָ��תΪ����ָ�� �������������ӿ�
		Student* stu = (Student*)student;
		int select = 0;
		//�����û�ѡ��
		cin >> select;
		switch (select)
		{
		case 1:
			//����˺�
			cout << "����ԤԼ" << endl;
			stu->applyorder();
			break;
		case 2:
			//�鿴�˺�
			cout << "�鿴����ԤԼ" << endl;
			stu->showMyorder();
			break;
		case 3:
			//�鿴����
			cout << "�鿴������ԤԼ" << endl;
			stu->showAllorder();
			break;
		case 4:
			//���ԤԼ
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
			break;
		case 0:
			delete student;//���ٵ���������
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "ѡ�����,������ѡ��!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//�������Ա�ӽ���
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//�����Ӳ˵�
		manager->openMenu();
		//������ָ��תΪ����ָ�� �������������ӿ�
		Manager* man = (Manager*)manager;
		int select = 0;
		//�����û�ѡ��
		cin >> select;
		switch (select)
		{
		case 1:
			//����˺�
			cout << "����˺�" << endl;
			man->AddPerson();
			break;
		case 2:
			//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
			break;
		case 3:
			//�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
			break;
		case 4:
			//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->cleanFile();
			break;
		case 0:
			delete manager;//���ٵ���������
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "ѡ�����,������ѡ��!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//��¼���� 
void LoginIn(string fileName, int type)
{
	//����ָ�� ָ���������
	Identity* person = nullptr;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������!" << endl;
		ifs.close();
		return;
	}
	//׼�������û�������Ϣ
	string id;
	string name;
	string pwd;

	//�ж����
	if (type == 1) //ѧ�����
	{
		cout << "������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "������ְ����:" << endl;
		cin >> id;
	}
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;

	switch (type)
	{
	case 1:
		//ѧ�������֤
	{
		//���ļ��л�ȡ����Ϣ
		string fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����¼�ɹ�" << endl;
				//system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//auto  ���뵽ѧ���Ӳ˵�
				studentMenu(person);
				//delete person;
				return;
			}
			else
			{
				cout << "ѧ����¼ʧ��!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	break;
	case 2:
		//��ʦ�����֤
	{
		//���ļ��л�ȡ����Ϣ
		string fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��¼�ɹ�" << endl;
				system("cls");
				person = new Teacher(id, name, pwd);
				//auto  ���뵽��ʦ�Ӳ˵�
				teacherMenu(person);
				//delete person;
				return;
			}
			else
			{
				cout << "��ʦ��¼ʧ��!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	break;
	case 3:
		//����Ա�����֤
	{
		//���ļ��л�ȡ����Ϣ
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��¼�ɹ�" << endl;
				//system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//auto  ���뵽����Ա�Ӳ˵�
				managerMenu(person);
				//delete person;
				return;
			}
			else
			{
				cout << "����Ա��¼ʧ��!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	break;
	default:
		cout << "���Ͳ�ƥ��!" << endl;
		system("pause");
		system("cls");
		break;
	}
}