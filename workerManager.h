#pragma once//防止头文件重复包含
#include <iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;


class workerManager
{
public:
	workerManager();
	~workerManager();

	void Show_Menu();//显示菜单

	void exitSystem();//退出系统

	void Add_Emp();//添加职工

	void save();//保存数据到文件

	int m_EmpNum;//记录职工人数
	Worker** m_EmpArray;//指向职工数组的指针
	bool m_FileIsEmpty;//判断文件是否存在
};