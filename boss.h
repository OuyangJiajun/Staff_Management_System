#pragma once
#include"worker.h"

//老板类
class Boss :public Worker
{
public:
	//构造函数
	Boss(int id, string name, int dId);
	void showInfo();
	string getDeptName();
};
