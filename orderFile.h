#pragma once
#include <iostream>
#include "globalFile.h"
#include <map>
#include <fstream>

using namespace std;
class orderFile
{
public:
	//记录预约条数
	int m_Size;
	//记录所有预约信息容器
	map<int, map<string, string>> m_orderData;
public:
	orderFile();
public:
	//更新预约记录
	void updateOrder();
};

