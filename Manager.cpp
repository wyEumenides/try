#include "Manager.h"


Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	m_Name = name;
	m_Pwd = pwd;

	//��ʼ������ ���һ�ȡ�ļ��н�ʦ ѧ������Ϣ
	initVector();

}

void Manager::initVector()
{
	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}

	//�������
	vStu.clear();

	//��ȡ�ļ�����Ϣ
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();


	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}

	//�������
	vTea.clear();

	//��ȡ�ļ�����Ϣ
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();
}

bool Manager::checkRepeat(string id, int type)
{
	switch (type)
	{
	case 1:
		//���ѧ��
		for (auto n : vStu)
		{
			if (n.m_Id == id)
			{
				return true;
			}
		}
		break;
	case 2:
		//����ʦ
		for (auto n : vTea)
		{
			if (n.m_EmpId == id)
			{
				return true;
			}
		}
		break;
	default:
		cout << "";
		break;
	}
	return false;
}

void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            1.����˺�           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            2.�鿴�˺�           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            3.�鿴����           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            4.���ԤԼ           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            0.ע����¼           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Manager::AddPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	//д���ļ�����Ϣ
	string fileName;
	string tip;//��ʾid��
	string errorTip;//�����ظ���ʾ
	ofstream ofs;//�ļ���������
	int select = 0;
	cin >> select;

	switch (select)
	{
	case 1:
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��: ";
		errorTip = "ѧ���ظ�!����������.";
		break;
	case 2:
		//��ӵ��ǽ�ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ����: ";
		errorTip = "ְ�����ظ�!����������.";
		break;
	default:
		cout << "�������!" << endl;
		break;
	}
	//׷����д�ļ�
	ofs.open(fileName, ios::out | ios::app);

	//�û�������Ϣ
	string id;
	string name;
	string pwd;

	cout << tip << endl;
	//����ظ�
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "����������: " << endl;
	cin >> name;
	cout << "����������: " << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << ' ' << name << ' ' << pwd << ' ' << endl;
	cout << "��ӳɹ�!" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//��ֹһ�����2����ͬid
	initVector();
}

template <typename S = Student>
void showPerson_print(S s)
{
	cout << s.m_Id << ' ' << s.m_Name << ' ' << s.m_Pwd << endl;
}
template<> void showPerson_print<Teacher>(Teacher t)
{
	cout << t.m_EmpId << ' ' << t.m_Name << ' ' << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "������鿴�˺ŵ�����" << endl;
	cout << "1���鿴ѧ���˺�" << endl;
	cout << "2���鿴��ʦ�˺�" << endl;
	int select = 0;
	cin >> select;
	////�ļ��鿴
	////д���ļ�����Ϣ
	//string fileName;
	//ifstream ifs;//�鿴�ļ�����

	////���ļ��л�ȡ����Ϣ
	//int fId;
	//string fName;
	//string fPwd;
	//switch (select)
	//{
	//case 1://�鿴ѧ���˺�
	//	fileName = STUDENT_FILE;
	//	cout << "��ǰѧ������: " << vStu.size() << endl;
	//	break;
	//case 2://�鿴��ʦ�˺�
	//	fileName = TEACHER_FILE;
	//	cout << "��ǰ��ʦ����: " << vTea.size() << endl;
	//	break;
	//default:
	//	cout << "ѡ�����!";
	//	break;
	//}
	//cout << endl;

	//ifs.open(fileName, ios::in);
	//while (ifs >> fId && ifs >> fName && ifs >> fPwd)
	//{
	//	cout << fId << ' ' << fName << ' ' << fPwd << endl;
	//}

	//�����鿴
	switch (select)
	{
	case 1://�鿴ѧ���˺�
		cout << "��ǰѧ������: " << vStu.size() << endl;
		for_each(vStu.begin(), vStu.end(), showPerson_print<Student>);
		break;
	case 2://�鿴��ʦ�˺�
		cout << "��ǰ��ʦ����: " << vTea.size() << endl;
		for_each(vTea.begin(), vTea.end(), showPerson_print<Teacher>);
		break;
	default:
		cout << "ѡ�����!";
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "������Ϣ����: " << endl;
	for (auto n : vCom)
	{
		cout << "�������" << n.m_ComId << ' ' << "�����������" << n.m_MaxNum << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}
