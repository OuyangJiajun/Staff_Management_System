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

	int get_EmpNum();//ͳ���ļ��е�ְ������

	void init_Emp();//���������Ȱ��ļ��е�ְ�������ڴ�����

	void Show_Emp();//��ʾְ��

	void Del_Emp();//ɾ��ְ��

	int IsExist(int id);//�жϸñ�ŵ�ְ���Ƿ����

	void Mod_Emp();//�޸�ְ��

	void Find_Emp();//����ְ��

	void Sort_Emp();//����ְ��

	void Clean_File();//����ļ�

	int m_EmpNum;//��¼ְ������

	Worker** m_EmpArray;//ָ��ְ�������ָ��

	bool m_FileIsEmpty;//�ж��ļ��Ƿ����
};