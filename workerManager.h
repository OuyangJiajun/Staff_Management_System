#pragma once//��ֹͷ�ļ��ظ�����
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

	void Show_Menu();//��ʾ�˵�

	void exitSystem();//�˳�ϵͳ

	void Add_Emp();//���ְ��

	void save();//�������ݵ��ļ�

	int m_EmpNum;//��¼ְ������
	Worker** m_EmpArray;//ָ��ְ�������ָ��
	bool m_FileIsEmpty;//�ж��ļ��Ƿ����
};