#include "Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(string empId, string name, string pwd)
{
	m_EmpId = empId;
	m_Name = name;
	m_Pwd = pwd;
}

void Teacher::openMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl; 
	cout << "\t\t ----------------------------------\n"; 
	cout << "\t\t|                                  |\n"; 
	cout << "\t\t|           1.�鿴����ԤԼ         |\n"; 
	cout << "\t\t|                                  |\n"; 
	cout << "\t\t|           2.���ԤԼ             |\n"; 
	cout << "\t\t|                                  |\n"; 
	cout << "\t\t|           0.ע����¼             |\n"; 
	cout << "\t\t|                                  |\n"; 
	cout << "\t\t ----------------------------------\n"; 
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Teacher::showAllOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "ԤԼ��¼Ϊ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��  ";
		cout << "ԤԼ����: ��" << of.m_orderData[i]["date"] << ' ';
		cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << ' ';
		cout << "ѧ��: " << of.m_orderData[i]["stuId"] << ' ';
		cout << "����: " << of.m_orderData[i]["stuName"] << ' ';
		cout << "������: " << of.m_orderData[i]["roomId"] << ' ';
		string status = "״̬: ";
		//1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "��ԤԼ";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ȡ��ԤԼ";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ:" << endl;
	//�������������±���
	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���ж��Ƿ�������ѧ��
		if (m_EmpId == of.m_orderData[i]["stuId"])
		{
			//ɸѡ״̬
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ����:  ��" << of.m_orderData[i]["date"];
				cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << ' ';
				cout << "������: " << of.m_orderData[i]["roomId"] << ' ';
				string status = "״̬: ";
				//1 �����  2 ��ԤԼ  -1 ԤԼʧ��  0 ȡ��ԤԼ
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "��ԤԼ";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������Ҫ��˵�ԤԼ,0������" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= (int)v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��:" << endl;
				cout << "1��ͨ��" << endl;
				cout << "1����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "������!";
				break;
			}
		}
		cout << "������������������!" << endl;
	}
	system("pause");
	system("cls");
}
