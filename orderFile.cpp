#include "orderFile.h"

//分割: key  value
void Intercept(map<string, string>& m, string str)
{
	string key;
	string value;
	int pos = str.find(":");
	if (pos != -1)
	{
		key = str.substr(0, pos);
		value = str.substr(pos + 1, str.size() - pos - 1);
		m.insert(make_pair(key, value));
	}
}
orderFile::orderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string date;    //日期
	string interval;//时间段
	string stuId;   //学生编号
	string stuName; //学生姓名
	string roomId;  //机房编号
	string status;  //预约状态
	m_Size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;
		Intercept(m, date);
		Intercept(m, interval);
		Intercept(m, stuId);
		Intercept(m, stuName);
		Intercept(m, roomId);
		Intercept(m, status);
		m_orderData.insert(make_pair(m_Size, m));
		m_Size++;
	}
	ifs.close();
}

void orderFile::updateOrder()
{
	if (this->m_Size == 0) 
	{ 
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{ 
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " "; 
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " "; 
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}

	ofs.close();
}
