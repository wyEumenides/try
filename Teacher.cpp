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
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl; 
	cout << "\t\t ----------------------------------\n"; 
	cout << "\t\t|                                  |\n"; 
	cout << "\t\t|           1.查看所有预约         |\n"; 
	cout << "\t\t|                                  |\n"; 
	cout << "\t\t|           2.审核预约             |\n"; 
	cout << "\t\t|                                  |\n"; 
	cout << "\t\t|           0.注销登录             |\n"; 
	cout << "\t\t|                                  |\n"; 
	cout << "\t\t ----------------------------------\n"; 
	cout << "请选择您的操作： " << endl;
}

void Teacher::showAllOrder()
{
	orderFile of;
	if (of.m_Size == 0)
	{
		cout << "预约记录为空!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、  ";
		cout << "预约日期: 周" << of.m_orderData[i]["date"] << ' ';
		cout << "时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << ' ';
		cout << "学号: " << of.m_orderData[i]["stuId"] << ' ';
		cout << "姓名: " << of.m_orderData[i]["stuName"] << ' ';
		cout << "机房号: " << of.m_orderData[i]["roomId"] << ' ';
		string status = "状态: ";
		//1 审核中  2 已预约  -1 预约失败  0 取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "已预约";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "取消预约";
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
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约:" << endl;
	//存放最大容器的下标编号
	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//先判断是否是自身学号
		if (m_EmpId == of.m_orderData[i]["stuId"])
		{
			//筛选状态
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "预约日期:  周" << of.m_orderData[i]["date"];
				cout << "时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << ' ';
				cout << "机房号: " << of.m_orderData[i]["roomId"] << ' ';
				string status = "状态: ";
				//1 审核中  2 已预约  -1 预约失败  0 取消预约
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "已预约";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入要审核的预约,0代表返回" << endl;
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
				cout << "请输入审核结果:" << endl;
				cout << "1、通过" << endl;
				cout << "1、不通过" << endl;
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
				cout << "审核完毕!";
				break;
			}
		}
		cout << "输入有误请重新输入!" << endl;
	}
	system("pause");
	system("cls");
}
