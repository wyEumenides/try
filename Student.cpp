#include "Student.h"

Student::Student()
{

}

Student::Student(string id, string name, string pwd)
{
	m_Id = id;
	m_Name = name;
	m_Pwd = pwd;

}

void Student::openMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            1.����ԤԼ           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            2.�鿴�ҵ�ԤԼ       |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            3.�鿴����ԤԼ       |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            4.ȡ��ԤԼ           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            0.ע����¼           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Student::applyorder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl; 
	cout << "5������" << endl; 
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "��������,����������!" << endl;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl; 
	cout << "1������" << endl; 
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval; if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close(); 

	system("pause");
	system("cls");
}

void Student::showMyorder()
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
		if (m_Id == of.m_orderData[i]["stuId"])//�ҵ�����ԤԼ
		{
			cout << "ԤԼ����: ��" << of.m_orderData[i]["date"] << ' ';
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
	}
}

void Student::showAllorder()
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

void Student::cancelOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ��,������ȡ���ļ�¼." << endl;
	//�������������±���
	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���ж��Ƿ�������ѧ��
		if (m_Id == of.m_orderData[i]["stuId"])
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
	cout << "������Ҫȡ���ļ�¼,0������" << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "ԤԼȡ���ɹ�.";
				break;
			}
		}
		cout << "������������������!" << endl;
	}
	system("pause");
	system("cls");
}
