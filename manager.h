#pragma once
#include"worker.h"

//������
class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int dId);
	void showInfo();
	string getDeptName();
};