#include "Manager.h"


Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	m_Name = name;
	m_Pwd = pwd;

	//初始化容器 并且获取文件中教师 学生的信息
	initVector();

}

void Manager::initVector()
{
	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!" << endl;
		return;
	}

	//清空容器
	vStu.clear();

	//读取文件的信息
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();


	//读取教师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!" << endl;
		return;
	}

	//清空容器
	vTea.clear();

	//读取文件的信息
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
		//检测学生
		for (auto n : vStu)
		{
			if (n.m_Id == id)
			{
				return true;
			}
		}
		break;
	case 2:
		//检测教师
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
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            1.添加账号           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            2.查看账号           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            3.查看机房           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            4.清空预约           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|            0.注销登录           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager::AddPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	//写入文件的信息
	string fileName;
	string tip;//提示id号
	string errorTip;//错误重复提示
	ofstream ofs;//文件操作对象
	int select = 0;
	cin >> select;

	switch (select)
	{
	case 1:
		//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号: ";
		errorTip = "学号重复!请重新输入.";
		break;
	case 2:
		//添加的是教师
		fileName = TEACHER_FILE;
		tip = "请输入职工号: ";
		errorTip = "职工号重复!请重新输入.";
		break;
	default:
		cout << "输入错误!" << endl;
		break;
	}
	//追加填写文件
	ofs.open(fileName, ios::out | ios::app);

	//用户输入信息
	string id;
	string name;
	string pwd;

	cout << tip << endl;
	//检测重复
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
	cout << "请输入姓名: " << endl;
	cin >> name;
	cout << "请输入密码: " << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << ' ' << name << ' ' << pwd << ' ' << endl;
	cout << "添加成功!" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//防止一次添加2个相同id
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
	cout << "请输入查看账号的类型" << endl;
	cout << "1、查看学生账号" << endl;
	cout << "2、查看老师账号" << endl;
	int select = 0;
	cin >> select;
	////文件查看
	////写入文件的信息
	//string fileName;
	//ifstream ifs;//查看文件对象

	////从文件中获取的信息
	//int fId;
	//string fName;
	//string fPwd;
	//switch (select)
	//{
	//case 1://查看学生账号
	//	fileName = STUDENT_FILE;
	//	cout << "当前学生数量: " << vStu.size() << endl;
	//	break;
	//case 2://查看教师账号
	//	fileName = TEACHER_FILE;
	//	cout << "当前教师数量: " << vTea.size() << endl;
	//	break;
	//default:
	//	cout << "选择错误!";
	//	break;
	//}
	//cout << endl;

	//ifs.open(fileName, ios::in);
	//while (ifs >> fId && ifs >> fName && ifs >> fPwd)
	//{
	//	cout << fId << ' ' << fName << ' ' << fPwd << endl;
	//}

	//容器查看
	switch (select)
	{
	case 1://查看学生账号
		cout << "当前学生数量: " << vStu.size() << endl;
		for_each(vStu.begin(), vStu.end(), showPerson_print<Student>);
		break;
	case 2://查看教师账号
		cout << "当前教师数量: " << vTea.size() << endl;
		for_each(vTea.begin(), vTea.end(), showPerson_print<Teacher>);
		break;
	default:
		cout << "选择错误!";
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下: " << endl;
	for (auto n : vCom)
	{
		cout << "机房编号" << n.m_ComId << ' ' << "机房最大容量" << n.m_MaxNum << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}
