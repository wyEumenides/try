#pragma once
#include <iostream>
#include "globalFile.h"
#include <map>
#include <fstream>

using namespace std;
class orderFile
{
public:
	//��¼ԤԼ����
	int m_Size;
	//��¼����ԤԼ��Ϣ����
	map<int, map<string, string>> m_orderData;
public:
	orderFile();
public:
	//����ԤԼ��¼
	void updateOrder();
};

