#pragma once
#include"worker.h"

//�ϰ���
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dId);
	void showInfo();
	string getDeptName();
};
