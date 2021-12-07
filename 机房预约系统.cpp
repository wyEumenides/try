#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
#include "globalFile.h"


using namespace std;
//进入老师界面
void teacherMenu(Identity*& teacher);
//进入学生子界面
void studentMenu(Identity*& student);
//进入管理员子界面
void managerMenu(Identity*& manager);
//登录功能 
void LoginIn(string fileName, int type);



int main()
{
	int select = 0;
	while (true)
	{
		cout << "====================== 欢迎来到传智播客机房预约系统===================== " << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|	    1.学生代表          |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|	    2.老 师             |\n";
		cout << "\t\t|                               |\n"; 
		cout << "\t\t|	    3.管 理 员          |\n";
		cout << "\t\t|                               |\n"; 
		cout << "\t\t|	    0.退 出             |\n";
		cout << "\t\t|                               |\n"; 
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1: //学生身份 
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //老师身份 
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //管理员身份 
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //退出系统 
			cout << "欢迎下次使用" << endl;
			system("cls");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	system("cls");
	return 0;
}

//教师菜单 
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//教师菜单 
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;
		string select;
		cin >> select;
		if (select == "1")
		{
			//查看所有预约 
			tea->showAllOrder();
		}
		else if (select == "2")
		{
			//审核预约 
			tea->validOrder();
		}
		else if (select == "0")
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "选择错误,请重新选择!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//进入学生子界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用子菜单
		student->openMenu();
		//将父类指针转为子类指针 调用子类其他接口
		Student* stu = (Student*)student;
		int select = 0;
		//接收用户选择
		cin >> select;
		switch (select)
		{
		case 1:
			//添加账号
			cout << "申请预约" << endl;
			stu->applyorder();
			break;
		case 2:
			//查看账号
			cout << "查看自身预约" << endl;
			stu->showMyorder();
			break;
		case 3:
			//查看机房
			cout << "查看所有人预约" << endl;
			stu->showAllorder();
			break;
		case 4:
			//清空预约
			cout << "取消预约" << endl;
			stu->cancelOrder();
			break;
		case 0:
			delete student;//销毁掉堆区对象
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "选择错误,请重新选择!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//进入管理员子界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用子菜单
		manager->openMenu();
		//将父类指针转为子类指针 调用子类其他接口
		Manager* man = (Manager*)manager;
		int select = 0;
		//接收用户选择
		cin >> select;
		switch (select)
		{
		case 1:
			//添加账号
			cout << "添加账号" << endl;
			man->AddPerson();
			break;
		case 2:
			//查看账号
			cout << "查看账号" << endl;
			man->showPerson();
			break;
		case 3:
			//查看机房
			cout << "查看机房" << endl;
			man->showComputer();
			break;
		case 4:
			//清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
			break;
		case 0:
			delete manager;//销毁掉堆区对象
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "选择错误,请重新选择!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//登录功能 
void LoginIn(string fileName, int type)
{
	//父类指针 指向子类对象
	Identity* person = nullptr;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		ifs.close();
		return;
	}
	//准备接收用户输入信息
	string id;
	string name;
	string pwd;

	//判断身份
	if (type == 1) //学生身份
	{
		cout << "请输入学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入职工号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	switch (type)
	{
	case 1:
		//学生身份验证
	{
		//从文件中获取的信息
		string fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生登录成功" << endl;
				//system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//auto  进入到学生子菜单
				studentMenu(person);
				//delete person;
				return;
			}
			else
			{
				cout << "学生登录失败!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	break;
	case 2:
		//教师身份验证
	{
		//从文件中获取的信息
		string fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师登录成功" << endl;
				system("cls");
				person = new Teacher(id, name, pwd);
				//auto  进入到教师子菜单
				teacherMenu(person);
				//delete person;
				return;
			}
			else
			{
				cout << "教师登录失败!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	break;
	case 3:
		//管理员身份验证
	{
		//从文件中获取的信息
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员登录成功" << endl;
				//system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//auto  进入到管理员子菜单
				managerMenu(person);
				//delete person;
				return;
			}
			else
			{
				cout << "管理员登录失败!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
	break;
	default:
		cout << "类型不匹配!" << endl;
		system("pause");
		system("cls");
		break;
	}
}