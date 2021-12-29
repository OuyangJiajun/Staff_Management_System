#pragma once
#include"worker.h"

//普通职工类
class Employee :public Worker
{
public:
	//构造函数
	Employee(int id, string name, int dId);
	void showInfo();
	string getDeptName();
};